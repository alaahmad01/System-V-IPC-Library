#ifndef __SHMEM_LIB_H
#define __SHMEM_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>



int open_shmem (int seed, size_t size, int flag);
void * attach_shmem (int shmid);


#endif