#ifndef LOANFUNCTIONS_H
#define LOANFUNCTIONS_H

#include "commonheader.h"
#include "loan_struct.h"
#include "common_functions.h"
#include "manager.h"


int create_loan(struct Customer cust){
    struct Loan loan;
    int fd;
    int id;
    int amount;
    char message[BUFFER_SIZE];
    const char *filename = LOAN_DB;
    int mid;

    // open loan file
    ssize_t bytes_writ;
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if(fd < 0){
        perror("Error opening file");
        return -1;
    }
    // get loan id
    id = getcounter("lid.txt", "Loan");
    if(id < 0){
        perror("Loan Id couldn't be added");
    }

    printf("Amount: ");
	fgets(message, BUFFER_SIZE, stdin);
    loan.amount = atoi(message);
    loan.lid = id;
    loan.assigned = false;
    loan.rejected = false;
    loan.approved = false;
    loan.cid = cust.cid;
    loan.eid = -1;

    mid = get_random_manager();
    if(mid == -1){
        printf("Error! Unable to find a manager to assing a loan!");
        close(fd);
        return -1;
    }

    loan.mid = mid;
    bytes_writ = write(fd, &loan, sizeof(struct Loan));
    if(bytes_writ < 0){
        perror(MODIFY_FAILED);
        close(fd);
        // revert the counter here somehow!
        return -1;
    }

    close(fd);
    printf("Loan has been requested!");
    return 1;
}

int read_loan(struct Loan *loan, int lid) {
    int fd;
    struct Loan temp;
    ssize_t bytes_read;
    off_t offset;
    if ((fd = open(LOAN_DB, O_RDONLY)) < 0) {
        perror("Error opening the file");
        return -1; // Return an empty struct
    }

    while ((bytes_read = read(fd, &temp, sizeof(struct Loan))) > 0){
        if (temp.lid == lid) {
            //printf("Found Employee: %d, Name: %s\n", emp.eid, emp.name);
            offset = lseek(fd, -1 * sizeof(struct Loan), SEEK_CUR);
            close(fd);
            *loan = temp;
            return offset; // Return the found employee
        }
    }

    if (bytes_read < 0) {
        perror("Could not read");
    }

    close(fd);
    return -1; // Return an empty struct if not found
}


int list_loan_manager(int mid){
    int fd;
    struct Loan loan;
    ssize_t bytes_read;

    if ((fd = open(LOAN_DB, O_RDONLY)) < 0) {
        perror("Error opening the file");
        return -1; // Return an empty struct
    }
    char loans[BUFFER_SIZE];
    char lid[12];
    int count = 0;
    while ((bytes_read = read(fd, &loan, sizeof(struct Loan))) > 0){
        //printf("%s %d", temp_cust.name, temp_cust.cid);
        if (loan.mid == mid && loan.eid == -1) {
            
            if (count > 0) {
                strcat(loans, ", "); // Add a comma if it's not the first number
            }
            count += 1;
            snprintf(lid, sizeof(lid), "%d", loan.lid); // Convert number to string
            strcat(loans, lid);
            // Return the found customer
        }
    }

    if(count == 0){
        return -1;
    }
    if (bytes_read < 0) {
        perror("Could not read");
        close(fd); 
        return -1;
    }

    printf("%s\n", loans);

    close(fd);
    return -1; // Return an empty struct if not found
}

int modify_loan(struct Loan loan, off_t offset, int lid){
    int fd;
    ssize_t bytes_writ;
    fd = open(LOAN_DB, O_RDWR, 0777);
    if(fd < 0){
        perror(OPENING_LOAN_FAILED);
        return -1;
    }   

    if(lseek(fd, offset, SEEK_SET) < 0) {
        perror(LSEEK_FAILED);
        return -1;
    }
    
    bytes_writ = write(fd, &loan, sizeof(struct Loan));
    if(bytes_writ < 0){
        perror(MODIFY_FAILED);
        return -1;
    }
    return 1;
}

int list_loan_employee(int eid){
    int fd;
    struct Loan loan;
    ssize_t bytes_read;

    if ((fd = open(LOAN_DB, O_RDONLY)) < 0) {
        perror("Error opening the file");
        return -1; // Return an empty struct
    }
    char loans[BUFFER_SIZE];
    char lid[12];
    int count = 0;
    while ((bytes_read = read(fd, &loan, sizeof(struct Loan))) > 0){
        //printf("%s %d", temp_cust.name, temp_cust.cid);
        if (loan.eid == eid && loan.approved == false && loan.rejected ==false) {
            
            if (count > 0) {
                strcat(loans, ", "); // Add a comma if it's not the first number
            }
            count += 1;
            snprintf(lid, sizeof(lid), "%d", loan.lid); // Convert number to string
            strcat(loans, lid);
            // Return the found customer
        }
    }

    if(count == 0){
        return -1;
    }
    if (bytes_read < 0) {
        perror("Could not read");
        close(fd); 
        return -1;
    }

    printf("%s\n", loans);

    close(fd);
    return 1; // Return an empty struct if not found
}

int process_loans(int eid){
    // we have loan structure, mid, and eid whom to assign - get employee list?
    // make function for employee list - or abhi show all employee and randomly assign loans
    int ls = list_loan_employee(eid) ;
    if(ls == -1){
        printf("No Loans to be processed");
        return -1;
    }

    printf("Enter a loan to assign: ");
    char message[BUFFER_SIZE];
    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;
    int lid;
    lid = atoi(message);

    //read loan
    struct Loan loan;
    off_t rd;
    rd = read_loan(&loan, lid);
    if( rd == -1){
        return -1;
    }

    
    
    while(1){
        printf("Accept/Reject (A/R/X): \n");
        fgets(message, BUFFER_SIZE, stdin);
        message[strcspn(message, "\n")] = '\0';

        if(strcmp(message, "A") == 0){
            loan.approved = true;

            if(modify_loan(loan, rd, lid) ==-1){
                return -1;
            }
            printf("The loan has been approved");
            return 1;
        }
        else if(strcmp(message, "R")==0){
            loan.rejected = true;
            if(modify_loan(loan, rd, lid) ==-1){
                return -1;
            }
            printf("The loan has been rejected");
            return 1;
        }
        else if(strcmp(message, "X")==0){
            printf("No action was taken!");
            return 1;
        }
        else{
            printf("Wrong Input \n");
        }
    }
    // now update the loan   
}

#endif