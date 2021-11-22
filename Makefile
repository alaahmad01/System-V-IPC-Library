CC=gcc

all: mq_lib.o test.o
	$(CC) mq_lib.o test.o -o main

%.o: %.c
	$(CC) -c $< -g -o $@

clean:
	rm -f test.o mq_lib.o main
	ipcrm --all=msg
