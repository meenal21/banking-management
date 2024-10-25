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
    
    struct Loan loan;
    read_loan(&loan, 2);
    printf("%d \n", loan.amount);
}