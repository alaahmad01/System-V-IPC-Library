

#include "mq_lib.h"



int main (void) {

    buffer buffer1;
    buffer buffer2;
    int arr[2] = {0,1};

    buffer1.mtype = 1;
    buffer1.mtext[0] = 0;
    buffer1.mtext[1] = 1;

    int mid = open_queue(".",1,IPC_CREAT|0666);
    send_queue(mid,(void *)&buffer1, sizeof(buffer1.mtext));
    printf("sending buffer1\n");
    buffer2 = *(buffer *) receive_queue(mid,(void *)&buffer2, sizeof(buffer2.mtext),0);
    printf("received buffer2 %d %d\n",buffer2.mtext[0],buffer2.mtext[1]);


}