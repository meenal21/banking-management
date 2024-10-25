#ifndef LOAN_H
#define LOAN_H

struct Loan{
	int lid;
	int cid;
	int mid;
	int eid;
	bool assigned;
	bool rejected;
	bool approved;
	int amount;
};

#endif
