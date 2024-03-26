// Q3. Implement following classes. Test all functionalities in main() of each created class. Note that
// employee is inherited into manager and salesman.

#include<iostream>
using namespace std;

class Employee
{
    int id;
    double salary;

    public:
    Employee()
    {
        cout<<"ctor Employee"<<endl;
        id = 101;
        salary = 10000;
    }

    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    int getId()
    {
        return id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    double setSalary()
    {
        return salary;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    virtual void accept()
    {
        cout<<"Enter ID      : ";
        cin>>id;
        cout<<"Enter Salary : ";
        cin>>salary;
    }

    virtual void display()
    {
        cout<<endl;
        cout<<"Employee ID     : "<<id<<endl;
        cout<<"Employee SALARY : "<<salary<<endl;
    }

    virtual ~Employee()
    {
        cout<<"dtor ~Employee"<<endl;
    }

};

class Manager : virtual public Employee
{
    private:
    double bonus;

    protected:
    void acceptManager()
    {
        cout<<"Enter Bonus : ";
        cin>>bonus;
    }

    void displayManager()
    {
        cout<<"BONUS : "<<bonus<<endl;
    } 

    public:
    Manager()
    {
        cout<<"ctor Manager"<<endl;
        bonus = 1000;
    }

    Manager(int id, double salary, double bonus)
    {
        this->bonus = bonus;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return bonus;
    }

    void accept()
    {
        //accept();// OK 
        Employee::accept();
        acceptManager();      
    }

    void display()
    {
        //display();//OK 
        Employee::display();
        displayManager();
    }

    ~Manager()
    {
        cout<<"dtor ~Manager"<<endl;
    }
};

class Salesman : virtual public Employee
{
    private:
    double commission ;
    
    protected:
    void acceptSalesman()
    {
        cout<<"Enter commission : ";
        cin>>commission;
    }

    void displaySalesman()
    {
        cout<<"COMMISSION : "<<commission<<endl;
    } 

    public:
    Salesman()
    {
        cout<<"ctor Salesman"<<endl;
        commission = 500;
    }

    Salesman(int id, double salary, double commission)
    {
        this->commission = commission;
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return commission;
    }

    void accept()
    {
        Employee::accept();
        acceptSalesman();      
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }

    ~Salesman()
    {
        cout<<"dtor ~Salesman"<<endl;
    }

};

class SalesManager : public Manager, public Salesman
{
    public:

    SalesManager()
    {
        cout<<"ctor SalesManager"<<endl;
    }

    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout<<"Parameterized ctor SalesManager"<<endl;
    }

    void accept()
    {
        // Manager::accept();
        // Salesman::accept();
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display()
    {
        // Manager::display();
        // Salesman::display();
        Employee::display();
        displayManager();
        displaySalesman();
    }

    ~SalesManager()
    {
        cout<<"dtor ~SalesManager"<<endl;
    }

};


int main()
{
    //Employee *ptr = new Employee;
    //Employee *ptr = new Manager;
    //Employee *ptr = new Salesman;
    Employee *ptr = new SalesManager;
    ptr->accept();
    ptr->display();

    delete ptr;
    ptr = NULL;

    // //Employee obj;
    // //Manager obj;
    // //Salesman obj;
    // SalesManager obj;
    // obj.accept();
    // obj.display();


    return 0;
}