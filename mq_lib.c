
#include "mq_lib.h"

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

void * receive_queue (int mid, void * msg, size_t som, int attr) {

    if (msgrcv(mid, &msg, som, attr, 0) == -1) {
        perror("receive_queue msgrcv");
        exit(-1);
    }

    return msg;
}

void send_queue (int mid, void * msg, size_t som) {

    if (msgsnd(mid, &msg, som, 0) == -1) {
        perror("send_queue msgsnd");
        exit(-1);
    }

}

