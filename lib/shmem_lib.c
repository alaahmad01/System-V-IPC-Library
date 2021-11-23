
#include "shmem_lib.h"

/*
 * Opens the public shared memory
 * */
int open_shmem (int seed, size_t size, int flag) {

    int key,shmid;

    if ((key = ftok(".", seed)) == -1) {
        perror("open_shmem ftok");
        exit(-1);
    }

    if ((shmid = shmget(key,size, flag)) == -1) {
        perror("open_shmem shmget");
        exit(-2);
    }
    return shmid;

}

/*
 * Attaches the public shared memory
 * */
void * attach_shmem (int shmid)
{
    void * shmptr;
    if ((shmptr = shmat(shmid,0,0)) == (int *) -1) {
        perror("attach_shmem shamt");
        exit(-1);
    }
    return shmptr;
}

