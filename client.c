#include "commonheader.h"
#include <strings.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>

#define PORT 8083
#define BUF_SIZE 1024

ssize_t read_input(char *buffer, size_t size) {
    printf("> ");
    fflush(stdout);
    
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
            return len - 1;
        }
        return len;
    }
    return -1;
}

int main(){
	int sock = 0;
	struct sockaddr_in serv_addr;
	char buffer[BUF_SIZE] = {0};
	char message[BUF_SIZE];

	//Step 1: Create a socket
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("Socket Creation error\n");
		return -1;
	}
	printf("Socket created successfully\n");

	//Step 2: Specify the server address
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port =  htons(PORT);

	//convert IPv4 address from text to binary 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
		perror("Invalid address or Address not supported\n");
		return -1;
	}

	//Step 3 Connect to the server
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
		perror("Connecton failed\n");
		return -1;
	}
	printf("Connected to the server \n");
	fflush(stdout);

	//Step 4: Communicate with the server
	
	// while(1) {
	// 	fflush(stdout);
	// 	fflush(stdin);
	// 	// first read from the server
	// 	int bytes_read;
	// 	bzero(buffer,BUF_SIZE);
	// 	bzero(message, sizeof(message));
	// 	bytes_read = read(sock, buffer, BUF_SIZE);
	// 	if(bytes_read <= 0){
	// 		printf("Server has closed the connection. \n");
	// 		break;
	// 	}
	// 	// buffer[bytes_read] = '\0';
	// 	printf("%s", buffer);
		
	// 	if(strchr(buffer, '*')){
	// 		// printf("\nOnly Read\n");
	// 		continue;
	// 	}
		

	// 	//get input from the user
	// 	fflush(stdout);
	// 	fgets(message, BUF_SIZE, stdin);
	// 	message[strcspn(message, "\n")] = '\0'; // removing new line character
	// 	//Send the message to the server
	// 	write(sock, message, strlen(message));

	// 	//check if the user has exited!
	// 	/*
	// 	if(strcmp(message, "exit")==0){
	// 		printf("Disconnected from the server\n");
	// 		break;
	// 	}
	// 	*/
	// }
	fd_set readfds;
	int maxfd;
	while (1) {
		// fflush(stdout);
		// fflush(stdin);
		memset(buffer, 0, BUF_SIZE);
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);  // Add stdin to set
        FD_SET(sock, &readfds);          // Add socket to set
        maxfd = (sock > STDIN_FILENO ? sock : STDIN_FILENO) + 1;

        // Wait for input from either socket or stdin
        if (select(maxfd, &readfds, NULL, NULL, NULL) < 0) {
            perror("Select error");
            break;
        }

        // Check for socket data (server message)
        if (FD_ISSET(sock, &readfds)) {
            memset(buffer, 0, BUF_SIZE);
            ssize_t bytes = read(sock, buffer, BUF_SIZE - 1);
            
            if (bytes <= 0) {
                if (bytes == 0) {
                    printf("\nServer closed connection\n");
                } else {
                    perror("Read error");
                }
                break;
            }

            buffer[bytes] = '\0';
            printf("%s", buffer);
            fflush(stdout);

            if (strchr(buffer, '*') != NULL) {
                continue;
            }
        }

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            memset(buffer, 0, BUF_SIZE);
            if (read_input(buffer, BUF_SIZE) > 0) {
                ssize_t bytes = write(sock, buffer, strlen(buffer));
                if (bytes <= 0) {
                    perror("Write error");
                    break;
                }
            }
        }
    }
	
	close(sock);
	return 0;
}
