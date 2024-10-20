#ifndef MENU_H
#define MENU_H
#include "commonheader.h"

void customer_menu(){
    printf("------Menu------");
    printf("1. Deposit Money");
    printf("2. Withdraw Money");
    printf("3. Transfer Funds");
    printf("4. Transaction History");
    printf("5. Apply for Loan");
    printf("6. Give Feedback");
    printf("7. Change Password");
}

void employee_menu(){
    printf("------Menu------");
    printf("1. Add Customer");
    printf("2. Modify Customer");
    printf("3. Process Loan Application");
    printf("4. Approve/Reject Application");
    printf("5. View Assigned Loan Application");
    printf("6. View Customer Transaction history");
    printf("7. Change Password");
}

void manager_menu(){
    printf("------Menu------");
    printf("1. Activate/Deactivate Customer Accounts");
    printf("2. Assign loan to an employee");
    printf("3. Review Customer Feedback");
    printf("4. Change Password");
}

void admin_menu(){
    
    printf("------Menu------");
    printf("1. Add new Employee");
    printf("2. Modify Employee Details");
    printf("3. Modify Customer Details");
    printf("4. Change User Roles");
}

void role_menu(){
    printf("------Roles Menu------");
    printf("1. Customer");
    printf("2. Employee");
    printf("3. Manager");
    printf("4. Admin");
}

#endif