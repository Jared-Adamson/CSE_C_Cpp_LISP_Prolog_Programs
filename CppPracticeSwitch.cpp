
// Jared Adamson


#include <iostream>
#include <cstdlib>

using namespace std;

void sch(int x);

int main(){

int x;

cout << "Enter a numer between 1-3\n";
cin >> x;
cin.ignore();

sch(x);

cin.get();

}


void sch(int x){

  switch(x){
  case 1:
  cout << "You entered 1.\n";
  break;
  case 2:
  cout << "You entered 2.\n";
  break;
  case 3:
  cout << "You entered 3.\n";
  break;
  default:
  cout << "Thas not 1-3!\n";
  break;
  }

}