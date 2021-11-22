

#include "mq_lib.h"

#define TYPE 1

int main (void) {

    switch (fork()) {
        case -1:
            perror("main fork");
            exit(-1);
        case 0:
            printf("hello child\n");
            fflush(stdout);
            buffer buffer2;
            int mid = open_queue(".",1,IPC_CREAT|0666);
            buffer2 = *(buffer *) receive_queue(mid,(void *)&buffer2, sizeof(buffer2.mtext),TYPE);
            printf("received buffer2 %d %d\n",buffer2.mtext[0],buffer2.mtext[1]);
            fflush(stdout);
            break;
        default:
            printf("hello parent\n");
            fflush(stdout);
            int mid2;
            buffer buffer1;
            buffer1.mtype = TYPE;
            buffer1.mtext[0] = 0;
            buffer1.mtext[1] = 1;
            mid2 = open_queue(".", 1, IPC_CREAT | 0666);
            send_queue(mid2,(void *)&buffer1, sizeof(buffer1.mtext));
            printf("sending buffer1\n");
            fflush(stdout);
            sleep(1);
    }



}