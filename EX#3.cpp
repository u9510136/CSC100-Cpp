// Hsuan-Yu Lin - Exercise #3
// Compute the weight of water in a pipe

#include<iostream>
#include<math.h>
using namespace std;

int main(){

  double water, lpipe, dpipe;
  const double density = 0.34;
  
  cout << endl << "Compute the weight of water in a pipe" << endl << endl ;
    
  cout << "Enter length of pipe(feet): " ;
  cin >> lpipe;
  
  cout << "Enter pipe diameter(inches): ";
  cin >> dpipe;
  
  water = lpipe * pow(dpipe,2) * density ;
  
  cout << endl << endl ;
  cout << "Weight of water in a pipe = " << water << endl << endl;
  
  cout << "Have a nice day" << endl << endl;
  
  return 0; 

}

