//Hsuan-Yu Lin(Sam) Pragram 5
//Function and Parameter Passing

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

void basicCalculation( void );
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
void artilleryTable( void );
void targetPractice( void );
void spaceInvaders( void );
void yourGame( void );

int main (){
  
  int menu;
  do{
    cout << "Welcome to Our system. We have options below" << endl
         << "1. Basic Calculation" << endl
         << "2. Artillery Table" << endl
         << "3. Target Practice" << endl
         << "4. Sapced Invaders" << endl
         << "5. Your Game" << endl
         << "6. Quit" << endl
         << "Please enter 1 ~ 6 to choose an option:  ";
    cin  >> menu;
  
    if( menu == 1 ){
      basicCalculation();
    }
    else if( menu == 2 ){
      artilleryTable();
    }
    else if( menu == 3 ){
      targetPractice();
    }
    else if( menu == 4 ){
	  spaceInvaders();
	}
	else if( menu == 5 ){
	  yourGame();
	}
  }while( menu != 6 );
  
  return 0;
}

void basicCalculation( void ){
	
  int option;
  
  do{
    cout << "please choose one formula you want to use:" << endl
	     << "1. Distance compute by 2 coordinates" << endl
		 << "2. horizontal angle compute by 2 coordinates" << endl
		 << "3. horizontal distance compute by angle and velocity" << endl 
		 << "4. distenation point dcompute by start point, angle and distance"
		 << endl << "5. system exit"
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

void artilleryTable( void ){
  
  double vertiAngle , velocity , add;
  int row , whichToChange;
  
  cout << "Enter the initial vertical angle(degree)(0~90,exclusive): ";
  cin  >> vertiAngle;
  while( vertiAngle <= 0 || vertiAngle >= 90 ){
    cout << "the vertical angle must be between 0 to 90, exclusive, " 
	     << "Enter again: ";
    cin  >> vertiAngle;
  }
  
  cout << "Enter the initial velocity(miles/hr)";
  cin  >> velocity;
  while( velocity <= 0 ){
    cout << "The initial velocity must be greater than 0, enter again:  ";
    cin  >> velocity;
  }
  
  cout << "How many rows do you want in the table: ";
  cin  >> row;
  while( row < 1 ){
    cout << "It must be at least 1, enter again: ";
    cin  >> row;
  }
  
  cout << "Which one do you want change the value while making the table" 
       << endl  << "1 for angle, 2 for velocity: ";
  cin  >> whichToChange;
  while( whichToChange != 1 && whichToChange != 2 ){
    cout << "You have to choose one, enter again(1/2): ";
    cin  >> whichToChange;
  }
  
  cout << "How much do you want to increase per time:  ";
  cin  >> add;
  while( add < 0 ){
    cout << "It must be greater than 0, enter again: ";
    cin  >> add;
  }
  if( whichToChange == 1 ){
    cout << "Angle    Distance" << endl
         << "(degs)   (feet)" << endl;
  }
  else{
    cout << "Speed        Distance" << endl
         << "(miles/hr)   (feet)" << endl;
  }  
  for( int i = 0 ; i < row ; i++ ){
    if( whichToChange == 1 ){
	  printf("%.1f    %.3f\n"
	         , vertiAngle, horizontalDistanceCompute( vertiAngle , velocity ));
	  vertiAngle = vertiAngle + add;
    }
	else{
	  printf("%.1f         %.3f\n"
	         , velocity, horizontalDistanceCompute( vertiAngle , velocity ));
	  velocity = velocity + add;
	}    
  }
}
void targetPractice( void ){
  
  int difficulty;
  int const SIZE_E = 100;
  int const SIZE_N = 25;
  int const SIZE_H = 5;
  int size;
  double targetX , targetY , hitX , hitY;
  double const CANNON_X = 2500;
  double const CANNON_Y = 0; 
  char again , next;
  int hit , notHit;
  double horiAngle , vertiAngle , velocity , distance , distanceToTarget;
  
  srand(time(NULL));
  
  cout << "You will fire a cannon and try to hit a floating target" << endl
       << "Your cannon is set at (2500,0) and the target is between (0,0) and"
       << endl << " (5000,5000) randomly." << endl
       << "What difficulty do you want? 1: easy, 2: normal, 3: hard:  ";
  cin  >> difficulty;
  while( difficulty != 1 && difficulty != 2 && difficulty != 3 ){
    cout << "It must be 1, 2 or 3, enter again: ";
    cin  >> difficulty;
  }
  if( difficulty == 1 ){
    size = SIZE_E;
  }
  else if( difficulty == 2 ){
    size = SIZE_N;
  }
  else{
    size = SIZE_H;
  }
  
  do{
    targetX = rand() % 5000;
    targetY = rand() % 5000;
    hit = notHit = 0;
    
    do{
      cout << "Enter the horizontal angle for the shot(0~180 degrees): ";
      cin  >> horiAngle;
      while( horiAngle < 0 || horiAngle > 180 ){
	    cout << "It must be between 0 to 180. Enter again: ";
	    cin  >> horiAngle;
	  }
	  
	  cout << "Enter the vertical angle for the shot"
	       << " (0~90 degrees, exclusive): ";
      cin  >> vertiAngle;
      while( vertiAngle <= 0 || vertiAngle >= 90 ){
	    cout << "It must be between 0 to 90 exclusively. Enter again: ";
	    cin  >> vertiAngle;
	  }
	  
	  cout << "Enter the velocity for the shot(miles/hr): ";
      cin  >> velocity;
      while( velocity <= 0){
	    cout << "It must be greater than 0. Enter again: ";
	    cin  >> velocity;
	  }
	  
	  distance = horizontalDistanceCompute(vertiAngle , velocity);
	  destinationCompute( CANNON_X , CANNON_Y , horiAngle
	                     , distance , hitX , hitY);
	  distanceToTarget = distanceCompute(targetX , targetY , hitX , hitY);
	  if( distanceToTarget <= size ){
	    cout << "BOOM!! You crash the target!!" << endl;
	    hit++;
	  }
	  else{
	    cout << "Oops! you miss the shot" << endl
	         << "the distance from your hit to the target is " 
			 << distanceToTarget << " (feet)" << endl
			 << "Do you want to try another shot?(y/n): ";
		cin  >> again;
		notHit++;
	  }
	}while(again == 'y');
	cout << "Do you want to try next target?(y/n): ";
	cin  >> next;
  }while( next == 'y');
  cout << "This time, you hit the target " << hit << " times" << endl
       << "And you miss the shot " << notHit << " times" << endl << endl;
}
void spaceInvaders( void ){
  
  int const SIZE_E = 100;
  int const SIZE_N = 25;
  int const SIZE_H = 5;
  int const RADAR_E = 20;
  int const RADAR_N = 6;
  int const RADAR_H = 2;
  int size , radar;
  double CANNON_X = 2500;
  double CANNON_Y = 0;
  double INI_HORI_ANGLE = 90;
  double INI_VERTI_ANGLE = 45;
  int difficulty;
  double const INI_ET_Y = 5000;
  double iniETX; 
  double etX , etY;
  double INI_ET_V = 300;
  double etSpeed;
  int option;
  int hit , etCross , fired;
  int vertiAngle , horiAngle;
  int flashOrShell;
  int MAX_C_V;
  double percentage , cannonSpeed;
  double distance , distanceToTarget;
  double hitX , hitY;
  int hitTarget;
  double etAngle;
  double horiAngleChange;
  int horiAngleDirection;
  double vertiAngleChange; 
  
  srand(time(NULL));
  
  cout << "You will fire a cannon and try to hit the ET" << endl
       << "Your cannon is set at (2500,0) with elevation angle: 45" << endl
       << "and horizontal angle: 90(means north)" << endl
       << "What difficulty do you want? 1: easy, 2: normal, 3: hard:  ";
  cin  >> difficulty;
  while( difficulty != 1 && difficulty != 2 && difficulty != 3 ){
    cout << "It must be 1, 2 or 3, enter again: ";
    cin  >> difficulty;
  }
  if( difficulty == 1 ){
    size = SIZE_E;
    radar = RADAR_E;
  }
  else if( difficulty == 2 ){
    size = SIZE_N;
    radar = RADAR_N;
  }
  else{
    size = SIZE_H;
    radar = RADAR_H;
  }

    hit = 0;
    fired = 0;
    etCross = 0;
    vertiAngle = INI_VERTI_ANGLE;
    horiAngle = INI_HORI_ANGLE;
    
  	do{ // quit the game
    iniETX = rand() % 5000;
    etX = iniETX;
    etY = INI_ET_Y;
    hitTarget = 0;
    
    if( fired == 0 && etCross == 0 ){
	  etSpeed = INI_ET_V;
	}
	else{
	  etSpeed = etSpeed + rand() % 500;
	}
	
	if( etSpeed > 3000 ){
	  etSpeed = 500;
	}
       
    cout << "A new target appear at (" << etX <<"," << etY << ")" << endl;
      do{
        cout << "What are you going to do now?" << endl
             << "1. fire the cannon" << endl
             << "2. consult radar" << endl
             << "3. adjust the connon's horizontal angle" << endl
             << "4. adjust the cannon's elevation angle" << endl
             << "5. let this ET go" << endl
             << "6. quit the game" << endl
             << "Enter your choice(1~6):  ";
        cin  >> option;
        while( option < 1 || option > 6 ){
	      cout << "It must be 1 to 6. Enter again: ";
	      cin  >> option;
	    }
	    
	    if( option == 1 ){
		  cout << "Do you want to fire a flash grenade or shell?" << endl
		       << "1 for flash, 2 for shell:  ";
		  cin  >> flashOrShell;
		  while( flashOrShell != 1 && flashOrShell != 2 ){
		    cout << "It must be 1 or 2, Enter again: ";
		    cin  >> flashOrShell;
		  }
		  
		  cout << "Enter the percentage of maximum velocity of cannon(0~100): ";
		  cin  >> percentage;
		  while( percentage < 0 || percentage > 100 ){
		    cout << "It must be 0 to 100, Enter again: ";
		    cin  >> percentage;
		  }
		  cannonSpeed = percentage * MAX_C_V / 100;
		  
		  distance = horizontalDistanceCompute(vertiAngle , cannonSpeed);
	      destinationCompute( CANNON_X , CANNON_Y , horiAngle
	                     , distance , hitX , hitY);
	      distanceToTarget = distanceCompute( etX , etY , hitX , hitY);
	      
	      if( flashOrShell == 1 && distanceToTarget < 500 ){
            cout << "The ship has been sighted at ("
			     << etX << "," << etY << ")" << endl << endl;
		  }
		  else if( flashOrShell == 2 && distanceToTarget < size ){
		    cout << "You hit the target !!" << endl << endl;
		    hit++;
		    hitTarget = 1;
		  }
		  else{
		    cout << "Oops! The target is missed." << endl << endl;
		  }
		  fired++;
		}
	    else if( option == 2 ){
		  if( radar <= 0 ){
		    cout << "The radar is out of power!!" << endl << endl;
		  }
		  else{
		    etAngle = horizontalAngleCompute( CANNON_X , CANNON_Y
			                                  , etX , etY );
		    cout << "The horizontal angle between mortar and the ET is "
		         << etAngle << " degrees" << endl << endl;
		    radar--;
		  }
		}
		else if( option == 3 ){
		  cout << "which direction do want to shift?" << endl
		       << "1 for the right, 2 for the left:  ";
		  cin  >> horiAngleDirection;
		  while( horiAngleDirection != 1 && horiAngleDirection != 2 ){
		    cout << "It must be 1 or 2, enter again:  ";
		    cin  >> horiAngleDirection;
		  }
		  
		  cout << "How many degrees do you want to shift(0~30):  ";
		  cin  >> horiAngleChange;
		  while( horiAngleChange < 0 || horiAngleChange > 30 ){
		    cout << "It must be 0 to 30. Enter again:  ";
		    cin  >> horiAngleChange;
	      }
	      
	      if( horiAngleDirection == 1 ){
		    horiAngle = horiAngle + horiAngleChange;
		  }
		  else{
		    horiAngle = horiAngle - horiAngleChange;
		  }
		}
		else if( option == 4 ){
		  cout << "How many degree do you want to shift(-30 ~ 30):  ";
		  cin  >> vertiAngleChange;
		  while( vertiAngleChange < -30 || vertiAngleChange > 30 ){
		    cout << "It must be bwtween -30 to +30. Enter again: ";
		    cin  >> vertiAngleChange;
		  }
		  vertiAngle = vertiAngle + vertiAngleChange;
		  if( vertiAngle <= 10 ){
		    vertiAngle = 10;
		  }
		  else if( vertiAngle >= 80 ){
		    vertiAngle = 80;
		  }
		}
		if( option == 5 ){
		  etCross++;
		}
		else{
          etY = etY - etSpeed;
          if( etY + etSpeed >= 2000 && etY <= 2000 ){
		    cout << "ET's ship has passed another trip-wire" << endl
		         << "it is currently at (" << etX << "," << etY << ")"
				 << endl << endl;
		  }
          else if( etY < 0 ){
		    etCross++;
		  }
        }    
      }while( etY > 0 && option != 5 && option != 6 && hitTarget != 1 );
    }while( option != 6 && etCross != 10 );
    if( etCross == 10 ){
	  cout << "You have lost the game!!" << endl << endl;
	}

    cout << "You fired " << fired << " missiles" << endl
         << "You hit " << hit <<" ETs" << endl
         << etCross << " has Cross the border" << endl << endl; 
}
void yourGame( void ){

}
