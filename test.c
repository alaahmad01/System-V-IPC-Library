

#include "local.h"

int main (void) {


    switch (fork()) {
        case -1:
            perror("main fork");
            exit(-1);
        case 0:
            printf("hello child\n");
            fflush(stdout);

            sleep(1);

            int sem = open_sem(SEED,2,0,NULL);
            int shm = open_shmem(SEED,SIZE,0);
            int * shmp = (int *) attach_shmem(shm);

            acquire_sem(sem,0);
            printf("Received %d\n", shmp[0]);
            release_sem(sem,0);

            acquire_sem(sem,1);
            printf("Received %d\n", shmp[1]);
            release_sem(sem,1);

            break;
        default:
            printf("hello parent\n");
            fflush(stdout);

            unsigned short arr[2] = {1,1};
            int semid = open_sem(SEED,2,IPC_CREAT|0666, arr);

            int shmid = open_shmem(SEED,SIZE,IPC_CREAT|0666);
            int * shmptr = (int *) attach_shmem(shmid);

            acquire_sem(semid,0);
            shmptr[0] = 0;
            release_sem(semid,0);

            acquire_sem(semid,1);
            shmptr[0] = 1;
            release_sem(semid,1);

            sleep(1);
    }



}