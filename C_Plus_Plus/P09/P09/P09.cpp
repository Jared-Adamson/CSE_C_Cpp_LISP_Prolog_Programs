//P09 - Array and File Processing  - Jared Adamson
//
//Loads, sorts and searches a partially filled array of integers

#include <iostream>      // cout and cin
#include <fstream>       // file processing
#include <cctype>        // tolower
#include <iomanip>       // setw
#include <stdlib.h>      // system()
using namespace std;

//Declare global variables
//Normally variables that change values are declared locally, 
//but here the array and supporting variables are declared globally
//to simplified the function definitions.

const int DECLARED_SIZE = 20;
int numberArray[DECLARED_SIZE], numbersEntered;

void loadArray( );

void sortArrayAscending( );

void sortArrayDescending( );

void displayArray( );

void searchArray( );

void displayContinuePrompt( );

void bubbleSort( );
//bubbleSort included as an informational item.

void main( )
{
    char choice;

//loadArray with numbers from the data file
    loadArray( );

//check to see what the user wants to do
    do  // while (choice != 'X')
    {
        cout << "P09  Jared Adamson   \n\n";

        cout << "Enter the letter of the desired menu option. \n"
             << "Press the Enter key after entering the letter. \n \n"

             << "  A: Display Employee Id (current order) \n"
             << "  B: Display Employee Id Ascending Order \n"
             << "  C: Display Employee Id Descending Order \n"
             << "  D: Search Employee Id List \n"

             << "  X: Exit the program \n \n"

             << "Choice: ";
		
        cin >> choice;

        choice = toupper(choice);

        switch (choice)
        {
            case 'A':
                cout << "\nValues as read:\n";
                displayArray( );
                displayContinuePrompt( );
                break;
            case 'B':
                cout << "\nValues sorted ascending:\n";
                sortArrayAscending( );
                displayArray( );
                displayContinuePrompt( );
                break;
            case 'C':
                cout << "\nValues sorted descending:\n";
                sortArrayDescending( );
                displayArray( );
                displayContinuePrompt( );
                break;
            case 'D':
                searchArray( );
                displayContinuePrompt( );
                break;
            case 'X':
                cout << "\nNow exiting Number Module...please wait.\n\n";
                break;
            default:
                cout << "\a \n\n Invalid Option Entered - Please try again. \n\n";

        } // end of switch

    } while (choice != 'X');
    
    return;
}//end of main


void loadArray( )
{
    cout << "Opening File...\n";

//Open the file for input;
    ifstream inFile;
    inFile.open("P09.txt"); 
//If there are any errors, display an error message and return.
    if (inFile.fail())
    {
        cout << endl << endl
             << "Error: Input file NOT found. " << endl << endl;
        numbersEntered = 0;
        return;
    }

    cout << "Loading up to " << DECLARED_SIZE << " whole numbers.\n";

//Declare index and initialize to zero for first array element
    int  i = 0;

//Read the first record into array
    inFile >> numberArray[i];        

//Only loads up to 20 numbers - additional data in the file is ignored.
//Use while loop to process file, because
//  while loops handle empty files.

    while (! inFile.eof())
    {
        i++;
        if (i < DECLARED_SIZE)
            inFile >> numberArray[i];
        else
            break;    //get out of the loop
    }
    numbersEntered = i;

    cout << "Closing File...\n\n";
    inFile.close();

    return;
}


void sortArrayAscending( )
{
    int minIndex, minValue, holdValue;

    for (int i = 0; i < (numbersEntered - 1); i++)   //walk through array
    {                                                //outer loop keeps track
        minIndex = i;                                //of where the next value
        minValue = numberArray[i];                   //should be placed.

        for (int i2 = i + 1; i2 < numbersEntered; i2++)
        {                                            //inner loop finds the   
            if (numberArray[i2] < minValue)          //lowest value to move   
            {
                minIndex = i2;                       //save the new low number
                minValue = numberArray[i2];          //found
            }
        }
        holdValue = numberArray[i];                  //swap the values
        numberArray[i] = numberArray[minIndex];
        numberArray[minIndex] = holdValue;
    }
    return;
}


void sortArrayDescending( )
{

    int maxIndex, maxValue, holdValue;

    for (int i = 0; i < (numbersEntered - 1); i++)   //walk through array
    {                                                //outer loop keeps track
        maxIndex = i;                                //of where the next value
        maxValue = numberArray[i];                   //should be placed.

        for (int i2 = i + 1; i2 < numbersEntered; i2++)
        {                                            //inner loop finds the   
            if (numberArray[i2] > maxValue)          //highest value to move  
            {
                maxIndex = i2;                       //save the new high number
                maxValue = numberArray[i2];          //found
            }
        }
        holdValue = numberArray[i];                  //swap the values
        numberArray[i] = numberArray[maxIndex];
        numberArray[maxIndex] = holdValue;
    }
    return;
}


void displayArray( )
{
    cout << endl;
    cout.setf(ios::right);  //already on by default for numbers

    for (int i = 0; i < numbersEntered; i++)
    {
        cout << "position ="; 
        cout << setw(3)  << (i + 1);

        cout << "  index ="; 
        cout << setw(3)  << i;

        cout << "  value =";
        cout << setw(4)  << numberArray[i] 
             << endl;
    }
    return;
}




void searchArray( )
{ 

    sortArrayAscending( ); 

    int  searchNumber;
    bool numberFound = false;

    cout << "\nEnter an employee Id number to search for: ";
    cin >> searchNumber;

    for(int i=0; i < numbersEntered; i++)
    {
        if (searchNumber == numberArray[i])      //check if the value entered is
        {                                        //= to the current array element
            numberFound = true;    
            cout << endl 
                 << searchNumber << " is stored in array position "
                 << i + 1 
                 << " and is \nreferenced with an index value of "
                 << i << ". \n\n";
            break;                              //get out of for-loop
        }
        else if (searchNumber < numberArray[i]) //Early exit
        {
            cout << endl << "Early exit...";
            break;                              //get out of for-loop
        }
    }

    if (false == numberFound)
        cout << searchNumber << " is not on the list.\n";

    return;
}


void displayContinuePrompt( )
{
    char prompt;

    cout << "\nProcedure completed. Press Enter to continue: ";
    cin.ignore(); 
    prompt = cin.get( );

    system("cls");    //clear the screen

    return;
}


//presented as informational item
void bubbleSort( )
{
    int holdValue;

    for (int i = 0; i < (numbersEntered - 1); i++)     //Number of entries in array.
    {                                                 
        for (int i2 = 0; i2 < numbersEntered - 1; i2++)//Inner loop finds the 
        {                                              //lowest value to move.
            if (numberArray[i2] > numberArray[i2 + 1]) //Low values float up.
            {
                holdValue = numberArray[i2];           //swap the values
                numberArray[i2] = numberArray[i2 + 1];
                numberArray[i2 + 1] = holdValue;
            }
        }
    }
    return;
}
// end of program