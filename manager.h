#ifndef MANaGER_H
#define MANAGER_H

#include "commonheader.h"
#include "employee.h"


int make_manager(int eid) {
    struct Employee emp;
    off_t offset;
    offset = read_employee(&emp,eid);
    if( offset == -1){
        printf("Unable to get the Employee");
        return -1;
    }

    printf("%d\n", emp.manager);
    if(emp.manager == true){
        printf("Already a manager");
        return -1;
    }
    emp.manager = true;
    if(modify_employee(emp, offset, eid) == -1){
        printf("Unable to promote to Manager");
        return -1;
    }

    get_counter(MANAGER_COUNTER, "Manager");

    return 1; 
}

int get_count(){
    int fd;
    int id;
    const char *file = MANAGER_COUNTER;
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