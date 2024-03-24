// Q2. Write a class for Time and provide the functionality
// Time()
// Time(int h,int m,int s)
// getHour()
// getMinute()
// getSeconds()
// printTime()
// setHour()
// setMinute()
// setSeconds()
// Allocate the memory for the the object dynamically and test the functunalities using time ptr.

#include<iostream>
using namespace std;

class Time
{
    private:
    int hr;
    int min;
    int sec;

    public:
    Time()
    {
        hr  = 11;
        min = 28;
        sec = 33;
    }

    Time(int h,int m,int s)
    {
        hr  = h;
        min = m;
        sec = s; 
    }

    int getHour()
    {
        return hr;
    }

    int getMinute()
    {
        return min;
    }

    int getSeconds()
    {
        return sec;
    }

    void printTime()
    {
        cout<<"Time : "<<hr<<"-"<<min<<"-"<<sec<<endl<<endl;
    }

    void setHour(int h)
    {
        hr = h;
    }

    void setMinute(int m)
    {
        min = m;
    }

    void setSeconds(int s)
    {
        sec = s;
    }

};
 
int main()
{
    Time *t1 = new Time; 
    t1->printTime();


    Time *t2 = new Time(10, 28, 33);
    t2->printTime();

    cout<<"Hr  : "<<t2->getHour()<<", set Hr  : 11"<<endl;
    t2->setHour(11);

    cout<<"Min : "<<t2->getMinute()<<", set Min : 36"<<endl;
    t2->setMinute(36);

    cout<<"Sec : "<<t2->getSeconds()<<", set Sec : 52"<<endl<<endl;
    t2->setSeconds(52);

    t2->printTime();

    delete t1;
    delete t2;
    
    t1 = NULL;
    t2 = NULL;

    return 0;
}