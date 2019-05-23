//Hsuan-Yu Lin(Sam) HW# 17
//Chair selling and delivery 

#include<iostream>
using namespace std;

int main(){

  const float PLASTIC = 12.99f;
  const float WOOD = 31.99f;
  const float NAUGA = 15.99f;
  const int NORMAL_DELIVERY = 25;
  const int RUSH_DELIVERY = 100;
  const float RUSH_FEE = 1.5f;
  int numchair;
  char size , delivery;
  float sizecost , totalcost; 

  cout << "Welcome to F&B's chair, which size of chair to you want today?" 
       << endl << "Plastic, wood or naugahyde(p/w/n):  ";
  cin >> size;
  
  while(size != 'p' && size != 'w' && size != 'n'){
    cout << "Sorry! Invalid input. Enter again(p/w/n):  ";
    cin >> size;
  }
  
  cout << "How many chairs do you want:  ";
  cin >> numchair;
  
  while(numchair <= 0){
    cout << "Invalid input. Enter again(must > 0):  ";
    cin >> numchair;
  }
  
  cout << "Do you need normal(within 7 days) or rush(within 1 day)"
       << " delivery(n/r):  ";
  cin >> delivery;
  
  while(delivery != 'n' && delivery != 'r'){
    cout << "Invalid input. Enter again(n/r):  ";
	cin >> delivery;    
  }
  
  if(size == 'p'){
    sizecost = PLASTIC;
  }
  else if(size == 'w'){
    sizecost = WOOD;
  }
  else{
    sizecost = NAUGA;
  }
  
  if(delivery == 'n'){
    totalcost = sizecost * numchair + NORMAL_DELIVERY;
  }
  else{
    totalcost = (sizecost + RUSH_FEE) * numchair + RUSH_DELIVERY;
  }
  
  if(totalcost >= 400){
    totalcost = totalcost * 0.9;
  }
  
  cout << "The total cost is: $" << totalcost << endl; 
    
  
  
  
  return 0;
}
