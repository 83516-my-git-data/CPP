// Q1. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
// Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
// given, allocate stack of size 5.
// Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().

#include<iostream>
using namespace std;

class Stack
{
    private:
    int size;
    int index;
    int *ptr;

    public:
    Stack(int size)
    {
        this->size = size;
        index = -1;
        ptr = new int[size];
    }

    void push()
    {
        if(!isFull())
        {
            int element;
            cout<<"ENTER THE ELEMENT : ";
            cin>>element;
            ++index;
            ptr[index]=element; 
            cout<<"ELEMENT IS PUSH..."<<endl<<endl;
        }
        else
            cout<< "STACK OVERFLOW"<<endl<<endl;            

    }

    void pop()
    {
        if(!isEmpty())
        {
            --index;
            cout<<"ELEMENT IS POP..."<<endl<<endl;
        }
        else
            cout<<"STACK UNDERFLOW"<<endl<<endl;
    }

    int peek()
    {
        return ptr[index];
    }

    bool isEmpty()
    {
        return index == -1;
    }

    bool isFull()
    {
        return index == (size-1);
    }

    void print()
    {
        if(!isEmpty())
        {
            cout<<"ELEMENTS : ";
            for(int i=0; i<=index; i++)
            cout<<ptr[i]<<"\t";
            cout<<endl<<endl;
        }
        else
            cout<<"STACK IS EMPTY...."<<endl<<endl;
    }

    ~Stack()
    {
        delete[] ptr;
        ptr =  NULL;
    }

};

int main()
{
    int s;
    cout<<"Enter Size of Stack : ";
    cin>>s;
    Stack s1(s);
    int choice;
    do
    {
        cout<<"0. EXIT"<<endl;
        cout<<"1. TO INSERT ELEMENT"<<endl;
        cout<<"2. TO DELETE ELEMENT"<<endl;
        cout<<"3. TO SEE CURRENT ELEMENT"<<endl;
        cout<<"4. TO SEE ALL ELEMENTS OF STACK"<<endl;
        cout<<endl<<"Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout<<"THANK YOU ....."<<endl;
                break;
            case 1:
                s1.push();
                break;

            case 2:
                s1.pop();
                break;

            case 3:
                cout<<"Element : "<<s1.peek()<<endl<<endl;
                break;

            case 4:
                s1.print();
                break;

            default:
                cout<<"Invalid..."<<endl<<endl;
                break;
        }

    } while (choice!=0);
    
    return 0;
}