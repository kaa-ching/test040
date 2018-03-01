.PHONY:  all clean

COMMONOBJS=main.o Engine.o Factory.o Cylinder.o
BIN=carmotor
CXXFLAGS=-Wall -Wextra -Werror -I. -g -std=c++14 -O2
LDFLAGS=-O2
CC=gcc-5
CXX=g++-5


all: ${BIN}

clean:
	rm -f *.o *~ ${BIN}
	${MAKE} -C test clean

${BIN}: ${COMMONOBJS}
	${CXX} ${COMMONOBJS} -o $@ ${LDFLAGS}

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

test: test/test

test/test:
	${MAKE} -C test test
