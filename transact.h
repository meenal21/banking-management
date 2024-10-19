#ifndef TRANSACT_H
#define TRANSACT_H


#include "commonheader.h"
#include "customer_struct.h"
#include "transaction_struct.h"
#include "placeholder.h"
#include "getcounter.h"

int deposit(struct Customer *trans_account, const char *corr_account,int amount){
    struct Transaction trans;
    struct Customer cust;
    int open_bal, close_bal;

    char const *tfile = "tid.txt";
    int tid;
    tid = getcounter(tfile, "Transaction");
    
    trans.tid = tid;
    // for now putting the account as name, alter as email
    strcpy(trans.trans_account, trans_account->name);
    strcpy(trans.corr_account, corr_account);
    trans.open_balance = trans_account->balance;
    trans.close_balance = trans.open_balance + amount;
    strcpy(trans.action,CREDIT);

    int fd;
    ssize_t bytes_writ;
    fd = open("transaction_logs.txt",O_CREAT|O_WRONLY|O_APPEND, 0644);
    if(fd < 0){
        perror("Error Opening the Transaction Logs!");
        return -1;
    }
    bytes_writ = write(fd, &trans, sizeof(struct Transaction));
    if(bytes_writ < 0){
        perror("Error Writing to the Transaction Logs!");
        close(fd);
        return -1;
    }
    printf("Transaction has been updated");
    close(fd);
    return 1;
}

int withdraw(struct Customer *trans_account, const char *corr_account,int amount){
    struct Transaction trans;
    struct Customer cust;
    int open_bal, close_bal;

    char const *tfile = "tid.txt";
    int tid;
    tid = getcounter(tfile, "Transaction");
    
    trans.tid = tid;
    // for now putting the account as name, alter as email
    strcpy(trans.trans_account, trans_account->name);
    strcpy(trans.corr_account, corr_account);
    trans.open_balance = trans_account->balance;
    trans.close_balance = trans.open_balance - amount;
    strcpy(trans.action,DEBIT);

    int fd;
    ssize_t bytes_writ;
    fd = open("transaction_logs.txt",O_CREAT|O_WRONLY|O_APPEND, 0644);
    if(fd < 0){
        perror("Error Opening the Transaction Logs!");
        return -1;
    }
    bytes_writ = write(fd, &trans, sizeof(struct Transaction));
    if(bytes_writ < 0){
        perror("Error Writing to the Transaction Logs!");
        close(fd);
        return -1;
    }
    printf("Transaction has been updated");
    close(fd);
    return 1;
}

int send_money(struct Customer *sender, struct Customer *receiver, int send_amount){

    if(sender->balance  < send_amount){
        printf("Insufficient funds!");
        return -1;
    }

    if(deposit(receiver, sender->name, send_amount)== -1){
        perror("Deposit Issue!");
        return -1;
    }
    if(withdraw(sender, receiver->name, send_amount)== -1){
        perror("Withdraw issue!");
        return -1;
    }

    return 1;
}

#endif