#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee{
	int eid;
	char emailid[30];
	char password[15];
	char name[30];
	char dob[10];
	char number[10];
	char address[50];
	char iddoc[10];
	char idnumber[20];
	bool manager;
	bool active;
	bool loggedin;
};

#endif
