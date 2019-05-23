//Hsuan-Yu Lin(Sam) EX15 (8)
//Array subprogram practice

#include<iostream>
using namespace std;

int greatNumber( double test[] , int size , double number ); 

int main(){
  
  
  /*
    introduction for program
    code for input array's info(data , size)
    code for input the number we want to compare
    greatNumber( test , size , number )
    show the final count
  */
       
  return 0;
}

int greatNumber( double test[] , int size , double number ){
  
  int count = 0;
   
  for( int i = 0 ; i < size ; i++ ){
    if( test[i] > number ){
	  count++;
	}
  }
  
  return count;
}

