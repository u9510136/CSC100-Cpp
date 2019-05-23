//Hsuan-yu Lin(Sam) HW# 16
//total volume of spheres

#include<iostream>
#include<math.h>
using namespace std;

int main(){
  
  double volume, radius, totalvolume;
  const double PI = 3.14159;
  
  totalvolume = 0; 
  
  cout << "This system help you to compute total volume of 10 spheres" << endl;
    
  for (int i = 0 ; i < 10 ; ++i ){
        cout << "Please enter the radius of spheres(inches):  ";
        cin >> radius;
        while(radius <= 0){
		  cout << "Error! Please enter a positive number:  ";
		  cin >> radius;
		}
        volume = (4.0 / 3.0) * PI * pow(radius , 3); 
        totalvolume = totalvolume + volume;
  }
  
  cout << "The total volume of 10 spheres is:  " << totalvolume 
       << "(in cubic inches)" << endl;
}
