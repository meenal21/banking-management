#ifndef ADMIN_H
#define ADMIN_H

#include "admin_struct.h"
#include "commonheader.h"
#include "placeholder.h"

int modify_admin(struct Admin admin, off_t offset, int eid){
    int fd;
    ssize_t bytes_writ;
    fd = open(ADMIN_DB, O_RDWR, 0644);
    if(fd < 0){
        perror(OPENING_ADMIN_FAILED);
        return -1;
    }   

    bytes_writ = write(fd, &admin, sizeof(struct Admin));
    if(bytes_writ < 0){
        perror(MODIFY_FAILED);
        return -1;
    }
    return 1;
}