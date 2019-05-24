//Hsuan-Yu Lin(Sam) HW#8
//Scooby's Hotdog House cost compute


#include<iostream>
using namespace std;

int main(){

  int HD, snacks;
  float cost;
  const float PerHD =  1.49;
  const float Persnacks = 9.95;
  
  cout << "Welcome to Scooby's Dog House!" << endl << endl
       << "How many hot dogs do you want today? ";
  cin >> HD;
  
  cost = PerHD * HD;
  
  if(HD >= 12) {
     cout << "How many packs of Scooby Snacks you want? ";
     cin  >> snacks;
     cost = cost + Persnacks * snacks; 
  }
  
  cout << "The total cost is : $" << cost << endl
       << "Have a nice day!";


 return 0;
}
