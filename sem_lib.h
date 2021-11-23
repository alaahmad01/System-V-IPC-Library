#ifndef __SEM_LIB_H
#define __SEM_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <assert.h>


union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

extern struct sembuf acquire;
extern struct sembuf release;


int open_sem (int seed, int nsems, int flag, unsigned short arr[]);
void acquire_sem (int semid, int index);
void release_sem (int semid, int index);

#endif