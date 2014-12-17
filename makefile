#compilation 
CC=colorgcc
CFLAGS=-lstdc++ -std=c++11 -Wall -c
#linking
LD=colorgcc
LDFLAGS=-lstdc++ -std=c++11 -fno-pretty-templates
#
SRC=$(wildcard ./src/*.cpp)
OBJ=$(patsubst ./bin/*.o,./src/*.cpp, $(SRC))

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

shell: $(OBJ) 
	$(LD) -o ./bin/$@ $^ $(LDFLAGS)

.PHONY:	clean

clean:
	rm -fv *.o *.gch
