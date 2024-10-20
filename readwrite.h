#ifndef READWRITE_H
#define READWRITE_H
#include "commonheader.h"
#include "placeholder.h"

bool readwrite(int clientConnectionFd, int writeSize, char *writeBuf,int readSize, char *readBuf){

    ssize_t readBytes, writeBytes;
    bzero(readBuf, readSize); 

    writeBytes = write(clientConnectionFd, writeBuf, writeSize);
    if(writeBytes < 0){
        perror(ERROR_WRITING_TO_CLIENT);
        return false;
    }

    readBytes = read(clientConnectionFd, readBuf, readSize);
    if(readBytes < 0){
        perror(ERROR_WRITING_TO_CLIENT);
        return false;
    }
    if(readBytes == 0){
        perror(NO_DATA_RECEIVED);
        return false;
    }

    return true;

}

// First do a write - write to client and then read from client

#endif

