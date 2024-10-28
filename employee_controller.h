#ifndef CUST_CONTR_H
#define CUST_CONTR_H

#include "commonheader.h"
#include "placeholder.h"
#include "common_functions.h"
#include "employee.h"
#include "customer.h"
#include "transact.h"
#include "loan.h"


int admin_handler(int connection_fd){
	while(1){
				
				char read_buf[BUFFER_SIZE];
				int ret;
				ret = sendrecv(connection_fd, sizeof(CUSTOMER_MENU), CUSTOMER_MENU, BUFFER_SIZE, read_buf);
				//printf("%d \n", ret);
					
				if(ret > 0){
					int choice;
					choice = atoi(read_buf);
					//printf("%d \n",choice);

					switch(choice){
						case 1: char *str = "Add New Customer \n"
                                send_only(connection_fd, strlen(str), str);
								break;
						case 2: char *str = "Modify Customer Details \n"
                                send_only(connection_fd, strlen(str), str);
                                printf("Modify Employee Details \n");
								break;
                        case 3: char *str = "Accept/Reject Loans \n"
                                send_only(connection_fd, strlen(str), str);
                                printf("Modify Customer Details \n");
								break;

                        case 4: char *str = "View Customer Transaction History \n"
                                send_only(connection_fd, strlen(str), str);
                                printf("Change Password \n");
                                //change_pass(connection_fd);
								break;

                        case 5: char *str = "Change Password \n"
                                send_only(connection_fd, strlen(str), str);
                                printf("Change Password \n");
                                //change_pass(connection_fd);
								break;        
						case 6: char *str = "Logout \n"
                                send_only(connection_fd, strlen(str), str);
                                printf("Logout \n");
                                //logout_customer(connection_fd);
								return 0;
						default: printf("Invalid Choice \n");
					}
				}
				else{
					// break - because - iff any error then cancel
					return 1;
				}
	}
}

#endif