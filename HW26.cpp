// Hsuan-YU Lin(Sam) HW 26
// practice for array

#include<iostream>
#include<math.h>
using namespace std;

int main(){
  
  double numbers[100];
  int i , last;
  char again;
  
  do{
    cout << "Enter the numbers to store in the array:  ";
    cin  >> numbers[i];
    last = i;
    i++;
    
    cout << "Do you have next number?(y/n):  ";
    cin  >> again;
  }while( again == 'y' );
  
  cout << "Number  Square" << endl;
  for( int j = 0 ; j < last ; j++ ){
    printf("%6.0f  %6.0f\n", numbers[j] , pow(numbers[j] , 2 ));
  } 
  
  return 0;
}
