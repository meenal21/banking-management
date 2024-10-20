#ifndef GETCOUNTER_H
#define GETCOUNTER_H

#include "commonheader.h"

int getcounter(char const *file, char const *usertype){
    int fd;
    int id;

    ssize_t bytes_count;
    
    fd = open(file, O_RDWR , 0777);
    if(fd < 0){
        perror("Error opening file");
        return -1;
    }

    bytes_count= read(fd, &id, sizeof(int));
    printf("%d\n",id);
    
    id += 1;
    printf("%d\n",id);
    lseek(fd, 0, SEEK_SET);
    bytes_count= write(fd, &id, sizeof(int));
    if(bytes_count < 0){
        perror("Incrementing counter for file failed");
        close(fd);
        return -1;
    }
    printf("%s ID has been incremented!\n",usertype);
    
    close(fd);
    return id;
}

#endif