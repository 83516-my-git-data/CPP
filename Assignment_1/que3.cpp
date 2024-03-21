// Q3. Write a menu driven program for Student in CPP language. Create a class student with data
// members roll no, name and marks. Implement the following functions
// void initStudent();
// void printStudentOnConsole();
// void acceptStudentFromConsole();

#include<iostream>
using namespace std;

class student
{
    private:
    int rollno;
    string name;
    double marks;

    public:
    void initStudent()
    {
        rollno = 21;
        name = "Soham";
        marks = 85;
        cout<<"ROLLNO : "<<rollno<<endl;
        cout<<"NAME   : "<<name<<endl;
        cout<<"MARKS  : "<<marks<<endl<<endl;
    }

    void printStudentOnConsole()
    {
        cout<<"ROLLNO : "<<rollno<<endl;
        cout<<"NAME   : "<<name<<endl;
        cout<<"MARKS  : "<<marks<<endl<<endl;
    }

    void acceptStudentFromConsole()
    {
        cout<<"Enter ROLLNO : ";
        cin>>rollno;
        cout<<"Enter NAME   : ";
        cin>>name;
        cout<<"Enter MARKS  : ";
        cin>>marks;
    }
    
};

int main()
{
    student s;
    int choice;
    s.initStudent();
    do
    {
        cout<<"0.Exit"<<endl;
        cout<<"1.Enter the Student Date "<<endl;
        cout<<"2.Displya the Student Data "<<endl;
        cout<<"Enter your Choice : "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"BYE BYE...."<<endl;
                break;

            case 1:   
                s.acceptStudentFromConsole();
                break;

            case 2:
                s.printStudentOnConsole();
                break;

            default:
                cout<<"Invalid...."<<endl;
                break;
        }
    }while(choice!=0);

    return 0;
}