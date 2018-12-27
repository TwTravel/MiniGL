#ifndef _tgl_specbuf_h_
#define _tgl_specbuf_h_

#include "zgl.h"
/* Max # of specular light pow buffers */
#define MAX_SPECULAR_BUFFERS 8
/* # of entries in specular buffer */
#define SPECULAR_BUFFER_SIZE 1024
/* specular buffer granularity */
#define SPECULAR_BUFFER_RESOLUTION 1024

/*
typedef struct GLSpecBuf {
  int shininess_i;
  int last_used;
  float buf[SPECULAR_BUFFER_SIZE+1];
  struct GLSpecBuf *next;
} GLSpecBuf;

*/

 
#include <math.h>
#include <stdlib.h>

 void inline calc_buf(GLSpecBuf *buf, const float shininess)
{
  int i;
  float val, inc;
  val = 0.0f;
  inc = 1.0f/SPECULAR_BUFFER_SIZE;
  for (i = 0; i <= SPECULAR_BUFFER_SIZE; i++) {
    buf->buf[i] = pow(val, shininess);
    val += inc;
  }
}

inline  GLSpecBuf *  specbuf_get_buffer(GLContext *c, const int shininess_i, 
                   const float shininess)
{
  GLSpecBuf *found, *oldest;
  found = oldest = c->specbuf_first;
  while (found && found->shininess_i != shininess_i) {
    if (found->last_used < oldest->last_used) {
      oldest = found;
    }
    found = found->next; 
  }
  if (found) { /* hey, found one! */
    found->last_used = c->specbuf_used_counter++;
    return found;
  }
  if (oldest == NULL || c->specbuf_num_buffers < MAX_SPECULAR_BUFFERS) {
    /* create new buffer */
    GLSpecBuf *buf = (GLSpecBuf *)gl_malloc(sizeof(GLSpecBuf));
    if (!buf) 
		exit(0);
		//gl_fatal_error("could not allocate specular buffer");
    c->specbuf_num_buffers++;
    buf->next = c->specbuf_first;
    c->specbuf_first = buf;
    buf->last_used = c->specbuf_used_counter++;
    buf->shininess_i = shininess_i;
    calc_buf(buf, shininess);
    return buf;     
  }
  /* overwrite the lru buffer */
  /*tgl_trace("overwriting spec buffer :(\n");*/
  oldest->shininess_i = shininess_i;
  oldest->last_used = c->specbuf_used_counter++;
  calc_buf(oldest, shininess);
  return oldest;
}


//GLSpecBuf *specbuf_get_buffer(GLContext *c, const int shininess_i, 
//                              const float shininess);
//void specbuf_cleanup(GLContext *c); /* free all memory used */

#endif /* _tgl_specbuf_h_ */