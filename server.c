#include "commonheader.h"
#include "placeholder.h"
//#include "readwrite.h"
//#include "sendrecv.h"
#include "common_functions.h"
#include "admin.h"

#define PORT 8083
#define BUFFER_SIZE 1024

void connection_handler(int connection_fd){
	while(1){
				
				char read_buf[BUFFER_SIZE];
				int ret;
				//readwrite(connection_fd, sizeof(ROLES_MENU), ROLES_MENU, BUFFER_SIZE, read_buf)
				ret = sendrecv(connection_fd, sizeof(ROLES_MENU), ROLES_MENU, BUFFER_SIZE, read_buf);
				printf("%d \n", ret);
					
				if(ret > 0){
					int choice;
					choice = atoi(read_buf);
					printf("%d \n",choice);

					switch(choice){
						case 1: printf("Customer \n");
								break;
						case 2: printf("Employee \n");
								break;
						case 3: printf("Manager \n");
								break;
						case 4: //write_client(connection_fd, sizeof("Admin *"), "Admin *");
								/*
								if(login_admin(connection_fd) == 1){
									printf("Admin  inside\n");		
								}
								logout_admin(connection_fd);
								//admin_controller(connection_fd);
								*/
								printf("Admin \n");
								break;
						case 5: printf("Exit \n");
								break;
						default: printf("Invalid Choice \n");
					}
				}
				else{
					printf("%s \n", read_buf);
				}
	}
}

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
			connection_handler(new_socket);

			close(new_socket);
			exit(0);
		}
		close(new_socket);
	}

	close(server_fd);
	return 0;
}
