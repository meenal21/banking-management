#include "initialize_id.h"
#include "commonheader.h"
#include "customer.h"
#include "employee.h"
#include "employee_struct.h"
#include "customer_struct.h"
//#include "read"

int main(){
    //printf("%d\n", initialize());
    //printf("%d\n",getcounter("cid.txt","Customer"));
    
    //printf("%d \n",create_customer());
    //printf("%d \n",createemp());
    //printf("%s \n", read_customer(27).name);
    /*
    struct Employee emp;
    printf("%d \n", read_employee(&emp, 26));
    printf("%s \n", emp.name);
    */
    /*
    if(create_admin() != 1){
        printf("Admin not created!");
    }
    */
    struct Customer cust;
    printf("%ld \n", read_customer(&cust,1));
    printf("%d \n", cust.loggedin);
    return 0;
    //*/
   //printf("%d\n",getcounter("tid.txt","Transaction"));
}
