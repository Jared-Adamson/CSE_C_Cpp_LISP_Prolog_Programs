//P11 SalesPerson class - Jared Adamson

#include <string>   // string class
using namespace std;


//Class definition -  the interface for the class

class SalesPerson
{
private:
//private member variables require accessors
     int salesPersonId;
     string firstName;
     string lastName; 

public: 
//default constructor - will call input functions
    SalesPerson();

//overloaded constructor - will assign parameter values to private variables
    SalesPerson(int id, string fn, string ln);

//destructor
    ~SalesPerson();

//accessors
    void setSalesPersonId(int id);
    void setFirstName(string fn);
    void setLastName(string ln);

    int getSalesPersonId( );
    string getFirstName( );
    string getLastName( ); 

    void inputSalesPersonId( );
    void inputFirstName( );
    void inputLastName( ) ;



};



//Need empty main so program will compile 
void main()
{
    return;
}