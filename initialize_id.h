#ifndef INITIALIZE_ID_H
#define INITIALIZE_ID_H

#include "commonheader.h"

bool initialize(){

    const char *cid = "cid.txt";
    const char *eid = "eid.txt";
    int fd1, fd2;
    ssize_t bytes_writ;

    if((fd1 = open(cid, O_WRONLY | O_CREAT ,0644)) < 0){
        perror("Error opening CID");
        return false;
    }
    if((fd2 = open(eid, O_WRONLY | O_CREAT ,0644)) < 0){
        perror("Error opening EID");
        return false;
    }

    int counter = 0;

    if((bytes_writ = write(fd1, &counter, sizeof(int))) < bytes_writ){
        perror("Error writing to CID");
        close(fd1);
        close(fd2);
        return false;
    }
    if((bytes_writ = write(fd2, &counter, sizeof(int))) < bytes_writ){
        perror("Error writing to EID");
        close(fd1);
        close(fd2);
        return false;
    }

    printf("Initialised the CID, EID\n");
    close(fd1);
    close(fd2);
    return true;
}

#endif
