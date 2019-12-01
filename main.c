#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myBank.h"
int userNum = 0;
int main()
{
    static char transaction;
    int scanCheck=0;
    while(transaction!='E')
    {
        printf("\nPlease choose one of this actions: \n O - opening account\n B - balance updates\n D - deposit\n W - withdraw\n C - close account\n I - interest rate\n P - print all\n E - close all and leave\n ");
        scanCheck = scanf(" %c", &transaction);
        if(scanCheck!=1)
        {
            printf("Please enter the CHAR from the list");
            return 1;
        }
        else{
        switch(transaction)
        {
        case 'O':
            newBank();
            break;
        case 'B':
            printf("\nPlease enter your bank account:\n");
            scanCheck = scanf(" %d", &userNum);
            if(scanCheck!=1)
            {
                printf("Error with this account number");
                break;
            }
            else{
            balance(userNum);
            break;
            }
        case 'D':
        {
            printf("\nPlease enter your bank account:\n");
            scanCheck=scanf(" %d",&userNum);
            if(scanCheck!=1)
            {
                printf("Error with this bank account number");
                break;
            }
            else{
            deposit(userNum);
            break;
            }
        }
        case 'W':
            printf("\nPlease enter your bank account:\n");
            scanCheck=scanf(" %d",&userNum);
            if(scanCheck!=1)
            {
                printf("Error with userNum");
                break;
            }
            else{
            withdraw(userNum);
            break;
            }
        case 'C':
            printf("\nPlease enter your bank account:\n");
            scanCheck=scanf(" %d",&userNum);
            if(scanCheck!=1)
            {
                printf("Error with userNum");
                break;
            }
            else{
            closeAccount(userNum);
            break;
            }
        case 'I':
        {
            double rates = 0.0;
            printf("\nPlease enter your intrest RATE:\n");
            scanCheck=scanf(" %lf",&rates);
            if(scanCheck!=1||rates<0)
            {
                printf("Error with account number/your rate is negetive\n");
                break;
            }
            else{
            rate(rates);
            break;
            }
        }
        case 'P':
        {
            printAll();
            break;
        }
        case 'E':
            printf("Goodbye..");
            erase();
            break;
        }
        }
    }
    return 0;
}