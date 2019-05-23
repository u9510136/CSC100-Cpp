//Hsuan-Yu Lin(Sam) HW24
//TV screen size

#include<iostream>
#include<math.h>
using namespace std;

void TVsizeTransfer ( double diagonal , double ratio ,
                      double &height , double &width);

int main(){
  
  double diagonal , ratio;
  double height , width;
  char again;
  
  do{
    cout << "This program computes the size of TV srceen." << endl
         << "Please enter the diagonal(inches):  ";
    cin  >> diagonal;
    cout << "Please enter the aspect ratio: ";
    cin  >> ratio;
    
    TVsizeTransfer( diagonal , ratio , height , width );
    
    cout << "The height of the TV is: " << height << "(inches)" << endl
         << "The width of the TV is: " << width << "(inches)" << endl;
         
    cout << "Do you want to try again?(y\n)  ";
    cin  >> again;
    
  }while(again == 'y');
  
  return 0;
}

void TVsizeTransfer ( double diagonal , double ratio , 
                      double &height , double &width){

  height = sqrt( diagonal * diagonal / ( 1 + ratio * ratio ));
  width = height * ratio;
}


