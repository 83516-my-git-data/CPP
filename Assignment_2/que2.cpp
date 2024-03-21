// Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
// Mostly they do, but sometimes a car goes by without paying.
// The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
// collected. Model this tollbooth with a class called tollbooth.
// The two data items are a type unsigned int to hold the total number of cars, and a type double to
// hold the total amount of money collected.
// A constructor initializes all data members to 0. A member function called payingCar() increments
// the car total and adds 0.50 to the cash total. An other function, called nopayCar()
// increments the car total but adds nothing to the cash total. Finally, a member function called
// printOnConsole() displays the two totals and number of paying as well as non paying cars total.

#include<iostream>
using namespace std;

class tollbooth
{
    private:
    unsigned int totalPayCar ;
    unsigned int totalNoPayCar ;
    double totalAmt;

    public:

    tollbooth()
    {
        totalPayCar=0;
        totalNoPayCar=0;
        totalAmt=0;
    }

    void payingCar()
    {
        ++totalPayCar;
        totalAmt = totalAmt + 0.50 ;
    }

    void nopayCar()
    {
        ++totalNoPayCar;
    }

    void printOnConsole()
    {
        cout<<"The Total Number Of Paying Car : "<< totalPayCar <<endl;
        cout<<"The Total Ampont Of Money Collection : "<< totalAmt <<endl;
        cout<<"The Total Number Of Non-Paying Car : "<< totalNoPayCar <<endl<<endl;
    }

};

int main()
{
    int choice;
    tollbooth t;
    do
    {
        cout<<"Welcome to SunBeam Bridge ..."<<endl;
        cout<<"0. EXIT "<<endl;
        cout<<"1. To Pay Toll :)"<<endl;
        cout<<"2. To Not Pay Toll :( "<<endl;
        cout<<"3. To Check About ALL Toll paid & Non-paid Cars "<<endl;
        cout<<"ENTER YOUR CHOICE : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 0:
                cout<<"Thank You ..."<<endl;
            case 1:
                t.payingCar();
                break;

            case 2: 
                t.nopayCar();
                break;

            case 3: 
                t.printOnConsole();
                break;

            default:
                cout<<"Please Try Again...:)"<<endl<<endl;
                break;

        }

    }while(choice !=0 );

}