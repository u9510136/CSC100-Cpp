//Hsuan-Yu Lin EX14
// Files and Arrays

#include<iostream>
#include<fstream>
using namespace std;

int loadData( int ID[] , double score[] );
void displayTable( int ID[] , double score[] , int nRecords );

int main(){

  int ID[100];
  double score[100];
  int nRecords;

  loadData( ID , score );
  displayTable( ID , score , nRecords );  
 
  return 0;
}

int loadData( int ID[] , double score[] ){
  
  fstream infile;
  int ix;
  int nRecords;
  
  cout << "opening the file..." << endl;
  infile.open(  "C:\\TL\\a.txt",ios::in);
  
  ix = 0;
  infile >> ID[ix] >> score[ix];
  while( ID[ix] != 0 ){
  	++ix;
  	infile >> ID[ix] >> score[ix];
  }
  nRecords = ix;
  infile.close();
  
  return nRecords;
}

void displayTable( int ID[] , double score[] , int nRecords ){
  
  int ix;
  
  cout << "ID\tScore" << endl;
  
  for ( ix = 0 ; ix < nRecords ; ix++ ){
    cout << ID[ix] << "\t" << score[ix] << endl;
  }
  
  cout << "all done..." << endl;
}
