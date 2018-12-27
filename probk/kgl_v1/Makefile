CXX = g++ -g -pg  -fprofile-arcs -ftest-coverage -fpermissive
CFLAGS = -fPIC -fpermissive
MYFLAGS = -DTIME_INFO -Wno-deprecated  -fpermissive
INC = -I ./include -I  ./TyGL 

CXXFLAGS = $(INC)
LDFLAGS =

SOURCES = \
    ./TyGL/api.cpp \
    ./3DS.cpp \
    ./TyGL/kh_project.cpp \
    ./TyGL/clip.cpp \
    ./TyGL/image_util.cpp \
    ./TyGL/init.cpp \
    ./TyGL/glx.cpp \
    ./main.cpp 

OBJ = \
    ./TyGL/api.o \
    ./3DS.o \
    ./TyGL/kh_project.o \
    ./TyGL/clip.o \
    ./TyGL/image_util.o \
    ./TyGL/init.o \
    ./TyGL/glx.o \
    ./main.o 

Decoder: $(OBJ) main.o
	$(CXX) $(CXXFLAGS) -o Draw3D $(OBJ) $(LDFLAGS)  -ldl -lpthread

clean:
	-rm Draw3D *.gc*  TyGL/*.gc* TyGL/*.o 

# $(OBJ)
