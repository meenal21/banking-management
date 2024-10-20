#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#define BUFFER_SIZE 1024
#define CREDIT "CR"
#define DEBIT "DR"

#define CUSTOMER_MENU "------Menu------\n1. Deposit Money \n2. Withdraw Money\n3. Transfer Funds \n4. Transaction History \n5. Apply for Loan \n6. Give Feedback \n7. Change Password \n8. Exit";
#define EMPLOYEE_MENU "------Menu------\n1. Add Customer\n2. Modify Customer\n3. Process Loan Application\n4. Approve/Reject Application\n5. View Assigned Loan Application\n6. View Customer Transaction history\n7. Change Password\n 8. Exit";
#define MANAGER_MENU "------Menu------\n1. Activate/Deactivate Customer Accounts\n2. Assign loan to an employee\n3. Review Customer Feedback\n4. Change Password \n5.Exit";
#define ADMIN_MENU "------Menu------\n1. Add new Employee\n2. Modify Employee Details\n3. Modify Customer Details\n4. Change User Roles\n5. Exit"
#define ROLES_MENU "------Roles Menu------\n1. Customer\n2. Employee\n3. Manager\n4. Admin\n5. Exit"



#define ERROR_WRITING_TO_CLIENT "!!!----- Error writing to the client -----!!!"
#define NO_DATA_RECEIVED "!!! ----- No Data Received from the client -----!!!"
#define OPENING_CUSTOMER_FAILED "!!!----- Unable to open the customer database -----!!!"
#define OPENING_TRANSACTION_FAILED "!!!----- Unable to open the transaction database -----!!!"
#define OPENING_ADMIN_FAILED "!!!----- Unable to open the admin database -----!!!"
#define OPENING_EMPLOYEE_FAILED "!!!----- Unable to open the employee database -----!!!"
#define OPENING_LOAN_FAILED "!!!----- Unable to open the loan database -----!!!"
#define LSEEK_FAILED "!!!----- Lseek Failed -----!!!"
#define MODIFY_FAILED "!!!----- Modify Failed -----!!!"

#define EMPLOYEE_DB "employee.txt"
#define CUSTOMER_DB "customer.txt"
#define TRANSACTION_DB "transaction_logs.txt"
#define ADMIN_DB "admin.txt"
#define LOAN_DB "loan.txt"

#endif 