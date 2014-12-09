#compilation 
CC=g++
CFLAGS=-std=c++11 -Wall -c
#linking
LD=g++
LDFLAGS=
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
