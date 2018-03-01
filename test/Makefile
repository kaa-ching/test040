.PHONY:  all clean

COMMONOBJS=
CXXFLAGS=-Wall -Wextra -I.. -g -std=c++14 -Iinclude
LDFLAGS=-pthread libgmock.a
CC=gcc-5
CXX=g++-5

all: test

clean:
	rm -f *.o *~ test

test: main.o testEngine.o Engine.o Cylinder.o
	${CXX} ${COMMONOBJS} $^ -o $@ ${LDFLAGS}

#-----------------------------

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

%.o: ../%.cpp ../%.h
	${CXX} ${CXXFLAGS} -c $< -o $@

%.o: %.c
	${CC} ${CXXFLAGS} -c $< -o $@
