
#include "mq_lib.h"

/*
 * Opens the public message queue
 * */
int open_queue(char path[], int seed, int flag) {

    int key,mid;

    if ((key = ftok(path, seed)) == -1) {
        perror("open_queue ftok");
        exit(-1);
    }

    if ((mid = msgget(key, flag)) == -1) {
        perror("open_queue msgget");
        exit(-2);
    }

    return mid;

}

/*
 * Receives from the public message queue
 * */
void * receive_queue (int mid, void * msg, size_t som, long attr) {

    if (msgrcv(mid, msg, som, attr, 0) == -1) {
        perror("receive_queue msgrcv");
        exit(-1);
    }

    return msg;
}

/*
 * Sends to the public message queue
 * */
void send_queue (int mid, void * msg, size_t som) {

    if (msgsnd(mid, msg, som, 0) == -1) {
        perror("send_queue msgsnd");
        exit(-1);
    }

}

