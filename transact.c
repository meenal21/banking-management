#include "commonheader.h"
#include "customer_struct.h"
#include "customer.h"
#include "transaction_struct.h"
#include "placeholder.h"
#include "getcounter.h"
#include "transact.h"


struct Transaction* add_transaction(struct Transaction *transaction, int *count) {
    // Resize the array to hold one more Transaction
    struct Transaction *new_transactions = realloc(transaction, (*count + 1) * sizeof(struct Transaction));
    if (new_transactions == NULL) {
        perror("Failed to allocate memory");
        return transaction; // Return old pointer if realloc fails
    }

    transaction = new_transactions; // Update pointer to the new array
    (*count)++; // Increment the transaction count
    return transaction; // Return the updated pointer
}
int main(){
    /*
    struct Customer trans_account;
    struct Transaction trans;
    int amount;
    off_t offset;
    char *corr_account = "mrunmayi.shirke@gmail.com";
    // for struct - read the customer
    if(read_customer(&trans_account,3) < 0){
        perror("Unable to fetch Customer Details");
        return -1;
    }
    amount = 500;
    //strcpy(corr_account,"mrunmayi@gmail.com");
    //printf("Customer Pointer: %p\n", (void*)&trans_account);
    printf("%d \n", deposit(&trans_account, corr_account, amount));
    printf("%d \n", withdraw(&trans_account, corr_account, amount));

    //send money
    /*
    We need struct 1 - sending money - struct 2 - receive money - show 2 transactions
    // 7 for Jyoti, 6 for Prashant
    */

    /*
    struct Customer sender;
    struct Customer receiver;

    
    if(read_customer(&sender,7) < 0){
        perror("Unable to fetch Sender Details");
        return -1;
    }
    /*
    if(read_customer(&receiver,6) < 0){
        perror("Unable to fetch Receiver Details/Receiver doesn't exist!");
        return -1;
    }

    int send_amount;
    send_amount = 9000;

    printf("%d \n", send_money(&sender, &receiver, send_amount));
    /*
    if(sender.balance  < send){
        printf("Insufficient funds!");
        return -1;
    }

    if(deposit(&receiver, sender.name, send)== -1){
        perror("Deposit Issue!");
        return -1;
    }
    if(withdraw(&sender, receiver.name, send)== -1){
        perror("Withdraw issue!");
    }

    */

    struct Customer sender;
    //struct Customer receiver;

    if(read_customer(&sender,7) < 0){
        perror("Unable to fetch Sender Details");
        return -1;
    }

    int fd;
    struct Transaction trans;
    ssize_t bytes_read;
    fd = open("transaction_logs.txt",O_RDONLY, 0644);
    if(fd < 0){
        perror("Error Opening the Transaction Logs!");
        return -1;
    }
    int count = 0;
    while(bytes_read = read(fd, &trans, sizeof(struct Transaction))){
        if (trans.trans_account == sender.name) {
            //*cust = temp_cust;
            printf("The transaction was a %s \n for amount %d \n", trans.action, trans.open_balance);
            // Return the found customer
            count += 1;
        }
    }
    close(fd);


    return 1;
}