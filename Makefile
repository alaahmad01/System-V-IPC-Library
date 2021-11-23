CC=gcc

all: lib/mq_lib.o lib/shmem_lib.o lib/sem_lib.o lib/fork_lib.o test.o
	$(CC) lib/mq_lib.o lib/shmem_lib.o lib/sem_lib.o lib/fork_lib.o test.o -o main

%.o: %.c
	$(CC) -c $< -g -o $@

clean:
	rm -f test.o lib/mq_lib.o lib/shmem_lib.o lib/sem_lib.o lib/fork_lib.o main
	ipcrm --all=msg
	ipcrm --all=shm
	ipcrm --all=sem
