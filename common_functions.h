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


int random_number(const char *file){
    int count;
    count = get_count(file);
    int min =1;
    int randomNum ;
    randomNum= (rand() % (count - min + 1)) + min;
    return randomNum;
}

int check_password(char *pass){
    printf("%s\n", pass);
    char message[BUFFER_SIZE];
    
    printf("Enter Password: ");
    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;
    pass[strcspn(pass, "\n")] = 0;

    int cmp;
    cmp = strcmp(message, pass);
    printf("%d\n", cmp);
    printf("%s\n", message);

    if(cmp != 0){
        printf(INVALID_CREDENTIALS);
        return -1;
    }

    return 1;
}


#endif