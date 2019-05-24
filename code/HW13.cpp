//Hsuan-Yu Lin(Sam)
// HW #13  classify igneous rocks

#include<iostream>
using namespace std;

int main(){

  int percent;

  cout << "Welcome to Ignoeus Rocks Classifying system" << endl
       << "Please enter the percentage of dark minerals in the rock(%):  ";
  cin >> percent;
  
  if(percent <= 35){
    cout << "It's Leuocratic." << endl;
  }
  else if(percent > 35 && percent <= 65){
    cout << "It's Mesocratic." << endl;
  }
  else if(percent > 65 && percent <= 90){
    cout << "It's Melanocratic." << endl;
  }
  else{
    cout << "It's Ultramafic." << endl;
  }
  
  cout << endl << "See you next time." << endl;
return 0;
}
