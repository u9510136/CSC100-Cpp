//Hsuan-Yu Lin(Sam) EX18
//Arrays of Records

#include<iostream>
#include<fstream>
using namespace std;

struct GSWarriors{

  char name[81];
  int age;
  float height;  
};

void loadPlayers( GSWarriors players[] , int &count );
void displayPlayers( GSWarriors players[] , int &count );

int main(){

  GSWarriors players[3];
  int count;
  
  cout << "Records of players at GS Warriors." << endl;
  
  loadPlayers( players , count );
  displayPlayers( players , count );


  return 0;
  

}

void loadPlayers ( GSWarriors players[] , int &count ){

  int j = 0;
  char more;
  fstream infile;
  char fileName[81];
  
  cout << "Enter the file name to load the data: ";
  cin  >> fileName;
  
  infile.open( fileName , ios::in );
  
  do{
  	cout << "Loading player #" << j + 1 << endl;
    infile >> players[j].name >> players[j].age >> players[j].height;
    j++;
    
    cout << "Do you have more record?(y/n): ";
	cin  >> more;
  }while( more == 'y'); 
  
  count = j;
}

void displayPlayers( GSWarriors players[] , int &count ){

  cout << endl << "*** GS Warriors ***" << endl << endl;
  for( int i = 0 ; i < count ; i++ ){

    cout << "Name\t\tAge\t\tHeight" << endl
         << players[i].name << "\t\t"
         << players[i].age << "\t\t"
         << players[i].height << endl;
  }

}


