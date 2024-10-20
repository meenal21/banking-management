#include "commonheader.h"
#include "customer.h"
#include "placeholder.h"
#include "employee.h"
#include "admin_struct.h"

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

int modify_employee(struct Employee emp, off_t offset, int eid){
    int fd;
    ssize_t bytes_writ;
    fd = open(EMPLOYEE_DB, O_RDWR, 0644);
    if(fd < 0){
        perror(OPENING_EMPLOYEE_FAILED);
        return -1;
    }   

    if(lseek(fd, offset, SEEK_SET) < 0) {
        perror(LSEEK_FAILED);
        return -1;
    }
    
    bytes_writ = write(fd, &emp, sizeof(struct Employee));
    if(bytes_writ < 0){
        perror(MODIFY_FAILED);
        return -1;
    }
    return 1;
}

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

int main(){
    struct Customer cust;
    off_t offset;
    offset = read_customer(&cust, 6);
    if(offset == -1){
            perror("Couldnt find the customer in the database!");
            return -1;
    }
    
    char *name = "Meenakshi";
    strcpy(cust.name, name);
    
    modify_customer(cust, offset, 6);
}