//Hsuan-Yu Lin(Sam) HW28
//Data types, Records and Array of Records

#include<iostream>
#include<string.h>
using namespace std;

struct memberOfHR {
  
  char lastName[81];
  char stateCode[2];
  char party;
  float height;
  double moneySpent;
  int numberInCongress;
};


int main(){
  
  memberOfHR fry;
  
  strcpy( fry.lastName , "Fry" );
  strcpy( fry.stateCode , "RI" );
  fry.party = 'R';
  fry.height = 69.5;
  fry.moneySpent = 22700462.10;
  fry.numberInCongress = 3;

  return 0;
} 
