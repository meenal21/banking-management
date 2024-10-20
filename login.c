#include "commonheader.h"
#include "customer.h"
#include "placeholder.h"
#include "employee.h"
#include "admin.h"
#include "feedback_struct.h"

int read_feedback(){
    int fd;
    struct Feedback fb;
    char buffer[BUFFER_SIZE];
    char const *filename = FEEDBACK_DB;
    ssize_t bytes_read;

    fd = open(filename, O_RDONLY | O_CREAT | O_APPEND, 0777);
    if(fd < 0){
        perror("Error opening file");
        return -1;
    }

    while ((bytes_read = read(fd, &fb, sizeof(struct Feedback))) > 0){
            printf("%s \n",fb.feedback);
    }

    close(fd);

    if (bytes_read < 0) {
        perror("Could not read");
        return -1;
    }

    return 1; 

}

int give_feedback(int userid){

    int fd;
    int id;
    struct Feedback fb;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    char const *filename = FEEDBACK_DB;

    //open file - 
    ssize_t bytes_writ;
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if(fd < 0){
        perror("Error opening file");
        return -1;
    }

    id = getcounter(FEEDBACK_DB, "Feedback");
    if(id < 0){
        perror("Feedback Id couldn't be added");
        return -1;
    }

    fb.cid = userid;
    fb.fid = id;

    fgets(message, BUFFER_SIZE, stdin);
    printf("%s \n",message);
    strcpy(fb.feedback,message);

    bytes_writ = write(fd,&fb,sizeof(struct Feedback));
    if(bytes_writ < 0){
        perror("Adding Feedback failed");
        close(fd);
        return -1;
    }
    printf("Feedback has been given!");
    close(fd);

    return 1;

}

int main(){
    int result;
    int userid = 1;
    result = give_feedback(userid);
    printf("%d \n", result);
    read_feedback();
    return 0;

}
