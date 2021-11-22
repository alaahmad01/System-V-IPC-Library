#ifndef __UTILS_H_
#define __UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

typedef struct {
    long mtype;
    int mtext[2];
}buffer;

int open_queue (char[], int, int);
void * receive_queue (int mid, void * msg, size_t som, long attr);
void send_queue (int mid, void * msg, size_t som);

#endif