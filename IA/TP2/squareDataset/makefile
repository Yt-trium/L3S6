CC=g++
CFLAGS=-g -Wall
LDFLAGS=

all : squareDataset.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	mv $@ squareDataset

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@ $(FLAGS)

test : all
	./squareDataset

clean :
	rm *.o

clear : clean
	rm ./squareDataset

val : all
	valgrind ./squareDataset
