CC=g++
CFLAGS=-g -Wall
LDFLAGS=

all : main.o io.o freq.o huffman.o btree.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	mv $@ bin/huffman

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@ $(FLAGS)

test : all
	./bin/huffman

clean :
	rm *.o

clear : clean
	rm ./bin/huffman

val : all
	valgrind ./bin/huffman
