#include <stdio.h>
#ifndef MYBANK_H_
#define _MYBANK_H_
#define COLM 50
#define ROWS 2
extern double arr[ROWS][COLM];
int newBank(); //open new account
int balance(int accountNumber); // check balance
int deposit(int accountNumber);//get deposit
int withdraw(int accountNumber);//withdraw 
int closeAccount(int accountNumber);//close the spesipec account
int rate(double rate);//insert rate for all accounts
int printAll();//print
int erase();
#endif