//Hsuan-Yu Lin(Sam) HW22
//interest compounded monthly

#include<iostream>
#include<math.h>
using namespace std;

double balanceFormula(double iniBalance , double intRate , int month );

int main(){
	
  double iniBalance , intRate , finalBalance;
  int month;

  cout << "Welcome to the saving balance computing system." << endl
       << "Please enter the initial balance(dollars):  ";
  cin >> iniBalance;
  
  cout << "Please enter the interest rate (0~100):  ";
  cin >> intRate;
  
  cout << "Please enter the number of months you save:  ";
  cin >> month;
  
  finalBalance = balanceFormula( iniBalance , intRate , month );
  
  cout << "Your final Balance is:  " << finalBalance << endl << endl;
  
  finalBalance = balanceFormula( finalBalance , intRate , 1 );
  
  cout << "the Balance is:  " << finalBalance << endl;

  return 0;
}

double balanceFormula(double iniBalance , double intRate , int month ){

  double finalBalance;
  
  finalBalance = iniBalance * pow( 1 + intRate / 100 , month / 12.0 );
  
  return finalBalance;
}

