// Q1. Write a menu driven program to calculate volume of the box(length * width * height).
// Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
// Create the local objects in respective case and call the function to caluclate area.
// Menu options ->
// 1. Calculate Volume with default values
// 2. Calculate Volume with length,breadth and height with same value
// 3. Calculate Volume with different length,breadth and height values.

#include<iostream>
using namespace std;

class box
{
    private:
    int length;
    int width;
    int height;

    public:
    
    box()
    {
        length = 10;
        width = 6;
        height = 8;
    }

    box(int a)
    {
        length = a;
        width = a;
        height = a;

    }

    box( int lenght,int width,int height)
    {
        this->length = length ;
        this->width = width ;
        this->height = height ;
    }

    void printVolume()
    {
        cout<<"VOLUME : "<<(length*width*height)<<endl<<endl;
    }

};

int main()
{
    int choice;
    do
    {
        cout<<"0. EXIT "<<endl;
        cout<<"1. Calculate Volume with default values "<<endl;
        cout<<"2. Calculate Volume with length,breadth and height with same value "<<endl;
        cout<<"3. Calculate Volume with different length,breadth and height values "<<endl;
        cout<<"ENTER YOUR CHOICE : ";
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout<<"Thank You BYE BYE...."<<endl;
                break;

            case 1:
            {
                box b;
                b.printVolume();
            }
                break;

            case 2:
            {
                int value;
                cout<<"Enter value for calculate Volume : ";
                cin>>value;
                box b(value);
                b.printVolume();
            }
                break;

            case 3:
            {
                int length,width,height;
                cout<<"Enter Length : ";
                cin>>length;
                cout<<"Enter Width  : ";
                cin>>width;
                cout<<"Enter Height : ";
                cin>>height;
                box b(length,width,height);
                b.printVolume();
            }
                break;

            default:
                cout<<"Invalid....."<<endl<<endl;
                break;
        }

    }while(choice !=0 );

    return 0;
}