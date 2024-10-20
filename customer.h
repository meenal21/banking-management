#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "./commonheader.h"
#include "./customer_struct.h"
#include "./placeholder.h"
#include "./getcounter.h"

int create_customer(){
    int fd;
    int id;
    struct Customer cust;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    char const *filename = "customer.txt";
    
    //ssize_t bytes_read;
    ssize_t bytes_writ;
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if(fd < 0){
        perror("Error opening file");
        return -1;
    }

    
    id = getcounter("cid.txt", "Customer");
    if(id < 0){
        perror("Customer Id couldn't be added");
    }
    printf("%d \n", id);

    printf("Enter customer details: \n");
    
    printf("Name: ");
    fgets(message, BUFFER_SIZE, stdin);
    strcpy(cust.name,message);

    printf("Email: ");
    fgets(message, BUFFER_SIZE, stdin);
    strcpy(cust.emailid,message);
    
    printf("DOB: ");
	fgets(message, BUFFER_SIZE, stdin);
    strcpy(cust.dob,message);
    
    printf("Ph. Number: ");
	fgets(message, BUFFER_SIZE, stdin);
    strcpy(cust.number,message);

    printf("Address: ");
	fgets(message, BUFFER_SIZE, stdin);
    strcpy(cust.address,message);

    printf("Document Type: ");
	fgets(message, BUFFER_SIZE, stdin);
    strcpy(cust.iddoc,message);

    printf("ID Number: ");
	fgets(message, BUFFER_SIZE, stdin);
    strcpy(cust.idnumber,message);

    printf("Balance: ");
	fgets(message, BUFFER_SIZE, stdin);
    cust.balance = atoi(message);


    //printf("%d\n",id);
    char pass[50];
    snprintf(pass, sizeof(pass), "cid@%s", cust.emailid); 
    strcpy(cust.password,pass);
    cust.cid = id;
    
    cust.active = true;
    cust.loggedin = false;
    
    bytes_writ = write(fd,&cust,sizeof(struct Customer));
    if(bytes_writ < 0){
        perror("Creating customer failed");
        close(fd);
        return -1;
    }
    printf("Customer has been created!");
    close(fd);

    return id;
}

off_t read_customer(struct Customer * cust, int cid) {
    int fd;
    off_t offset;
    struct Customer temp_cust;
    ssize_t bytes_read;

    if ((fd = open("customer.txt", O_RDONLY)) < 0) {
        perror("Error opening the file");
        return -1; // Return an empty struct
    }

    while ((bytes_read = read(fd, &temp_cust, sizeof(struct Customer))) > 0){
        //printf("%s %d", temp_cust.name, temp_cust.cid);
        if (temp_cust.cid == cid) {
            offset = lseek(fd, -1 * sizeof(struct Customer), SEEK_CUR);
            close(fd);
            *cust = temp_cust;
            return offset; // Return the found customer
        }
    }

    if (bytes_read < 0) {
        perror("Could not read");
    }

    close(fd);
    return -1; // Return an empty struct if not found
}

int modify_customer(struct Customer cust, off_t offset, int cid){
    int fd;
    ssize_t bytes_writ;
    fd = open(CUSTOMER_DB, O_RDWR, 0644);
    if(fd < 0){
        perror(OPENING_CUSTOMER_FAILED);
        return -1;
    }   

    if(lseek(fd, offset, SEEK_SET) < 0) {
        perror(LSEEK_FAILED);
        return -1;
    }
    
    bytes_writ = write(fd, &cust, sizeof(struct Customer));
    if(bytes_writ < 0){
        perror(MODIFY_FAILED);
        return -1;
    }
    return 1;
}

int login_customer(int userid){
    struct Customer cust;
    off_t offset;
    offset = read_customer(&cust, userid);
    if(offset == -1){
            perror(USER_NOT_FOUND);
            return -1;
    }
    // check if active
    if(cust.active != true){
        printf(USER_NOT_ACTIVE);
        return -1;
    }

    // check if logged in
    if(cust.loggedin != false){
        printf(USER_ALREADY_LOGGED_IN);
        return -1;
    }

    cust.loggedin = true;
    if(modify_customer(cust, offset, userid) == -1){
        printf(UNABLE_TO_LOGIN);
        return -1;
    }

    printf("Logged in!");
    return 1;

}

int logout_customer(int userid){
    struct Customer cust;
    off_t offset;
    offset = read_customer(&cust, userid);
    if(offset == -1){
            perror(USER_NOT_FOUND);
            return -1;
    }

    cust.loggedin = false;
    if(modify_customer(cust, offset, userid) == -1){
        printf(UNABLE_TO_LOGIN);
        return -1;
    }

    printf("Logged out!");
    return 1;

}

int deactivate_customer(int userid){
    struct Customer cust;
    off_t offset;
    offset = read_customer(&cust, userid);
    if(offset == -1){
            perror(USER_NOT_FOUND);
            return -1;
    }
    // check if active
    if(cust.active != true){
        printf(USER_ALREADY_INACTIVE);
        return -1;
    }

    
    cust.active = false;
    if(modify_customer(cust, offset, userid) == -1){
        printf(UNABLE_TO_DEACTIVATE);
        return -1;
    }

    printf(USER_DEACTIVATED);
    return 1;

}

int activate_customer(int userid){
    struct Customer cust;
    off_t offset;
    offset = read_customer(&cust, userid);
    if(offset == -1){
            perror(USER_NOT_FOUND);
            return -1;
    }
    // check if active
    if(cust.active != false){
        printf(USER_ALREADY_ACTIVE);
        return -1;
    }

    
    cust.loggedin = true;
    if(modify_customer(cust, offset, userid) == -1){
        printf(UNABLE_TO_ACTIVATE);
        return -1;
    }

    printf(USER_ACTIVATED);
    return 1;
}

#endif 
