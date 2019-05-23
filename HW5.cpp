//CSC 100 Homework #5
//Hsuan-Yu Lin(Sam)

#include<iostream>
#include<math.h>
using namespace std;

int main() {

double Lum, dis, bright, PI;
PI = 3.14159; 

  cout << "Welcome to Night Sky Brightness Calculation System" << endl
       << "Please type in the distance(in meters): ";
  cin  >> dis;
  cout << "Please type in the brightness(in Watts/meters^2 ): ";
  cin  >> bright;
  Lum = 4*PI*pow(dis,2)*bright;
  
  cout << endl << "Here is the luminosity of your star(Watts): " << Lum
       << endl;
  
  return 0;


}
