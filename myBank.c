#define _CRT_SECURE_NO_WARNINGS
#include "myBank.h"
#include <stdio.h>
#define COLM 50
#define ROWS 2
#define START_ACC 901
#define FINAL_ACC 950
double arr[ROWS][COLM]={0};
//0 is closed, 1 is opened.
int newBank()
{
    double amount=0;
    int scanCheck=0;
    int flag =0;
    for(int i=0;i<COLM;i++)
    {
        if(arr[0][i]==0)
        {
            printf("\nInitial deposit: \n");
            scanCheck = scanf(" %lf",&amount);
            if(scanCheck!=1)
            {
                printf("Invalid value was enter! please try again");
                return 0;
            }
            arr[0][i]=1;
            flag =1;
            amount=amount*100;
            amount=(int)amount;
            amount=amount/100;
            arr[1][i] += amount;
            printf("\nYour new account number is: %d ", i+START_ACC);
            printf("\n");
            i=51;
        }
    }
    if(flag==0)
        {
            printf("Sorry..there is already 50 bank accounts exited");
        }
    return 0;
}
int balance(int accountNumber)
{
    int userNum=accountNumber;
    float balanceUpdate=0;
    if(userNum>FINAL_ACC||userNum<START_ACC)
    {
        printf("Please check your bank account number!");
    }
    else if(arr[0][userNum-START_ACC]!=1)
    {
        printf("This account number is NOT open!");
    }
    else
    {
        balanceUpdate = arr[1][userNum-START_ACC];
        printf("Your updated balance is : %.2f ",balanceUpdate);
    }
    return 0;
}
int deposit(int accountNumber)
{
    int userAcc=accountNumber;
    double amounts=0;
    int scanCheck=0;
    if(userAcc>FINAL_ACC||userAcc<START_ACC)
    {
        printf("Please check your bank account number!");
    }
    else if(arr[0][userAcc-START_ACC]!=1)
    {
        printf("This account number is NOT open!");
    }
    else
    {
        printf("\nAmount to deposit: \n");
        scanCheck=scanf(" %lf",&amounts);
        if(scanCheck!=1||amounts<0)
        {
            printf("Error with the amount!");
            return 1;
        }
        arr[1][userAcc-START_ACC] = arr[1][userAcc-START_ACC] + amounts;
        printf("\nYour new balance is: %f", arr[1][userAcc-START_ACC]);
        printf("\n");
    }
    return 0;
}
int withdraw(int accountNumber)
{
    int userAccount =accountNumber;
    double withdraw=0;
    int scanCheck=0;
    if(userAccount>FINAL_ACC||userAccount<START_ACC)
    {
        printf("Please check your bank account number!");
    }
    else if(arr[0][userAccount-START_ACC]!=1)
    {
        printf("This account numbere is NOT opend!");
    }
    else
    {
        printf("Amount to withdraw: \n");
        scanCheck=scanf(" %lf", &withdraw);
        if(scanCheck!=1)
        {
            printf("Error with the amount!");
            return 1;
        }
        if(withdraw>arr[1][userAccount-START_ACC])
        {
            printf("CANNOT withdraw more than your balance!");
        }
        else
        {
            arr[1][userAccount-START_ACC]=arr[1][userAccount-START_ACC] - withdraw;
            printf("Your balance after the withdraw is : %.2f",arr[1][userAccount-START_ACC]);
        }

    }
    return 0;
}
int closeAccount(int accountNumber)
{
    int accountNum=accountNumber;
    if(accountNum>FINAL_ACC||accountNum<START_ACC)
    {
        printf("Please check your bank account number!");
    }
    else if(arr[0][accountNum-START_ACC]==1)
    {
        arr[0][accountNum-START_ACC]=0;
        arr[1][accountNum-START_ACC]=0;
        printf("This account CLOSED NOW\n");
    }
    else
    {
        printf("This account number is already CLOSED!");
    }
    return 0;
}
int rate(double rates)
{
    double rate=rates;
    for(int i=0;i<COLM;i++)
    {
        double temp=0;
        if(arr[0][i]==1)
        {
            temp=arr[1][i]*rate;
            temp=temp/100;
            arr[1][i]=arr[1][i]+temp;
            i=50;
        }
    }
    return 0;
}
int printAll()
{
    for(int i=0;i<COLM;i++)
    {
        if(arr[0][i]==1)
        {
            printf("Account that opened: %d", i+START_ACC);
            printf(" ,balance: %.2f\n",arr[1][i]);
        }
    }
    return 0;
}
int erase()
{
    //static i;
    for(int i=0;i<COLM;i++)
    {
        if(arr[0][i]==1)
        {
            arr[0][i]=0;
            arr[1][i]=0;
            break;
        }
    }
    return 0;
}