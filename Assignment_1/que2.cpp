// Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
// Date is having data members day, month, year. Implement the following functions.
// void initDate();
// void printDateOnConsole();
// void acceptDateFromConsole();
// bool isLeapYear();

#include<iostream>
using namespace std;

class Date
{
    private:
    int day;
    int month;
    int year;

    public:

    void initDate()
    {
        day = 19;
        month = 03;
        year = 24;
        cout << day << "-"<< month <<"-"<< year << endl<<endl;

    }

    void acceptDateFromConsole()
    {
        cout << "Enter Day   :: " ;
        cin >> day ;
        cout << "Enter Month :: " ;
        cin >> month ;
        cout << "Enter Year  :: " ;
        cin >> year ;
    }

    void printDateOnConsole()
    {
        cout <<"DATE : "<< day <<"-"<< month <<"-"<< year<<endl<<endl;
    }

    bool isLeapYear()
    {
        if(year%4)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }

};

int main()
{
    Date d;
    int choice;
    bool a;
    d.initDate();
    do
    {
        cout<<"0.Exit "<<endl;
        cout<<"1.To Enter Date "<<endl;
        cout<<"2.To display Date "<<endl;
        cout<<"3.To check Leap year or not "<<endl;
        cout<<"Enter your Choice : "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 0:
            cout<<"BYE BYE..."<<endl;
            break;

        case 1:
            d.acceptDateFromConsole();
            break;

        case 2:
            d.printDateOnConsole();
            break;

        case 3:
            a = d.isLeapYear();
            if(a)
                printf("NON_LEAP_YEAR \n\n");
            else
                printf("LEAP_YEAR \n\n");
            break;

        default:
            cout<<"Check your Choice..."<<endl<<endl;
            break;
        }

    }while(choice!=0);
    return 0;
}