#ifndef MANAGER_H
#define MANAGER_H

#include "commonheader.h"
#include "employee.h"
#include "common_functions.h"



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

    getcounter(MANAGER_COUNTER, "Manager");

    return 1; 
}


int get_random_manager(){
    int fd;
    int id;
    const char* file = EMPLOYEE_DB;
    struct Employee emp;
    int count = 0;

    ssize_t bytes_read;
    
    fd = open(file, O_RDWR , 0777);
    if(fd < 0){
        perror("Error opening file");
        return -1;
    }
    int ran = random_number(MANAGER_COUNTER);
    while ((bytes_read = read(fd, &emp, sizeof(struct Employee))) > 0){
        //printf("%s %d", temp_cust.name, temp_cust.cid);
        
        if (emp.manager == true) {
            count += 1;
            if(count == ran){
                close(fd);
                return emp.eid;
            }
            
        }
    }
    close(fd);
    return -1;
}

#endif