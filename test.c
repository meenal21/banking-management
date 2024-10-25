#include "initialize_id.h"
#include "commonheader.h"
#include "customer.h"
#include "employee.h"
//#include "read"

int main(){
    //printf("%d\n", initialize());
    //printf("%d\n",getcounter("cid.txt","Customer"));
    //srand(time(NULL));
    //printf("%d \n",create_customer());
    //int newId = create_employee();
    
    //printf("%d \n",createemp());
    //printf("%s \n", read_customer(27).name);
    
    /*
    struct Employee emp;
    printf("%d \n", read_employee(&emp, 1));
    printf("%s \n", emp.name);
    */
    /*
    if(create_admin() != 1){
        printf("Admin not created!");
    }
    */
    struct Customer cust;
    printf("%ld \n", read_customer(&cust,3));
    printf("%d \n", cust.loggedin);
    return 0;
    
   //printf("%d\n",getcounter("tid.txt","Transaction"));


}
