#ifndef EMPLOYEE_FUNCTIONS_H
#define EMPLOYEE_FUNCTIONS_H

#include "./commonheader.h"
#include "./employee_struct.h"
#include "./placeholder.h"
#include "./getcounter.h"

int createemp(){
    int fd;
    int id;
    struct Employee emp;
    ssize_t bytes_writ;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    const char *filename = "employee.txt";

    fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0777); // Use O_APPEND to append to the file
    if (fd < 0) {
        perror("Error opening file");
        return -1;
    }

    id = getcounter("eid.txt", "Employee");
    if (id < 0) {
        perror("Employee Id couldn't be added");
        close(fd);
        return -1;
    }

    printf("Enter Employee details: \n");
    
    printf("Name: ");
    // do{
		fgets(message, BUFFER_SIZE, stdin);
		// message[strcspn(message, "\n")] = '\0'; // removing new line character
	// }while(strlen(message)==0);
    strcpy(emp.name,message);
    
    printf("DOB: ");
    // do{
		fgets(message, BUFFER_SIZE, stdin);
		// message[strcspn(message, "\n")] = '\0'; // removing new line character
	// }while(strlen(message)==0);
    strcpy(emp.dob,message);
    
    printf("Ph. Number: ");
    // do{
		fgets(message, BUFFER_SIZE, stdin);
		// message[strcspn(message, "\n")] = '\0'; // removing new line character
	// }while(strlen(message)==0);
    strcpy(emp.number,message);

    printf("Address: ");
    // do{
		fgets(message, BUFFER_SIZE, stdin);
		// message[strcspn(message, "\n")] = '\0'; // removing new line character
	// }while(strlen(message)==0);
    strcpy(emp.address,message);

    printf("Document Type: ");
    // do{
		fgets(message, BUFFER_SIZE, stdin);
		// message[strcspn(message, "\n")] = '\0'; // removing new line character
	// }while(strlen(message)==0);
    strcpy(emp.iddoc,message);

    printf("ID Number: ");
    // do{
		fgets(message, BUFFER_SIZE, stdin);
		// message[strcspn(message, "\n")] = '\0'; // removing new line character
	// }while(strlen(message)==0);
    strcpy(emp.idnumber,message);

    //printf("%d\n",id);
    emp.eid = id;
    /*
    strcpy(cust.name,"Meenal Jain");
    strcpy(cust.dob, "21/11/1996");
    strcpy(cust.number,"9370713266");
    strcpy(cust.address,"Surat, Gujarat");
    strcpy(cust.iddoc,"PAN");
    strcpy(cust.idnumber,"BDIPJ0987");
    cust.balance = 12345;
    */
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

struct Employee readuser(int eid) {
    int fd;
    struct Employee emp;
    ssize_t bytes_read;

    if ((fd = open("employee.txt", O_RDONLY)) < 0) {
        perror("Error opening the file");
        return emp; // Return an empty struct
    }

    while ((bytes_read = read(fd, &emp, sizeof(struct Employee))) > 0) {
        if (emp.eid == eid) {
            printf("Found Employee: %d, Name: %s\n", emp.eid, emp.name);
            close(fd);
            return emp; // Return the found employee
        }
    }

    if (bytes_read < 0) {
        perror("Could not read");
    }

    close(fd);
    return emp; // Return an empty struct if not found
}

#endif