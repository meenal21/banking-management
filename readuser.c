#include "commonheader.h"
#include "employee_struct.h"
#include "placeholder.h"

int main(){

    printf("Hello1\n");

    int fd;
    int eid = 27;
    struct Employee emp;
    ssize_t bytes_read;

    //Open the file
    if((fd = open("employee.txt", O_RDONLY, 0777)) < 0) {
        perror("Error opening the file");
        return -1;
    }
    printf("Hello\n");

    while((bytes_read = read(fd, &emp, sizeof(struct Employee))) != 0){
        printf("Read Bytes: %d",emp.eid );
        if(emp.eid == eid){ 
            printf("%d %d %s", emp.eid, eid, emp.name);
            fflush(stdout);
            close(fd);
            return eid;
        }
    }

    if(bytes_read < 0){
        printf("Couldnt read?");
    }

    printf("Out of the loop\n");
    close(fd);
    return 1;
    //Read the file
}