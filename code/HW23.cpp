//Hsuuan-Yu Lin(Sam) Hw# 23
//Compute Ring Volume Subprograms

#include<iostream>

using namespace std;

void Message( void );
double Inputs ( double &ringRadius , double &crossRadius );
double Formula ( double ringRadius , double crossRadius );
void Result( double volume );

int main(){
	
  double ringRadius , crossRadius;
  double volume;
  
  Message();
  Inputs( ringRadius , crossRadius );
  volume = Formula( ringRadius , crossRadius );
  Result( volume );
  
  return 0;
}

void Message( void ){
  cout << "Compute Ring Volume" << endl;
}

double Inputs ( double &ringRadius , double &crossRadius ){
  
  cout << "Enter the ring radius(inches): ";
  cin  >> ringRadius;
  
  while( ringRadius <= 0 ){
    cout << "the radius must be positive" << endl
         << "Enter the ring radius(inches):  ";
    cin  >> ringRadius;
  }
  
  cout << "Enter the cross section radius(inches): ";
  cin  >> crossRadius;
  
  while( crossRadius <= 0 ){
    cout << "The radius must be positive" << endl
         << "Enter the cross section radius(inches):  ";
    cin  >> crossRadius;
  }
  
}
double Formula ( double ringRadius , double crossRadius ){
  
  double volume;
  const double PI = 3.14159;
  
  volume = 2 * PI * PI * ringRadius * crossRadius * crossRadius;
  
  return volume;
}
void Result( double volume ){
  cout << "The volume of the ring is:  " << volume << "(cube in inches)" 
       << endl;
}
