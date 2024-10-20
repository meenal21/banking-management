#ifndef EMPLOYEE_FUNCTIONS_H
#define EMPLOYEE_FUNCTIONS_H

#include "./commonheader.h"
#include "./employee_struct.h"
#include "./placeholder.h"
#include "./getcounter.h"

int create_employee(){
    int fd;
    int id;
    struct Employee emp;
    ssize_t bytes_writ;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    const char *filename = EMPLOYEE_DB;

    fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0777); // Use O_APPEND to append to the file
    if (fd < 0) {
        perror(OPENING_EMPLOYEE_FAILED);
        return -1;
    }

    id = getcounter(EMPLOYEE_DB, "Employee");
    if (id < 0) {
        perror("Employee Id couldn't be added");
        close(fd);
        return -1;
    }

    printf("Enter Employee details: \n");
    
    printf("Name: ");
    fgets(message, BUFFER_SIZE, stdin);
    strcpy(emp.name,message);
    
    printf("DOB: ");
    fgets(message, BUFFER_SIZE, stdin);
    strcpy(emp.dob,message);
    
    printf("Ph. Number: ");
    fgets(message, BUFFER_SIZE, stdin);
    strcpy(emp.number,message);

    printf("Address: ");
    fgets(message, BUFFER_SIZE, stdin);
    strcpy(emp.address,message);

    printf("Document Type: ");
    fgets(message, BUFFER_SIZE, stdin);
    strcpy(emp.iddoc,message);

    printf("ID Number: ");
    fgets(message, BUFFER_SIZE, stdin);
    strcpy(emp.idnumber,message);

    
    emp.eid = id;
    emp.eid = id;
    emp.manager = false;
    emp.active = true;
    emp.loggedin = false;

    bytes_writ = write(fd, &emp, sizeof(struct Employee));
    if (bytes_writ < 0) {
        perror("Creating employee failed");
        close(fd);
        return -1;
    }

    printf("Employee has been created!\n");
    close(fd);
    return id;
}

int read_employee(struct Employee *emp, int eid) {
    int fd;
    struct Employee temp;
    ssize_t bytes_read;

    if ((fd = open("employee.txt", O_RDONLY)) < 0) {
        perror("Error opening the file");
        return -1; // Return an empty struct
    }

    while ((bytes_read = read(fd, &temp, sizeof(struct Employee))) > 0){
        if (temp.eid == eid) {
            //printf("Found Employee: %d, Name: %s\n", emp.eid, emp.name);
            close(fd);
            *emp = temp;
            return 1; // Return the found employee
        }
    }

    if (bytes_read < 0) {
        perror("Could not read");
    }

    close(fd);
    return -1; // Return an empty struct if not found
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

#endif