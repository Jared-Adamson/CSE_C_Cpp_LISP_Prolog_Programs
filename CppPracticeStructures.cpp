
// Jared Adamson


#include <iostream>
#include <cstdlib>

using namespace std;

struct exampleStruct {

  int x;
  int y;
  int z;

};


int main(){

  exampleStruct demoStruct;

  demoStruct.x = 23;
  demoStruct.y = 67;
  demoStruct.z = 34;

  //cout << "Enter a number:\n";
  //cin >> x;
  //cin.ignore();

  cout << demoStruct.x << endl;
  cout << demoStruct.y << endl;
  cout << demoStruct.z << endl;

  cin.get();

}

