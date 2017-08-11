//P14  SalesInfo -  Jared Adamson   TR 1:00pm
//Interface file - sales_info.h  - function prototypes

#ifndef SALES_INFO_H
#define SALES_INFO_H

#include "sales_person.h"   //SalesPerson definition required for inheritance



class SalesInfo : public SalesPerson   //copy-and-paste your class definition over this outline.
{
private:
	 double rate;
     int    qty;

public:
//default constructor - call input functions and base constructor
    SalesInfo( );

//overload constructor - need to also take in values for base class
    SalesInfo(int id, string fn, string ln, double r, int q);

//destructor
    ~SalesInfo( );

//accessors
    void setRate(double r);
    void setQty(int q);
    

    double getRate( );
    int getQty( );
    

    void inputRate( );
    void inputQty( );
  
};                    //copy-and-paste your class definition over this outline.


#endif  // End of SALES_INFO_H  class 

