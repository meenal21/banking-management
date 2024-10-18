#include "commonheader.h"
#include "employee.h"
#include "getcounter.h"
#include "placeholder.h"

int main(){

    int fd;
    int id;
    struct Employee emp;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    char const *filename = "employee.txt";
    
    

    //ssize_t bytes_read;
    ssize_t bytes_writ;
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if(fd < 0){
        perror("Error opening file");
        return -1;
    }


    id = getcounter("eid.txt", "Employee");
    if(id < 0){
        perror("Employee Id couldn't be added");
    }

    printf("Enter Employee details: \n");
    
    printf("Name: ");
    do{
		fgets(message, BUFFER_SIZE, stdin);
		message[strcspn(message, "\n")] = 0; // removing new line character
	}while(strlen(message)==0);
    strcpy(emp.name,message);
    
    printf("DOB: ");
    do{
		fgets(message, BUFFER_SIZE, stdin);
		message[strcspn(message, "\n")] = 0; // removing new line character
	}while(strlen(message)==0);
    strcpy(emp.dob,message);
    
    printf("Ph. Number: ");
    do{
		fgets(message, BUFFER_SIZE, stdin);
		message[strcspn(message, "\n")] = 0; // removing new line character
	}while(strlen(message)==0);
    strcpy(emp.number,message);

    printf("Address: ");
    do{
		fgets(message, BUFFER_SIZE, stdin);
		message[strcspn(message, "\n")] = 0; // removing new line character
	}while(strlen(message)==0);
    strcpy(emp.address,message);

    printf("Document Type: ");
    do{
		fgets(message, BUFFER_SIZE, stdin);
		message[strcspn(message, "\n")] = 0; // removing new line character
	}while(strlen(message)==0);
    strcpy(emp.iddoc,message);

    printf("ID Number: ");
    do{
		fgets(message, BUFFER_SIZE, stdin);
		message[strcspn(message, "\n")] = 0; // removing new line character
	}while(strlen(message)==0);
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
    emp.manager = false;
    emp.active = true;
    emp.loggedin = false;
    
    
    if((bytes_writ = write(fd,&emp,sizeof(struct Employee))) < bytes_writ){
        perror("Creating employee failed");
        close(fd);
        return -1;
    }
    printf("Employee has been created!");
    close(fd);

    return 1;
}