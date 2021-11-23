#ifndef __MQ_LIB_H
#define __MQ_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int open_queue (char[], int, int);
void * receive_queue (int mid, void * msg, size_t som, long attr);
void send_queue (int mid, void * msg, size_t som);

#endif