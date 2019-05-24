// Hsuan-Yu Lin(Sam) HW#10
// number of T-shirts customer can afford

#include<iostream>
using namespace std;

int main(){
  

  const float ETshirt = 29.99f;
  const float PTshirt = 19.99f;
  const float TAX = 1.07f;
  char team, ticket;
  float wanttospend;
  double ajustcost;
  int NumTshirts;

  cout << "Welcome! Which team's T-shirts do you want today?" << endl
       << "enter e if you want Eagles, or p if you want Patriots:  ";
  cin >> team;
  cout << endl;
  
  cout << "How much do you want to spend today?  $";
  cin >> wanttospend;
  cout << endl;
  
  cout << "Do you have a Azizona Cardinals season ticket?(y/n)  ";
  cin >> ticket;
  cout << endl;
  
  if( team == 'e') {
  
     if( ticket == 'y' ){
	   ajustcost = ETshirt;
	 } else {
	   ajustcost = ETshirt * TAX; 
	 }
  } else {
     
	 if( ticket == 'y' ){
	   ajustcost = PTshirt;
	 } else {
	   ajustcost = PTshirt * TAX;
	 }
  }
  
  NumTshirts = wanttospend / ajustcost;
  
  cout << "You can buy " << NumTshirts << " T-shirts today!" << endl;
  
return 0;

}
