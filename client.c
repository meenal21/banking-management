#include "commonheader.h"
#include "placeholder.h"
#include "stdio.h"
#define PORT 8083

void handle_server_input(int sock){
	char buffer[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);
	
	printf("%s", buffer);	

	ssize_t rBytes;
	fflush(stdin);
	fflush(stdout);
	rBytes = recv(sock, buffer, BUFFER_SIZE - 1,0);
	fflush(stdin);
	fflush(stdout);
	if(rBytes < 0){
		printf("Socket reading error!");
		exit(EXIT_FAILURE);
	}
	if(rBytes == 0){
		printf(SERVER_CLOSED_CONNECTION);
		exit(EXIT_FAILURE);
	}

	buffer[rBytes] = '\0';
	printf("%s",  buffer);
	fflush(stdout);

	// if * is there then only write!
	if(strchr(buffer,'*') != NULL){
		return;
	}
}

void handle_user_input(int sock){
	char buffer[BUFFER_SIZE];
	//memset(buffer, 0 , BUFFER_SIZE);
	fflush(stdout);
	fflush(stdin);

	//printf("Inside the handle user input! Please Please take input");	

	if(fgets(buffer, BUFFER_SIZE, stdin) != NULL){
		//printf("%s Did it get anything from the fgets?", buffer);
		buffer[strcspn(buffer, "\n")] = '\0';
		
		fflush(stdin);
		fflush(stdout);
		ssize_t wBytes = send(sock, buffer, strlen(buffer),0);
		if(wBytes <= 0){
			printf(ERROR_WRITING_TO_SERVER);
			exit(EXIT_FAILURE);
		}
	}
}

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
	char buffer[BUFFER_SIZE] = {0};
	char message[BUFFER_SIZE];

	//Step 1: Create a socket
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("Socket Creation error\n");
		return -1;
	}
	//printf("Socket created successfully\n");

	//Step 2: Specify the server address
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port =  htons(PORT);

	//convert IPv4 address from text to binary 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
		printf("Invalid address or Address not supported\n");
		return -1;
	}

	//Step 3 Connect to the server
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
		printf("Connecton failed\n");
		return -1;
	}
	//printf("Connected to the server \n");
	fflush(stdout);

	

	fd_set readfds;
	int maxfd;
	while(1){
		memset(buffer,0, BUFFER_SIZE);
		FD_ZERO(&readfds);  // clear read file descriptor set
		FD_SET(STDIN_FILENO, &readfds); //add stdin to the set
		FD_SET(sock, &readfds); // add sock to the set

		maxfd = (sock > STDIN_FILENO ?  sock : STDIN_FILENO) + 1;

		//get the input from stdin or sock
		int select_status; 
		// select scans - 0 to maxfd -1 - fds - whichever is ready
		select_status = select(maxfd, &readfds,NULL, NULL, NULL);
		if(select_status < 0){
			printf(SELECT_ERROR);
			break;
		}

		//check if there is any data from server
		if(FD_ISSET(sock, &readfds)){
			handle_server_input(sock);
		}

		//check if data from stdin
		if(FD_ISSET(STDIN_FILENO, &readfds)){
			//printf("Lol! is the control even here?");
			handle_user_input(sock);
		}
	}
		
	close(sock);
	return 0;
}
