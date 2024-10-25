#include "commonheader.h"
#include "placeholder.h"
#include "getcounter.h"
#include "common_functions.h"
#include "customer.h"
#include "employee.h"
#include "loan_struct.h"
#include "loan.h"
#include "manager.h"
#include "admin.h"

//show loans ka list:

int admin_controller(int sfd){
    while(1){
    printf(ADMIN_MENU);
    char message[BUFFER_SIZE];

    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message,"\n")] = 0;
    int ch;
    ch = atoi(message);

    switch(ch){
        case 1: printf("Add Employee");
                break;
        case 2: printf("Modify Employee");
                break;
        case 3: printf("Modify Customer");
                break;
        case 4: printf("Promote Employee");
                break;
        case 5: printf("Change Password");
                break;
        case 6: printf("Logging out");
                break;
        case 7: printf("Exit");
                break;
        default: printf("Wrong Choice!");
    };

   }
}

int customer_controller(int sfd){
     while(1){
    printf(CUSTOMER_MENU);
    char message[BUFFER_SIZE];

    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message,"\n")] = 0;
    int ch;
    ch = atoi(message);

    switch(ch){
        case 1: printf("Deposit Money");
                break;
        case 2: printf("Withdraw Money");
                break;
        case 3: printf("Transfer Funds");
                break;
        case 4: printf("Transaction History");
                break;
        case 5: printf("Apply for Loan");
                break;
        case 6: printf("Give Feedback");
                break;        
        case 7: printf("Change Password");
                break;
        case 8: printf("Logging out");
                break;
        case 9: printf("Exit");
                break;
        default: printf("Wrong Choice!");
    };

   }
}

int main(){

    //printf("%d\n", make_manager(3));
    //printf("%d \n",login_admin());
    //printf("%d\n", get_count(LOAN_COUNTER));
    //printf("%d\n", random_number(MANAGER_COUNTER));
    //printf("%d\n", get_random_manager());
    
    //struct Customer cust;
    //printf("%ld \n", read_customer(&cust,2));
    //printf("%d\n", create_loan(cust));
    //login_customer(1);
    //login_employee_chk(3);
    //list_loan_manager(2);
    //list_employees();
   
    //assign_loans(2);
    /*
    struct Loan loan;
    read_loan(&loan, 2);
    printf("%d \n", loan.amount);
    */
    logout_admin();
   
  
}