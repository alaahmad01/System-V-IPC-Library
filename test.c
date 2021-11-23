

#include "mq_lib.h"
#include "shmem_lib.h"

#define SEED 'A'
#define SIZE 1024

int main (void) {

    switch (fork()) {
        case -1:
            perror("main fork");
            exit(-1);
        case 0:
            printf("hello child\n");
            fflush(stdout);

            int shm = open_shmem(SEED, SIZE, 0);
            int *shmp = (int *) attach_shmem(shm);

            sleep(1);
            printf("Received %d %d",shmp[0],shmp[1]);
            fflush(stdout);
            break;
        default:
            printf("hello parent\n");
            fflush(stdout);
            int shmid = open_shmem(SEED, SIZE, IPC_CREAT | 0666);
            int * shmptr = (int *) attach_shmem(shmid);
            shmptr[0] = 0;
            shmptr [1] = 1;
            sleep(2);
    }



}