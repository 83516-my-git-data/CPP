// Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
// should be menu driven and should not cause memory leakage.
// Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]

#include<iostream>
using namespace std;


class Product
{
    protected:
    int id;
    string title;
    double price;

    public:
    virtual void accept()
    {
        cout<<"Enter ID    : ";
        cin>>id;
        cout<<"Enter Title : ";
        cin>>title;
        cout<<"Enter Price : ";
        cin>>price;
    }

     double getPrice()
    {
        return price;
    }

    virtual void display()
    {
        cout<<"Product ID    : "<<id<<endl;
        cout<<"Product TITLE : "<<title<<endl;
        cout<<"PRODUCT PRICE : "<<price<<endl;
       // cout<<endl;
    }

};

class Book : public Product
{
    private:
    string author;

    public:
    void accept()
    {
        cout<<"Enter Author Name : ";
        cin>>author;
        Product::accept();
        this->setPrice();
    }

    void setPrice()
    {
        price = (price - 0.1*price);
    }

    virtual void display()
    {
        cout<<endl;
        cout<<"Author Name : "<<author<<endl;
        Product::display();
        Book::getPrice();
        cout<<endl;
    }

};

class Tape : public Product
{
    string artist;
    void accept()
    {
        cout<<"Enter Artist Name : ";
        cin>>artist;
        Product::accept();
        this->setPrice();
    }

    void setPrice()
    {
        price = (price - 0.05*price);
    }

    virtual void display()
    {
        cout<<endl;
        cout<<"Artist Name : "<<artist<<endl;
        Product::display();
        Tape::getPrice();
        cout<<endl;
    }
};

int main()
{
Product *arr[3];
Product *p = NULL;
int choice; 
int index = 0;
double finalbill;

do
{
    cout<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. To Puchase Book "<<endl;
    cout<<"2. To Purchase Tape "<<endl;
    cout<<"3. Your Purchase List "<<endl;
    cout<<"4. YOUR FINAL BILL"<<endl;
    cout<<"ENTER YOUR CHOICE : ";
    cin>>choice;

    switch(choice)
    {
        case 0: 
            cout<<"THANK YOU...."<<endl;
            break;
        case 1:
            p = new Book();
            break;
        case 2:
            p = new Tape();
            break;
        case 3:
            for (int i = 0; i < index; i++)
                arr[i]->display();
            break;
        case 4:
            finalbill =0;
            for (int i = 0; i < index; i++)
                finalbill=finalbill+arr[i]->getPrice();
            cout<<"FINAL PAYEMNT BILL : "<<finalbill<<endl;     
            cout<<endl;
            break;
        default:
            cout<<"WRONG CHOICE...."<<endl;
            break;
    }
        if (p != NULL)
        {
            if (index < 3)
            {
                p->accept();
                arr[index] = p;
                index++;
                p = NULL;
            }
            else
            {
                cout << "YOUR PURCHASE LIMIT IS FULL..." << endl;
                delete p;
                p = NULL;
            }
        }    

    
}while(choice != 0);

return 0;

}