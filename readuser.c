#include "commonheader.h"
#include "employee_struct.h"
#include "placeholder.h"

int main(){

    int fd;
    int eid = 26;
    struct Employee emp;
    struct Employee temp_emp;
    ssize_t bytes_read;

    //Open the file
    if((fd = open("employee.txt", O_RDONLY, 0777)) < 0) {
        perror("Error opening the file");
        return -1;
    }

    while((bytes_read = read(fd, &temp_emp, sizeof(struct Employee))) > 0){
        if(temp_emp.eid == eid){ 
            printf("This is the employee name: %s", temp_emp.name);
            fflush(stdout);
            close(fd);
            emp = temp_emp;
            return eid;
        }
    }

    if(bytes_read < 0){
        printf("Couldn't read?");
    }

    close(fd);
    return 1;
    //Read the file
}