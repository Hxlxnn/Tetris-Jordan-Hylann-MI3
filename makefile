OBJS	= fonction.o main.o

SOURCE	= fonction.c main.c

HEADER	= header.h

OUT	= main

CC	 = gcc

FLAGS	 = -g -c -Wall

LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


fonction.o: fonction.c
	$(CC) $(FLAGS) fonction.c 


main.o: main.c
	$(CC) $(FLAGS) main.c 



clean:
	rm -f $(OBJS) $(OUT)
