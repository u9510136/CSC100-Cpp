//Hsuan-Yu Lin Hw20
// subprogram pratice 2

#include<iostream>
#include<math.h>
using namespace std;

double ballHeight( double velocity , double time );

int main(){
  
  double velocity, time, height;
  
  cout << "Height of a ball thrown straight up" << endl << endl;
  
  cout << "Enter the initial velocity of the ball(feet per second):  ";
  cin >>  velocity;
  
  cout << "Enter the amount of the time after the ball is thrown(seconds):  ";
  cin >> time;
  
  height = ballHeight( velocity , time );
  
  cout << endl << "height = " << height << " feet" << endl;
  cout << endl << "Have a nice day!" << endl;
  
  return 0;
}

double ballHeight( double velocity , double time ){
  
  double height;
  const double GRAVITY = 32.174;
  
  height = velocity * time - ( 1.0 / 2.0 ) * GRAVITY * pow( time , 2 );
  return height;
}
