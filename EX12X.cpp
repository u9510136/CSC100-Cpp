//Hsuan-Yu Lin(Sam) EX12X
//subprogram exercise

#include<iostream>
using namespace std;

void blankLines ( int lines );
void nChars ( int number , char chars );
void horizonLines ( int horizontal );

int main(){
  
  int numChars;
  
  cout << "How many nChars in the first horizontal line?";
  cin  >> numChars;
  
  blankLines( 2 );
  horizonLines( 5 );
  nChars ( numChars , '*' );
  blankLines( 1 );
  horizonLines( 3 );
  nChars ( numChars * 2 , 'X' );
  blankLines( 1 );
  horizonLines( 1 );
  nChars ( numChars * 3 , 'O' );

  return 0;
}

void blankLines ( int blank ){
  
  for ( int i = 0 ; i < blank ; i++ ){
    cout << endl;
  } 
}

void nChars ( int number , char chars ){
  for( int i = 0 ; i < number ; i++ ){
    cout << chars;
  }
}

void horizonLines ( int horizontal ){
  for ( int i = 0 ; i < horizontal ; i++ ){
    cout << " ";
  }
}


