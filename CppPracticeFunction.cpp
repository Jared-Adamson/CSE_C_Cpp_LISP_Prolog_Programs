
// Jared Adamson


#include <iostream>
#include <cstdlib>

int mply(int x, int y);

using namespace std;

int main(){

int a; 
int b;

a = rand();

b = rand();

cout << a << endl;
cout << b << endl;
cout << mply(a,b);

cin.get();


}

int mply(int x, int y){

  return y * x;

}