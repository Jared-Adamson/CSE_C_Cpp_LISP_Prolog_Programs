//P14 SalesPerson  -  Jared Adamson  
//Interface file - sales_person.h  - class definition

#ifndef SALES_PERSON_H
#define SALES_PERSON_H

#include <string>  // string class
using namespace std;


class SalesPerson
{
protected:
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
};                  //copy-and-paste your class definition over this outline.


#endif   // End of SALES_PERSON_H