#include "sem_lib.h"


struct sembuf acquire = {0, -1, SEM_UNDO}, release = {0, 1, SEM_UNDO};


/*
 * Opens the public semaphore
 * */
int open_sem(int seed, int nsems, int flag, unsigned short arr[]) {

    int key, semid;

    /*
     * Get the key to open the semaphore
     * */
    if ((key = ftok(".", seed)) == -1) {
        perror("open_sem ftok");
        exit(-1);
    }
    if ((semid = semget(key, nsems, flag)) == -1) {
        perror("open_sem semget");
        exit(-2);
    }

    if (flag == (IPC_CREAT | 0666)) {

        if (arr != NULL) {
            union semun arg;
            arg.array = arr;

            if (semctl(semid, 0, SETALL, arg) == -1) {
                perror("open_sem semctl");
                exit(-3);
            }
        }
        else
            fprintf(stderr, "arr must not be NULL while specifying flag = IPC_CREAT | 0666");
    }

    return semid;
}

/*
 * Acquires the semaphore at index
 * */
void acquire_sem(int semid, int index) {
    acquire.sem_num = index;
    if (semop(semid, &acquire, 1) == -1) {
        perror("acquire_sem semop");
        exit(-1);
    }
}

/*
 * Releases the semaphore at index
 * */
void release_sem(int semid, int index) {
    release.sem_num = index;
    if (semop(semid, &release, 1) == -1) {
        perror("release_sem semop");
        exit(-1);
    }
}

