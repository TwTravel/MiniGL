#ifndef _tgl_specbuf_h_
#define _tgl_specbuf_h_

#include "zgl.h"
/* Max # of specular light pow buffers */


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

 


//GLSpecBuf *specbuf_get_buffer(GLContext *c, const int shininess_i, 
//                              const float shininess);
//void specbuf_cleanup(GLContext *c); /* free all memory used */

#endif /* _tgl_specbuf_h_ */