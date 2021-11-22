CC=gcc

all: mq_lib.o main.o
	$(CC) mq_lib.o main.o -o main

%.o: %.c
	$(CC) -c $< -g -o $@

clean:
	rm -f main.o mq_lib.o main
	ipcrm --all=msg
