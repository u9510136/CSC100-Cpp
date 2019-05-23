//Hsuan-Yu Lin(Sam) Program #3
//1040XEZ form

#include<iostream>
using namespace std;

int main(){
 
  char married;
  string ssn1 , ssn2;
  float salaries , taxableinterest;
  float agi;  //ajusted gross income 
  int taxableincome; 
  float fitw; // Federal income tax withheld
  float tax;
  float final;
  
  cout << "Welcome to 1040XEZ system." << endl
       << "PLease enter your social security number(SSN): ";
  cin >> ssn1;
  cout << endl;
  
  cout << "Are you married(y/n)?  ";
  cin >> married; 
  cout << endl;
  
  if( married == 'y' ){
    cout << "Pleased enter your spouse's SSN:  ";
    cin >> ssn2;
    cout << endl;
  }
  
  cout << "Please enter the wages, salaries, tips, from W-2" << endl
       << "(if married, enter the combined one):  ";
  cin >> salaries;
  cout << endl;
  
  cout << "Please enter the taxable interest" << endl
       << "(if married, enter the combined one):  ";
  cin >> taxableinterest;
  cout << endl;
  
  if( taxableinterest > 1500 ){
    cout << "Warning! You may not allowed to use 1040XEZ form" << endl << endl;
  }
  
  agi = salaries + taxableinterest;
  
  if( married == 'y' ){
    taxableincome = agi - 20800;
  }
  else{
    taxableincome = agi - 10400;
  }
         
  if( taxableincome < 0 ){
    taxableincome = 0;  
  }
  
  cout << "Please enter Federal income tax withheld from W-2 & 1099" << endl
       << "(If married, enter the combined one):  ";
  cin >> fitw;
  cout << endl;
  
  if( taxableincome <= 9350 ){
    if( taxableincome < 5 ){
	  tax = 0;
	}
	else if( taxableincome < 25 ){
	  tax = 1 + ((agi - 5) / 10) * 1;
    }
    else if( taxableincome < 75 ){
	  tax = 4 + ((agi - 25) / 25) * 2;
	}
	else{
	  tax = 9 + ((agi - 75) / 50) * 5;
	}
  }
  else{
    if( married == 'y'){
	  if( taxableincome < 18650 ){
	    tax = 938 + ((agi - 9350) / 50) * 5;
	  }
	  else if( taxableincome < 75900 ){
	    tax = 1869 + ((agi - 18650) / 100) * 15; 
	  }
	  else{
	    tax = 10459 + ((agi - 75900) / 100) * 25;
	  }
	}
	else{
	  if( taxableincome < 38000 ){
	    tax = 940 + ((agi - 9350) / 100) * 15;
	  }
	  else if( taxableincome < 91900){
	    tax = 5245 + ((agi - 38000) / 100) * 25;
	  } 
	  else{
	    tax = 18721 + ((agi - 91900) / 50) * 14;
	  }
	}
  }
  
  if( taxableincome > 100000 ){
    cout << "Warning! You may not allowed to use 1040XEZ form." 
	     << endl << endl;
  }
  
  final = fitw - taxableincome;
  
  cout << "Congratulations! We are finally done!" << endl
       << "Here is your tax information" << endl << endl
       << "Your social security number(SSN): " << ssn1 << endl;
  if( married == 'y'){
    cout << "Your spouse's SSN: " << ssn2 << endl;
  }
  cout << "Your ajusted gross income:  $" << agi << endl;
  cout << "Your taxable income:  $" << taxableincome << endl
       << "Your tax:  $" << tax << endl;
  
  if( final < 0){
    final = -final;
    cout << "You still owe the goverment:  $" << final << endl;
  }
  else if (final == 0 ){
    cout << "Congratulations! We are exactly even! No refund and nothing owed."
	     << endl;
  }
  else{
    cout << "Congratulations! You have refund:  $" << final << endl;
  }
  
  cout << "We hope see you again next year. Thank you very much." << endl;
  
  return 0;
}
