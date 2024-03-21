#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to represent an account
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Array to store all the accounts
struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function to create a new account
void createAccount() {
    struct Account newAccount;
    
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    
    accounts[numAccounts++] = newAccount;
    printf("Account created successfully.\n");
}

// Function to deposit money into an account
void deposit() {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdraw() {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully.\n");
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to check balance of an account
void checkBalance() {
    int accountNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;
    
    while(1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
