#ifndef TRANSACTION_H
#define TRANSACTION_H

struct Transaction{
	int cid;
	char name[30];
	int amount;
	char action[2];
	int balance;
};

#endif 
