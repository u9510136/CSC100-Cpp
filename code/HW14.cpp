//Hsua-Yu Lin(Sam)
//HW #14 miles to kilometers convert

#include<iostream>
using namespace std;

int main(){
  
  const double kmpermile = 1.609344;
  double kilometers, miles;
  char again;
  
  do{
    cout << "Welcome to miles-kilometers covert system!" << endl
         << "Please enter the value(miles):  ";
    cin >> miles;
  
    while(miles <= 0){
      cout << "The value must be positive!!" << endl
           << "Please enter again(miles):  ";
      cin >> miles;
    }
  
    kilometers = miles * kmpermile;
  
    cout << miles << " miles are " << kilometers << " kilometers." << endl
         << "Want to try again(y/n):  "; 
    cin >> again;
  }
  while(again == 'y');

  return 0;
}
