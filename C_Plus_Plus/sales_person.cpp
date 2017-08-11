//P14 SalesPerson  -  Jared Adamson
//Implementation file - sales_person.cpp - function defintions


#include <iostream>        // cout and cin
#include "sales_person.h"  // SalesPerson

using namespace std;


//Functions for class SalesPerson include:


SalesPerson::SalesPerson()
	{
    inputSalesPersonId( );
     inputFirstName( );
     inputLastName( ) ;
}  
SalesPerson::SalesPerson(int id, string fn, string ln)
	{
     salesPersonId = id;
     firstName = fn;
     lastName  = ln; 
}    

SalesPerson::~SalesPerson()
	{
   
}
void SalesPerson::setSalesPersonId(int id)

	{
    salesPersonId = id;
} 

void SalesPerson::setFirstName(string fn)
	{
    firstName = fn;
} 

void SalesPerson::setLastName(string ln)
	{
    lastName  = ln; 
} 
int SalesPerson::getSalesPersonId()
	{
    return salesPersonId;
}

string SalesPerson::getFirstName()
	{
    return firstName;
} 


string SalesPerson::getLastName()
	{
    return lastName;
}
void SalesPerson::inputSalesPersonId()

	{
    cout << "Enter Sales Persons ID: ";
    cin  >> salesPersonId;
} 
void SalesPerson::inputFirstName()

	{
    cout << "Enter First Name:   ";
    cin  >> firstName;
} 
void SalesPerson::inputLastName()

	{
    cout << "Enter Last Name:  ";
    cin  >> lastName;
    cout << endl;
} 


    





