#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTONS 10

//structure to store transaction details
typedef struct {
    char type[10]; //Deposite or withdraw
    float amount;
} Transaction;

//structure to store account details
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
    Transaction
    Transactions[MAX_TRANSACTONS];
    int transactionCount;
}Account;

//Global array to store all accounts
Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

//Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void displayAccountDetails();
void generateMiniStatement();
void menu();

int main(){
    menu();
    return 0;
}

//Display menu
void menu(){
    int choice;
    do {
        printf("\n---Bank Account Management System ---\n*");
        printf("*1. Create New Account\n");
        printf("*2. Deposit Money\n");
        printf("*3. Withdraw Money\n");
        printf("*4. Display Account Details\n");
        printf("*5. Generate Mini Statement\n");
        printf("*6. Exit\n");
        printf("Enter Your choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            createAccount();
            break;
            case 2:
            depositMoney();
            break;
            case 3:
            withdrawMoney();
            break;
            case 4:
            displayAccountDetails();
            break;
            case 5:
            generateMiniStatement();
            break;
            case 6:
            printf("Exiting the system. Thank you!\n");
            break;
            default:
            printf("Invalid choice! please try again.\n");
        }
    }while(choice!= 6);
}

//Create a new account
void createAccount(){
    if(accountCount >= MAX_ACCOUNTS){
        printf("Maximum account limit reached.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber=accountCount+1;
    printf("Enter your name:");
    scanf("%[^\n]",newAccount.name);
    newAccount.balance = 0.0;
    newAccount.transactionCount = 0;
    
    accounts[accountCount]=newAccount;
    accountCount++;
    printf("Account created successfully!Your account number is %d\n",newAccount.accountNumber);
}

//Deposite money
void depositMoney(){
    int accNum;
    float amount;
    printf("Enter account number:");
    scanf("%d",&accNum);
    
    if(accNum < 1|| accNum > accountCount){
        printf("Invalid account number:\n");
        return;
    }
    
    Account * acc = &accounts[accNum - 1];
    printf("Enter amount to deposit:");
    scanf("%f",&amount);
    
    if(amount<=0){
        printf("Invalid amount.\n");
        return;
    }
    
    acc->balance+=amount;
    
    //Record transaction
    if(acc->transactionCount < MAX_TRANSACTONS){
        
        strcpy(acc->Transactions[acc->transactionCount].type,"Deposit");
        
        acc->Transactions[acc->transactionCount].amount=amount;
        acc->transactionCount++;
    }
    
    printf("Amount deposite successfully!Current balance:%2f\n",acc->balance);
}

//Withdraw money
void withdrawMoney(){
    int accNum;
    float amount;
    printf("Enter account number:");
    scanf("%d",&accNum);
    
    if(accNum < 1||accNum > accountCount){
        printf("Invalid account number.\n");
        return;
    }
    
    Account*acc=&accounts[accNum-1];
    printf("Enter amount to withdraw:");
    scanf("%f",&amount);
    
    if(amount<=0||amount>acc->balance){
        printf("Invalid amount or insufficient balance.\n");
        return;
    }
    
    acc->balance-=amount;
    
    //Record transaction
    if(acc->transactionCount < MAX_TRANSACTONS){
        
        strcpy(acc->Transactions[acc->transactionCount].type,"Withdraw");
        
        acc->Transactions[acc->transactionCount].amount=amount;
        acc->transactionCount++;
    }
    
    printf("Amount withdrawn successfully!Current balance:%2f\n",acc->balance);
}

//Display account details
void displayAccountDetails(){
    int accNum;
    printf("Enter account number:");
    scanf("%d",&accNum);
    
    if(accNum < 1||accNum > accountCount){
        printf("Invalid account number.\n");
        return;
    }
    
    Account*acc=&accounts[accNum -1];
    printf("\n---Account Details---\n");
    printf("Account Number:%d\n",acc->accountNumber);
    printf("Name:%s\n",acc->name);
    printf("Balance:%2f\n",acc->balance);
}

//Generate mini statement
void generateMiniStatement(){
    int accNum;
    printf("Enter account number:");
    scanf("%d",&accNum);
    
    if(accNum < 1 || accNum > accountCount){
        printf("Invalid account number.\n");
        return;
    }
    
    Account*acc=&accounts[accNum-1];
    printf("\n---Mini Statement---\n");
    printf("account Number:%d\n",acc->accountNumber);
    printf("Name:%s\n",acc->name);
    printf("Balance:%2f\n",acc->balance);
    printf("Recent Transactions:\n");
    
    for(int i=0; i<acc->transactionCount; i++){
        printf("%s:%.2f\n",acc->Transactions[i].type,acc->Transactions[i].amount);
    }
    
    if(acc->transactionCount == 0){
        printf("No transactions available.\n");
    }
}