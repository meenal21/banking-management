#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#define BUFFER_SIZE 1024
#define CREDIT "CR"
#define DEBIT "DR"
#define LOGIN_PASSWORD "\nEnter Password: \n"

#define CUSTOMER_MENU "\n------Menu------\n1. Deposit Money \n2. Withdraw Money\n3. Transfer Funds \n4. Transaction History \n5. Apply for Loan \n6. Give Feedback \n7. Change Password \n8. Logout\n9. Exit\n"
#define EMPLOYEE_MENU "\n------Menu------\n1. Add Customer\n2. Modify Customer\n3. Process Loan Application\n4. Approve/Reject Application\n5. View Assigned Loan Application\n6. View Customer Transaction history\n7. Change Password\n8. Logout\n9. Exit\n"
#define MANAGER_MENU "\n------Menu------\n1. Activate/Deactivate Customer Accounts\n2. Assign loan to an employee\n3. Review Customer Feedback\n4. Change Password \n5. Logout\n6. Exit\n"
#define ADMIN_MENU "\n------Menu------\n1. Add new Employee\n2. Modify Employee Details\n3. Modify Customer Details\n4. Change User Roles\n5. Logout\n6. Exit\n"
#define ROLES_MENU "\n------Roles Menu------\n1. Customer\n2. Employee\n3. Manager\n4. Admin\n5. Exit\n"



#define ERROR_WRITING_TO_CLIENT "\n!!!----- Error writing to the client* -----!!!\n"
#define ERROR_READING_FROM_CLIENT "\n!!!----- Error reading from the client* -----!!!\n"
#define NO_DATA_RECEIVED "\n!!! ----- No Data Received from the client* -----!!!\n"
#define OPENING_CUSTOMER_FAILED "\n!!!----- Unable to open the customer database* -----!!!\n"
#define OPENING_TRANSACTION_FAILED "\n!!!----- Unable to open the transaction database* -----!!!\n"
#define OPENING_ADMIN_FAILED "\n!!!----- Unable to open the admin database* -----!!!\n"
#define OPENING_EMPLOYEE_FAILED "\n!!!----- Unable to open the employee database* -----!!!\n"
#define OPENING_LOAN_FAILED "\n!!!----- Unable to open the loan database* -----!!!\n"
#define LSEEK_FAILED "\n!!!----- Lseek Failed* -----!!!\n"
#define MODIFY_FAILED "\n!!!----- Modify Failed* -----!!!\n"
#define USER_NOT_FOUND "\n!!!----- User not found* ----- !!!\n"
#define USER_NOT_ACTIVE "\n!!!----- User not active* ----- !!!\n"
#define USER_ALREADY_LOGGED_IN "\n!!!----- User already logged in* ----- !!!\n"
#define UNABLE_TO_LOGIN "\n!!!----- Unable to Login* ----- !!!\n"
#define UNABLE_TO_LOGOUT "\n!!!----- Unable to Logout* ----- !!!\n"
#define UNABLE_TO_READ_ADMIN "\n!!!----- Unable to read admin db* ----- !!!\n"
#define ADMIN_CREATION_FAILED "\n!!!----- Unable to create the admin* -----!!!\n"
#define USER_ALREADY_ACTIVE "\n!!!----- User is already active* -----!!!\n"
#define USER_ALREADY_INACTIVE "\n!!!----- User is already inactive* -----!!!\n"
#define SUCCESSFULLY_LOGGED_IN "\n!!!----- Successfully Logged in!* ----- !!!\n"
#define SUCCESSFULLY_LOGGED_OUT "\n!!!----- Successfully Logged out!* ----- !!!\n"
#define USER_ACTIVATED "\n!!!----- User activated* -----!!!\n"
#define USER_DEACTIVATED "\n!!!----- User deactivated* -----!!!\n"
#define UNABLE_TO_ACTIVATE "\n!!!----- Unable to activate the user* ----- !!!\n"
#define UNABLE_TO_DEACTIVATE "\n!!!----- Unable to deactivate the user* ----- !!!\n"
#define INVALID_CREDENTIALS "\n!!!----- Unable to login! Invalid credentials!* -----!!!\n"



#define EMPLOYEE_DB "employee.txt"
#define CUSTOMER_DB "customer.txt"
#define TRANSACTION_DB "transaction_logs.txt"
#define ADMIN_DB "admin.txt"
#define LOAN_DB "loan.txt"
#define FEEDBACK_DB "feedback.txt"

#define CUSTOMER_COUNTER "cid.txt"
#define TRANSACTION_COUNTER "tid.txt"
#define EMPLOYEE_COUNTER "eid.txt"
#define LOAN_COUNTER "lid.txt"
#define FEEDBACK_COUNTER "fid.txt"
#define MANAGER_COUNTER "mid.txt"

#endif 