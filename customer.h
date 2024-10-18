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

    printf("Enter customer details: \n");
    
    printf("Name: ");
    //do{
		fgets(message, BUFFER_SIZE, stdin);
	//	message[strcspn(message, "\n")] = '\0'; // removing new line character
	//}while(strlen(message)==0);
    strcpy(cust.name,message);
    
    printf("DOB: ");
    //do{
		fgets(message, BUFFER_SIZE, stdin);
	//	message[strcspn(message, "\n")] = '\0'; // removing new line character
	//}while(strlen(message)==0);
    strcpy(cust.dob,message);
    
    printf("Ph. Number: ");
    //do{
		fgets(message, BUFFER_SIZE, stdin);
	//	message[strcspn(message, "\n")] = '\0'; // removing new line character
	//}while(strlen(message)==0);
    strcpy(cust.number,message);

    printf("Address: ");
    //do{
		fgets(message, BUFFER_SIZE, stdin);
	//	message[strcspn(message, "\n")] = '\0'; // removing new line character
	//}while(strlen(message)==0);
    strcpy(cust.address,message);

    printf("Document Type: ");
    //do{
		fgets(message, BUFFER_SIZE, stdin);
	//	message[strcspn(message, "\n")] = '\0'; // removing new line character
	//}while(strlen(message)==0);
    strcpy(cust.iddoc,message);

    printf("ID Number: ");
    //do{
		fgets(message, BUFFER_SIZE, stdin);
	//	message[strcspn(message, "\n")] = '\0'; // removing new line character
	//}while(strlen(message)==0);
    strcpy(cust.idnumber,message);

    printf("Balance: ");
    //do{
		fgets(message, BUFFER_SIZE, stdin);
	//	message[strcspn(message, "\n")] = '\0'; // removing new line character
	//}while(strlen(message)==0);
    strcpy(cust.idnumber,message);
    cust.balance = atoi(message);


    //printf("%d\n",id);
    cust.cid = id;
    /*
    strcpy(cust.name,"Meenal Jain");
    strcpy(cust.dob, "21/11/1996");
    strcpy(cust.number,"9370713266");
    strcpy(cust.address,"Surat, Gujarat");
    strcpy(cust.iddoc,"PAN");
    strcpy(cust.idnumber,"BDIPJ0987");
    cust.balance = 12345;
    */
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

int read_customer(struct Customer * cust, int cid) {
    int fd;
    struct Customer temp_cust;
    ssize_t bytes_read;

    if ((fd = open("customer.txt", O_RDONLY)) < 0) {
        perror("Error opening the file");
        return -1; // Return an empty struct
    }

    while ((bytes_read = read(fd, &temp_cust, sizeof(struct Customer))) > 0){
        if (temp_cust.cid == cid) {
            close(fd);
            *cust = temp_cust;
            return 1; // Return the found customer
        }
    }

    if (bytes_read < 0) {
        perror("Could not read");
    }

    close(fd);
    return -1; // Return an empty struct if not found
}
#endif 
