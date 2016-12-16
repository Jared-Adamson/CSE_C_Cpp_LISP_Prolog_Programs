
// Jared Adamson

#include <iostream>

using namespace std;

int main(){
  
  int age;

  cout << "enter your age:";

  cin >> age;

  cin.ignore();

  if( age < 100){

  cout << " You are young!";

  } else if( age == 100){

    cout << "You are old.";

  }else {

    cout << " You are super old!!!";

  }

  cin.get();




}
