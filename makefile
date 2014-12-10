#compilation 
CC=colorgcc
CFLAGS=-lstdc++ -std=c++11 -Wall -c
#linking
LD=colorgcc
LDFLAGS=-lstdc++ -std=c++11 -fno-pretty-templates
#
SRC=$(wildcard *.cpp)
OBJ=$(patsubst *.o,*.cpp, $(SRC))

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

shell: $(OBJ) 
	$(LD) -o $@ $^ $(LDFLAGS)

.PHONY:	clean

clean:
	rm -fv *.o *.gch
