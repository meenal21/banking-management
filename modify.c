#include "commonheader.h"
#include "customer.h"
#include "placeholder.h"
#include "employee.h"







int main(){
    struct Customer cust;
    off_t offset;
    offset = read_customer(&cust, 2);
    if(offset == -1){
            perror("Couldnt find the customer in the database!");
            return -1;
    }
    
    char *name = "Meenakshi";
    strcpy(cust.name, name);
    
    modify_customer(cust, offset, 2);
}