CC=gcc
CFLAGS=-g -Wall
LDFLAGS=

all : inter_segment.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	mv $@ inter_segment

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@ $(FLAGS)

test : all
	./inter_segment

clean :
	rm *.o

clear : clean
	rm ./inter_segment

val : all
	valgrind ./inter_segment
