// Q1. Implement following classes. Test all functionalities in main().
// Create a class Date with data memebrs day,month and year.
// Create a class Person with data members name,address and birthdate. The birthdate shoud be of
// type date.
// Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
// be of type date.

#include<iostream>
using namespace std;

class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    Date()
    {
        day = 21;
        month = 8;
        year = 2001;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout<<"Enter Day   : ";
        cin>>day;
        cout<<"Enter Month : ";
        cin>>month;
        cout<<"Enter Year  : ";
        cin>>year;
    }

    void displayDate()
    {
        cout<<day<<"-"<<month<<"-"<<year<<endl;
    }
    
};

class Person
{
    private:
    string name;
    string address;
    Date birthdate;

    public:
    Person()
    {
        name = "Sahil";
        address = "Chandrapur";
    }    

    Person(string name, string address, int day, int month, int year):birthdate(day,month,year)
    {
        this->name = name;
        this->address = address;
    }

    void acceptPerson()
    {
        cout<<"Personal Information"<<endl;
        cout<<"Enter Name    : ";
        cin>>name;
        cout<<"Enter Address : ";
        cin>>address;
        cout<<"Birthdate Information"<<endl;
        birthdate.acceptDate();
    }

    void displayPerson()
    {
        cout<<endl;
        cout<<"PERSON NAME = "<<name<<endl;
        cout<<"ADDRESS     = "<<address<<endl;
        cout<<"BIRTHDATE   = ";
        birthdate.displayDate();
    }
};

class Employee
{
    private:
    int id;
    string dept;
    double salary;
    Date joinDate;

    public:
    Employee()
    {
        id = 101;
        dept = "Manufacturing";
        salary = 10000;
    }

    Employee(int id, string dept, double salary, int day, int month, int year):joinDate(day,month,year)
    {
        this->id = id;
        this->dept = dept;
        this->salary = salary;
    }

    void acceptEmployee()
    {
        cout<<"Employee Information"<<endl;
        cout<<"Enter ID         : ";
        cin>>id;
        cout<<"Enter Department : ";
        cin>>dept;
        cout<<"Enter Salary     : ";
        cin>>salary;
        cout<<"Joining Date Information"<<endl;
        joinDate.acceptDate();
    }

    void displayEmployee()
    {
        cout<<endl;
        cout<<"EMPLOYEE Id     = "<<id<<endl;
        cout<<"DEPARTMENT      = "<<dept<<endl;
        cout<<"EMPLOYEE SALARY = "<<salary<<"/-"<<endl;
        cout<<"JOINING DATE    = ";
        joinDate.displayDate();
    }
};

int main()
{
    Person p;
    Employee e;
    p.acceptPerson(); 
    e.acceptEmployee();
    p.displayPerson();
    e.displayEmployee();

    return 0;
}