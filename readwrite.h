#ifndef READWRITE_H
#define READWRITE_H
#include "commonheader.h"
#include "placeholder.h"

bool readwrite(int clientConnectionFd, int writeSize, char *writeBuf,int readSize, char *readBuf){

    ssize_t readBytes, writeBytes;
    bzero(readBuf, readSize); 
    printf("Inside Read write - write -------\n");
    printf("%s\n", writeBuf);

    writeBytes = write(clientConnectionFd, writeBuf, writeSize);
    if(writeBytes < 0){
        perror(ERROR_WRITING_TO_CLIENT);
        return false;
    }
    
    printf("Inside ReadWrite --- read -----\n");
    readBytes = read(clientConnectionFd, readBuf, readSize);
    if(readBytes < 0){
        perror(ERROR_WRITING_TO_CLIENT);
        return false;
    }
    if(readBytes == 0){
        perror(NO_DATA_RECEIVED);
        return false;
    }

    printf("%s\n", readBuf);

    return true;

}

bool write_client(int clientConnectionFd, int writeSize, char *writeBuf){

    ssize_t writeBytes;

    writeBytes = write(clientConnectionFd, writeBuf, writeSize);
    if(writeBytes < 0){
        perror(ERROR_WRITING_TO_CLIENT);
        return false;
    }

    return true;

}


// First do a write - write to client and then read from client

#endif

