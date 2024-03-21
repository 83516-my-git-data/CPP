// Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
// day, month, year. Implement the following functions.
// void initDate(struct Date* ptrDate);
// void printDateOnConsole(struct Date* ptrDate);
// void acceptDateFromConsole(struct Date* ptrDate);


#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;

};

void initDate(struct Date* ptrDate)
{
    ptrDate->day   = 19;
    ptrDate->month = 03;
    ptrDate->year  = 2024;
    printf("%d-%d-%d \n\n",ptrDate->day,ptrDate->month,ptrDate->year);

}

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Enter Day   : ");
    scanf("%d",&ptrDate->day);
    printf("Enter Month : ");
    scanf("%d",&ptrDate->month);
    printf("Enter Year  : ");
    scanf("%d",&ptrDate->year);

}

void printDateOnConsole(struct Date* ptrDate)
{
    printf("%d-%d-%d \n\n",ptrDate->day, ptrDate->month, ptrDate->year);
}

int main()
{
    struct Date d;
    int choice;
    initDate(&d);
    do
    {
        printf("0.Exit\n");
        printf("1.To Enter Date\n");
        printf("2.To Display Date\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            printf("BYE BYE....");
            break;

        case 1:
            acceptDateFromConsole(&d);
            break;

        case 2:    
            printDateOnConsole(&d);
            break;

        default:
            printf("Invalid choice....");
            break;

        }

    }while(choice!=0);

    return 0;
}