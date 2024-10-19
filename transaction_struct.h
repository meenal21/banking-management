#ifndef TRANSACTION_STRUCT_H
#define TRANSACTION_STRUCT_H

struct Transaction{
	int tid;
	char trans_account[30];
	char corr_account[30];
	int open_balance;
	char action[2];
	int close_balance;
};

#endif 
