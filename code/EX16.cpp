//Hsuan-Yu Lin(Sam) EX16 (3)
//Array subprogram practice

#include<iostream>
using namespace std;

void loadData( char name[] , double num[] , int len );
double nearest( double num[] , int len , int val );

int main(){
  
  char name1[81];
  char name2[81];
  double score1[10];
  double score2[10];
  int numScores1;
  int numScores2;
  double standard;
  double near1;
  double near2;
  char again;
  
  cout << "Who have the nearest scores?" << endl;
  
  do{
    cout << "Enter the 1st name: ";
    cin  >> name1;
  
    cout <<"Enter the 2nd name:  ";
    cin  >> name2;
  
    cout << "What's the score you want to compare?";
    cin  >> standard;
  
    loadData( name1 , score1 , numScores1 );
    loadData( name2 , score2 , numScores2 );
  
    near1 = nearest( score1 , numScores1 , standard );
    near2 = nearest( score2 , numScores2 , standard );
  
    if( near1 < near2 ){
      cout << name1 << " has the nearest score!" << endl;
    }
    else if( near1 > near2 ){
      cout << name2 << " has the nearest score!" << endl;
    }
    else{
      cout << name1 << " and " << name2 << " are even!" << endl;
    }  
  
    cout << "Do you want to try again?(y/n):  ";
    cin  >> again;
  }while( again == 'y' );
  
  return 0;
}

void loadData( char name[] , double num[] , int len ){

}

double nearest( double num[] , int len , int val ){

}
