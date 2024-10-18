#include "commonheader.h"
#include <strings.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUF_SIZE 1024

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

	//Step 4: Communicate with the server
	
	while(1){
		printf("Enter message that needs to be sent!\n");
		
		do{
			fgets(message, BUF_SIZE, stdin);
			message[strcspn(message, "\n")] = '\0'; // removing new line character
		}while(strlen(message)==0);
		

		
		//Send the message to the server
		send(sock, message, strlen(message),0);

		//check if the user has exited!
		if(strcmp(message, "exit")==0){
			printf("Disconnected from the server\n");
			break;
		}

		//receive the server's response
		int bytes_read = recv(sock, buffer, BUF_SIZE, 0);
		if(bytes_read <= 0){
			printf("Server has closed the connection. \n");
			break;
		}
		buffer[bytes_read] = '\0';
		printf("Server: %s\n", buffer);
		bzero(buffer,BUF_SIZE);
	}
	
	close(sock);
	return 0;
}
