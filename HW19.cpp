//Hsuan-yu Lin HW# 19
// Loops and subprogram practice

#include<iostream>
using namespace std;

void display();

int main(){

  cout << "Greeting!" << endl;
  display();
  cout << "One more time..." << endl;
  display();
  cout << "See you next time!" << endl;
  
  return 0;
}

void display(){

  for ( int i = 0 ; i < 20 ; ++i ){
    cout << "Hsuan-Yu Lin" << endl;
  } 
}


