#ifndef INITIALIZE_ID_H
#define INITIALIZE_ID_H

#include "commonheader.h"
#include "placeholder.h"

bool initialize(){

    const char *cid = CUSTOMER_COUNTER;
    const char *eid = EMPLOYEE_COUNTER;
    const char *tid = TRANSACTION_COUNTER;
    const char *fid = FEEDBACK_COUNTER;
    const char *lid = LOAN_COUNTER;
    const char *mid = MANAGER_COUNTER;

    int fd1, fd2, fd3, fd4, fd5, fd6;
    ssize_t bytes_writ;

    if((fd1 = open(cid, O_WRONLY | O_CREAT ,0644)) < 0){
        perror("Error opening CID");
        return false;
    }
    if((fd2 = open(eid, O_WRONLY | O_CREAT ,0644)) < 0){
        perror("Error opening EID");
        return false;
    }

    if((fd3 = open(tid, O_WRONLY | O_CREAT ,0644)) < 0){
        perror("Error opening TID");
        return false;
    }

    if((fd4 = open(fid, O_WRONLY | O_CREAT ,0644)) < 0){
        perror("Error opening FID");
        return false;
    }

    if((fd5 = open(lid, O_WRONLY | O_CREAT ,0644)) < 0){
        perror("Error opening LID");
        return false;
    }
    int counter = 0;

    if((bytes_writ = write(fd1, &counter, sizeof(int))) < bytes_writ){
        perror("Error writing to CID");
        close(fd1);
        close(fd2);
        close(fd3);
        close(fd4);
        close(fd5);
        return false;
    }
    if((bytes_writ = write(fd2, &counter, sizeof(int))) < bytes_writ){
        perror("Error writing to EID");
        close(fd1);
        close(fd2);
        close(fd3);
        close(fd4);
        close(fd5);
        return false;
    }

    if((bytes_writ = write(fd3,  &counter, sizeof(int))) < bytes_writ){
        perror("Error writing to TID");
        close(fd1);
        close(fd2);
        close(fd3);
        close(fd4);
        close(fd5);
        return false;
    }

    if((bytes_writ = write(fd4,  &counter, sizeof(int))) < bytes_writ){
        perror("Error writing to FID");
        close(fd1);
        close(fd2);
        close(fd3);
        close(fd4);
        close(fd5);
        return false;
    }

    if((bytes_writ = write(fd5,  &counter, sizeof(int))) < bytes_writ){
        perror("Error writing to LID");
        close(fd1);
        close(fd2);
        close(fd3);
        close(fd4);
        close(fd5);
        return false;
    }

    if((fd6 = open(mid, O_WRONLY | O_CREAT ,0644)) < 0){
        perror("Error opening MID");
        return false;
    }

    if((bytes_writ = write(fd6,  &counter, sizeof(int))) < bytes_writ){
        perror("Error writing to MID");
        close(fd6);
        return false;
    }

    printf("Initialised the CID, EID, TID, FID, LID\n");
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);
    close(fd6);
    return true;
}

#endif
