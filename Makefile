CC=g++
CFLAGS=-Wall -g -std=c++11
TARGERT=StdDraw
OBJS=StdDraw.o
CPP=StdDraw.cpp
LIBS=-lglut -lGLU -lGL

#all:$(TARGERT)

$(TARGERT): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGERT) $(OBJS) $(LIBS)

StdDraw.o:StdDraw.cpp StdDraw.h
	$(CC) $(CFLAGS) -c StdDraw.cpp

clean:
	rm -f $(OBJS) $(TARGERT)
