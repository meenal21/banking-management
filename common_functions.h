#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include "commonheader.h"

int get_count(const char *file){
    int fd;
    int id;
    ssize_t bytes_count;
    
    fd = open(file, O_RDONLY, 0777);
    if(fd < 0){
        perror("Error opening file");
        return -1;
    }

    bytes_count= read(fd, &id, sizeof(int));
    return id;
}

#endif