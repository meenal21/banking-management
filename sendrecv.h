#ifndef SENDRECV_H
#define SENDRECV_H

#include "commonheader.h"
#include "placeholder.h"

int sendrecv(int cfd, int recvSize, char *recvBuffer,int sendSize, char *sendBuffer){

    ssize_t recvBytes, sendBytes;
    memset(recvBuffer, 0, recvSize);

    // send call
    sendBytes = send(cfd, sendBuffer, sendSize,0);
    if(sendBytes < 0){
        printf(ERROR_WRITING_TO_CLIENT);
        return -1;
    }

    // read back call
    recvBytes = recv(cfd, recvBuffer, recvSize, 0);

    if(recvBytes < 0){
        printf(ERROR_READING_FROM_CLIENT);
        return -1;
    }

    if(recvBytes == 0){
        return -1;
    }
}

#endif