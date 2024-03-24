// Q3. Write a class Address with data members (string building, string street, string city ,int pin)
// Implement constructors, getters, setters, accept(), and display() methods.
// Test the class functunalities by creating the object of class and calling all the functions.

#include<iostream>
using namespace std;

class Address
{
    private:
    string building;
    string street;
    string city;
    int pin;

    public:
    // Constructors
    Address()
    {
        building = "203, Anuda Chambers";
        street = "Shaniwar Peth, near Gujar Hospital";
        city = "Karad";
        pin = 415110;
    }
    Address(string building, string street, string city, int pin)
    {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }   

    // Setter
    void setBuilding(string b)
    {
        building = b;
    }
    void setStreet(string s)
    {
        street = s;
    }
    void setCity(string c)
    {
        city = c;
    }
    void setPin(int p)
    {
        pin = p;
    }

    // Getter
    string getBuilding() const
    {
        return building;
    }
    string getStreet() const
    {
        return street;
    }
    string getCity() const
    {
        return city;
    }
    int getPin() const
    {
        return pin;
    }

    // Accept()
    void acceptAddress()
    {
        cout<<"Enter Name of Building : ";
        cin>>building;
        cout<<"Enter Name of Street : ";
        cin>>street;
        cout<<"Enter Name of City : ";
        cin>>city;
        cout<<"Enter Pin Code : ";
        cin>>pin;
    }   

    // Display()
    void displayAddress()
    {
        cout<< building <<", ";
        cout<< street <<", ";
        cout<< city <<", ";
        cout<< pin <<endl<<endl;
    }

};

int main()
{
    Address a;
    a.displayAddress();
    Address b("Shakuntala","Urjanagar Road","chandrapur",442404);
    b.displayAddress();
    a.acceptAddress();
    a.displayAddress();
    a.setBuilding("201,Aayushman");
    cout<<a.getBuilding()<<endl;
    a.setStreet("Gndhi nagar road");
    cout<<a.getStreet()<<endl;
    a.setCity("Chandrapur");
    cout<<a.getCity()<<endl;
    a.setPin(442404);
    cout<<a.getPin()<<endl;
    a.displayAddress();

    return 0;
}