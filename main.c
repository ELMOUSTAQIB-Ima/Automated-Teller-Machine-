#include <stdio.h>// this is the header file for input and out or compilation
#include <stdlib.h>
#include <windows.h>
#include <time.h>


//then initialize variables named

int amountToWithdrawal;
int amountToDeposit;
int anotherTransaction;
//balance is point because rupees have some point value so it is the float
float balance=0; //it is initially zero for every run first time

//main method

int main()
{
    system("color 3F");
    int pin=1234,enteredPin,count=0;
    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t   %s",ctime(&now));
    printf("\t\t\t\t\t============*Welecome to ATM*============");
    while(pin != enteredPin)
    {
        printf("\nPlease enter you pin: ");
        scanf("%d",&enteredPin);
        if(enteredPin != pin)
        {
            Beep(610,500);
            printf("Invalid pin!!!");
        }
        if(count == 3 && pin != enteredPin)
        {
            exit(0);
        }

    }



    //now the time to run the program simply call the transaction function
    transaction();//now compile
}
//a function which named transaction
void transaction()
{
    //menu for the user create driven program
    int choice;
    printf("Enter any One option to be served! \n\n");
    printf("01) withdrawal of the Money\n");
    printf("02) Deposit the Money\n");
    printf("03) Account balance ");
    scanf("%d",&choice);
    //now make switch statements
    switch(choice)
    {
        //first case is for Withdrawal
       case 1:
           printf("Please enter amount to Withdrawal: ");
           scanf("%d",&amountToWithdrawal);
           //to check account
           if(amountToWithdrawal > balance)
           {
               printf("There is no insufficient balance in your account");
               //ask for another transaction
               printf("\n\n Do you want Another Transaction?\n Press 1 to proceed 2 for EXIT\n");
               scanf("%d",&anotherTransaction);
               if( anotherTransaction == 1)
               {
                   //call transaction method
                   transaction();
               }
           }
            else
            {
                   //if account have some balance/money so the process is :
                   balance = balance - amountToWithdrawal;//initialize the balance variable
                   printf("You have Withdrawal %d and your new balance is %f",amountToWithdrawal,balance);
                   //request for another transaction
                    printf("\n\n Do you want Another Transaction?\n Press 1 to proceed 2 for EXIT\n");
                    scanf("%d",&anotherTransaction);
                    if( anotherTransaction == 1)
                    {
                       //call transaction method
                       transaction();
                    }
            }
            break;//for jump the case
        case 2:
            //for deposit
            printf("Please Enter Amount to Deposit: ");
            scanf("%d",&amountToDeposit);
            //if you deposit amount so its add in your balance variable so:
            balance = amountToDeposit + balance;
            printf("Thank You for depositing, Your New balance is : %f",balance);

            // ask user for another transaction
            printf("\n\n Do you want Another Transaction?\n Press 1 to proceed 2 for EXIT\n");
            scanf("%d",&anotherTransaction);
            if( anotherTransaction == 1)
            {
                //call transaction method
                transaction();
            }
            break;

            //now final option case for balance
        case 3:
            printf("Your Bank Balance is : %f",balance);

            //request for another transaction
            printf("\n\n Do you want Another Transaction?\n Press 1 to proceed 2 for EXIT\n");
            scanf("%d",&anotherTransaction);
            if( anotherTransaction == 1)
            {
                //call transaction method
                transaction();
            }
            break;
    }

}
