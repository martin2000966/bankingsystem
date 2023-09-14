#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "STD_TYPES.H"

typedef struct Account Account;

struct Account{
    u8 fullName[50];
    u8 adress[50];
    u8 age;
    u8 password[16];
    u8 guardFlag;
    u8 accountStatus ;  //if 1: activate  if 2:restricted   if 3:closed

    u32 bankID;

    f64 balance;
    
    u64 guardNationalID;
    u64 nationalID;

    Account *next;

};

void setFirstTime(Account *myAcc);
void createAccount();
// void printAccount(Account *myAcc);
// void deleteAccount(u32 AbankID);
Account *getAccountByID(u32 argID);         // returns a pointer to the object . if not fount returns NULL

void makeTransaction(u32 senderID ,u32 recieverID ,f64 amount);

void setAccStatus (Account *myAcc);

void getCash(Account *myAcc);

void deposit (Account *myAcc);


#endif