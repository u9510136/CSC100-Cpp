//Hsuan-Yu Lin(Sam) Pragram 5 Phase 1
//Function and Parameter Passing

#include<iostream>
#include<math.h>
using namespace std;

void distance( void );
double distanceCompute( double x1 , double y1 , double x2 , double y2 );
void horizontalAngle( void );
double horizontalAngleCompute( double x1 , double y1 , double x2 , double y2 );
void horizontalDistance( void );
double horizontalDistanceCompute( double vertiAngle , double velocity);
void destination( void );
void destinationCompute( double x1 , double y1 , double horiAngle 
                        ,double length , double &x2 , double &y2 );
void getCoordinates( double &x , double &y );

int main (){
  
  int option;
  
  cout << "Welcome to our formula computing system";
  
  do{
    cout << "please choose one formula you want to use:" << endl
	     << "1. Distance compute by 2 coordinates" << endl
		 << "2. horizontal angle compute by 2 coordinates" << endl
		 << "3. horizontal distance compute by angle and velocity" << endl 
		 << "4. distenation point dcompute by start point, angle and distance"
		 << "5 system exit"
		 << endl;
    cout << "Which one do you want(1~5): ";
	cin  >> option;
	while( option < 1 || option > 5 ){
	  cout << "The option must be 1, 2, 3, 4 or 5. Enter again(1~5):";
	  cin  >> option;
	}
	
	if( option == 1 ){
	  distance();
	}
	else if( option == 2 ){
	  horizontalAngle();
	}
	else if( option == 3 ){
	  horizontalDistance();
	}
    else if( option == 4 ){
      destination();
	}
	
	cout << endl;
		
  }while( option != 5 );
  
  return 0;
}

void distance( void ){
	
  double x1 , y1 , x2 , y2 , result;
	
  cout << "1st set of coordinates(feets): " << endl;
  getCoordinates( x1 , y1 );
  cout << "2nd set of coordinates(feets): " << endl;
  getCoordinates( x2 , y2 );
  
  result = distanceCompute( x1 , y1 , x2 , y2 );
  printf("The distance between (%.2f,%.2f) and (%.2f,%.2f) is %.2f feets \n"
         , x1, y1, x2, y2, result); 
  
}

double distanceCompute( double x1 , double y1 , double x2 , double y2 ){
  
  double result;
  
  result = sqrt( pow(( x2 - x1 ) , 2) + pow(( y2 - y1 ) , 2 ));
  
  return result;
}
void horizontalAngle( void ){
  
  double x1 , y1 , x2 , y2 , result;
  	
  cout << "1st set of coordinates(feets):" << endl;
  getCoordinates( x1 , y1 );
  cout << "2nd set of coordinates:(feets)" << endl;
  getCoordinates( x2 , y2 ); 
  
  result = horizontalAngleCompute( x1 , y1 , x2 , y2 );
  
  printf("The horizontal angle from (%.2f,%.2f) to (%.2f,%.2f) is %.2f degrees",
         x1, y1, x2, y2, result); 
  cout << endl;

}

double horizontalAngleCompute( double x1 , double y1 , double x2 , double y2 ){
  
  double dx , dy , temp , horiAngle;
  double const PI = 3.14159;
  
  dx = x2 - x1;
  dy = y2 - y1;
  
  if( dx > 0 ){
    temp = atan( dy / dx );
  }
  else if( dx < 0 ){
    temp = atan( dy / dx) + PI;
  }
  else if( dy >= 0 ){
    temp = PI / 2;
  }
  else{
    temp = -PI / 2;
  }
  horiAngle = temp * 180 / PI;
  
  return horiAngle; 
}
void horizontalDistance( void ){
  
  double vertiAngle , velocity , result;
  
  cout << "Enter the vertical Angle(degrees, 0~90): ";
  cin  >> vertiAngle;
  while( vertiAngle <= 0 || vertiAngle >= 90){
    cout << "It must be between 0 and 90(exclusive), Enter again:";
    cin  >> vertiAngle;
  }
  
  cout << "Enter the velocity(miles/hr): ";
  cin  >> velocity;
  while( velocity <= 0 ){
    cout << "It must be positive. Enter again: ";
    cin  >> velocity;
  }
  
  result = horizontalDistanceCompute( vertiAngle , velocity );
  
  cout << "The distance is " << result << "(feets)" << endl; 
}

double horizontalDistanceCompute( double vertiAngle , double velocity){
  
  double finalDistance;
  double radianAngle , initialVelocity;
  double const PI = 3.14159;
  double const FEET_PER_MILE = 5280;
  double const SECONDS_PER_HOUR = 3600;
  double const GRAVITY = 32.172; 
  
  radianAngle = vertiAngle * PI / 180;
  initialVelocity = velocity * FEET_PER_MILE / SECONDS_PER_HOUR;
  finalDistance = pow( initialVelocity , 2 ) * sin( 2 * radianAngle ) / GRAVITY;
  
  return finalDistance;
}
void destination( void ){
  
  double x1 , y1 , x2 , y2 , length , horiAngle;
  
  cout << "Enter the start point: " << endl;
  getCoordinates( x1 , y1 );
  
  cout << "Enter the horizontle angle(degrees, 0~360, inclusive): ";
  cin  >> horiAngle;
  while( horiAngle < 0 || horiAngle > 360 ){
    cout << "It must be between 0 to 360, enter again: ";
    cin  >> horiAngle;
  }
  
  cout << "Enter the distance from the start point: ";
  cin  >> length;
  while( length <= 0 ){
    cout << "It must be great than 0, enter again: ";
    cin  >> length;
  }
  
  destinationCompute( x1 , y1 , horiAngle , length , x2 , y2 );
  printf("The end point from (%.2f,%.2f) with horizontle angle", x1, y1);
  printf(" %.2f and distance %.2f is (%.2f,%.2f)", horiAngle, length, x2, y2);
  cout << endl;
}

void destinationCompute( double x1 , double y1 , double horiAngle 
                        ,double length , double &x2 , double &y2 ){

  double const PI = 3.14159;
  double angle , dx , dy ;
  
  angle = horiAngle * PI / 180;
  dx = length * cos( angle );
  dy = length * sin( angle );
  x2 = x1 + dx;
  y2 = y1 + dy;
  						
}

void getCoordinates ( double &x , double &y ){

  cout << "Enter the x: ";
  cin  >> x;
  cout << "Enter the y: ";
  cin  >> y;
}
