// Pay Calculator - Jared Adamson


#include <iostream>
using namespace std;
// Global

	const double OVERTIME_RATE = 1.5;
	const double UNION_DUES = 10.00, FICA_RATE = 0.06,
             FEDERAL_RATE (0.15), STATE_RATE = (0.05);
//Define variables
//Function Prototypes
    double inputRate();
    int    inputHours();
    double calcGross(double rate, int hours);
    double calcTax(double gross, double taxRate);

	//Functions
	double inputRate ()
{
    double rate;

  do
    {
         cout  << "Enter the hourly pay rate (Between $10.00 and $15.00 inclusively.) : ";
//Get the input values
cin >> rate;

    } while (rate < 10.00 || rate > 15.0);

    rate = rate;
	return rate;
}


	int inputHours()
	{
		int hours;

	do
{
// Check to see if input is valid
cout << "Enter the number of hours worked (between 1 and 50 inclusively): ";
cin >> hours;


} while (hours > 50 || hours < 1);



    return hours;
	}



 double calcGross(double rate, int hours)
{
    double gross;
    if (hours > 40)
        gross   = (40 * rate) + ((hours - 40) * rate * OVERTIME_RATE);
     else
        gross   = hours * rate;
    
    return gross;
}










	

void main()
{


//Set the decimal

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

//----------------------------------------------

double fica, federal, state, netpay, netHourly, gross, rate;
int hours;
//Display name 
cout << "P05 - Jared Adamson \n\n";

//input values
cout << "Enter the hourly rate and the number of hours \n"
<< "worked. \n"
<< "Press the enter key after entering both values. \n" 
<< "The hourly rate  must be between $10.00 and $15.00 inclusively. \n" 
<< "The hours worked must be between 1 and 50 inclusively."
<< endl << endl;

// Call to the functions
rate = inputRate ();

hours = inputHours ();

gross = calcGross( rate, hours);


// Calc gross,taxes netpay, and nethourly


fica = gross * FICA_RATE;
federal = gross * FEDERAL_RATE;
state = gross * STATE_RATE;
netpay = gross - (fica + federal + state + UNION_DUES);
netHourly = netpay / hours;
// DIsplays all info

cout << endl
	<< "Hourly Rate: \t" << rate << endl
	<< "Hours Worked: \t" << hours << endl
	<< "Gross Pay: \t" << gross << endl
	<< "FICA Tax: \t" << fica << " at " << FICA_RATE << endl
	<< "Federal Tax: \t" << federal << " at " << FEDERAL_RATE << endl
	<< "State Tax: \t" << state << " at " << STATE_RATE << endl
	<< "Union Dues: \t" << UNION_DUES << endl
	<< "Net Pay: \t" << netpay << endl
	<< "Net Hourly: \t" << netHourly << endl;





cout << "\nThank You!\n\n";


}


//End of Main