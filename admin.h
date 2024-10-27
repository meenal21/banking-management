#ifndef ADMIN_H
#define ADMIN_H

#include "admin_struct.h"
#include "commonheader.h"
#include "placeholder.h"
#include "common_functions.h"

int modify_admin(struct Admin admin){
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

int create_admin(){
    struct Admin admin;
    admin.loggedin = false;
    strcpy(admin.password, "admin_pass");
    int fd;

    fd = open(ADMIN_DB, O_RDWR | O_CREAT | O_APPEND, 0777); // Use O_APPEND to append to the file
    if (fd < 0) {
        perror(OPENING_ADMIN_FAILED);
        return -1;
    }
    ssize_t bytes_writ;
    bytes_writ = write(fd, &admin, sizeof(struct Admin));
    if (bytes_writ < 0) {
        perror(ADMIN_CREATION_FAILED);
        close(fd);
        return -1;
    }

    return 1;
}

int read_admin(struct Admin *admin) {
    int fd;
    struct Admin temp;
    ssize_t bytes_read;

    if ((fd = open(ADMIN_DB, O_RDONLY)) < 0) {
        perror(OPENING_ADMIN_FAILED);
        return -1; // Return an empty struct
    }

    while ((bytes_read = read(fd, &temp, sizeof(struct Admin))) > 0){
            close(fd);
            *admin = temp;
            return 1; 
    }

    if (bytes_read < 0) {
        perror(UNABLE_TO_READ_ADMIN);
    }

    close(fd);
    return -1; // Return an empty struct if not found
}

int login_admin(int sfd){
    struct Admin admin;
    off_t offset;
    
    //printf("Came inside login\n");
    offset = read_admin(&admin);
    if(offset == -1){
            perror(USER_NOT_FOUND);
            return -1;
    }

    // check if logged in
    if(admin.loggedin != false){
        //write_client(sfd, sizeof(USER_ALREADY_LOGGED_IN), USER_ALREADY_LOGGED_IN);
        printf(USER_ALREADY_LOGGED_IN);
        return -1;
    }

    int check;
    check = check_password(sfd,admin.password);

    if(check == -1){
        //write_client(sfd, sizeof(INVALID_CREDENTIALS), INVALID_CREDENTIALS);
        printf(INVALID_CREDENTIALS);
        return -1;
    }

    admin.loggedin = true;
    if(modify_admin(admin) == -1){
        //write_client(sfd, sizeof(UNABLE_TO_LOGIN), UNABLE_TO_LOGIN);
        printf(UNABLE_TO_LOGIN);
        return -1;
    }

    //write_client(sfd, sizeof(SUCCESSFULLY_LOGGED_IN), SUCCESSFULLY_LOGGED_IN);
    printf(SUCCESSFULLY_LOGGED_IN);
    return 1;

}


int logout_admin(int sfd){
    struct Admin admin;
    off_t offset;
    
    
    offset = read_admin(&admin);
    if(offset == -1){
            //write_client(sfd, sizeof(USER_NOT_FOUND), USER_NOT_FOUND);
            printf(USER_NOT_FOUND);
            return -1;
    }

    // check if logged in

    admin.loggedin = false;
    if(modify_admin(admin) == -1){
        //write_client(sfd, sizeof(UNABLE_TO_LOGOUT), UNABLE_TO_LOGOUT);
        printf(UNABLE_TO_LOGOUT);
        return -1;
    }

    //write_client(sfd, sizeof(SUCCESSFULLY_LOGGED_OUT), SUCCESSFULLY_LOGGED_OUT);
    printf(SUCCESSFULLY_LOGGED_OUT);
    return 1;

}

#endif