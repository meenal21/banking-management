#ifndef CUSTOMER_STRUCT_H
#define CUSTOMER_STRUCT_H

struct Customer{

	int cid;
	char emailid[30];
	char password[15];
	char name[30];
	char dob[10];
	char number[10];
	char address[50];
	char iddoc[10];
	char idnumber[20];
	int balance;
	bool active;
	bool loggedin;

};

#endif
