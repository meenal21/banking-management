#include "commonheader.h"
#include <strings.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

	int server_fd, new_socket;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[BUFFER_SIZE] = {0};
	pid_t childpid;

	// Create Socket
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
		perror("Socket failed");
		exit(EXIT_FAILURE);
	}
	printf("Socket created successfully...\n");

	// Step 2 Bind the socket to the specified port
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if(bind(server_fd, (struct sockaddr*)&address, sizeof(address))<0){
		perror("Bind Failed!");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	printf("Bind to the port successful!... \n");

	// Step 3: Listen for incoming connections
	if(listen (server_fd, 5) < 0) 
	// 5 children are allowed for concurrency
	{
		perror("Listen Failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}
	printf("Server is listening..\n");

	while(1){
		// Step 4: Now accept the incoming connection
		if((new_socket = accept(server_fd,(struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0){
			perror("Accept failed!");
			continue;
		}
		printf("Connection accepted from %s:%d \n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

		// Step 5: Create a child process to handle the client

		if((childpid = fork())==0){
			//Child Process
			close(server_fd);

			//communication with the client - infinite loop here
			while(1){
				int bytes_read = recv(new_socket, buffer, BUFFER_SIZE, 0);
				if(bytes_read <= 0){
					printf("Client Disconnected.\n");
					break;
				}
				// adding null character that acts as a null terminated string
				buffer[bytes_read] ='\0';
				printf("Client: %s\n", buffer);

				//echo the message back to the client
				send(new_socket, buffer, strlen(buffer),0);
				bzero(buffer, BUFFER_SIZE);
			}
			close(new_socket);
			exit(0);
		}

		close(new_socket);
	}

	close(server_fd);
	return 0;
}
