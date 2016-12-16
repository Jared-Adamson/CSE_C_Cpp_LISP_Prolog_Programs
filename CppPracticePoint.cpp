
// Jared Adamson


#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

int x;
int *p;

p = &x;

cout << "Enter a number:\n";
cin >> x;
cin.ignore();

cout << *p << endl;
cout << p << endl;

//The keyword new is used to initialize pointers with memory from free store (a section of memory available to all programs). 
int *ptr = new int;
//The delete operator frees up the memory allocated through new. To do so, the syntax is as in the example.
delete ptr;

cin.get();

}

