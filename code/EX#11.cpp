//Hsuan-Yu Lin(Sam) EX11
//  A sample program that computes volumes of four-sided pyramids
//    with square bases.

#include <iostream>
using namespace std;
#include <stdio.h>

void Hello( void );
void DisplayMenu( void );
void ComputeOnce( void );
void ComputeDifference( void );
void MakeTable( void );
void Goodbye( void );
void getParameter( double &side , double &height );
double pyramidVolume ( double side , double feet );

int main(  )
{
    int choice;

    Hello();

    do
    {
        DisplayMenu();
        cout << "Enter your selection: ";
        cin >> choice;

        if ( choice == 1 ) 
            ComputeOnce();
        else if ( choice == 2 )
            ComputeDifference();
        else if ( choice == 3 )
            MakeTable();
        else if ( choice != 4 )
        {
            cout << endl << "Please enter a number from 1 to 4"; 
            cout << endl << endl;
        }
    }
    while ( choice != 4 );

    Goodbye();

		return 0;
}

void Hello( void )
{
	cout << endl;
	cout << "          Pyramid Volume Calculations" << endl;
	cout << endl;
	cout << "   Compute the volume of square-based pyramids" << endl;
	cout << endl << endl;
}

void Goodbye( void )
{
	cout << endl;
	cout << "Have a nice day." << endl;
	cout << endl << endl;
}

void DisplayMenu( void )
{
	cout << endl;
	cout << "Choose from the following options..." << endl;
	cout << "(1) Compute the volume of one pyramid" << endl;
	cout << "(2) Compute the difference between" << endl;
	cout << "     the volume of two pyramids" << endl;
	cout << "(3) Make a table of pyramid volumes" << endl;
	cout << "(4) Exit the program" << endl;
}

void ComputeOnce( void )
{
  double side , height , volume;	
  
  getParameter( side , height );	  
  volume = pyramidVolume( side , height );
  
  cout << "The volume of pyramid is: " << volume << "(cube in feet)"
       << endl;
}

void ComputeDifference( void )
{
  double side1 , side2 , height1 , height2;
  double volume1 , volume2 , difference;
  
  cout << "1st pyramid:" << endl;
  getParameter( side1 , height1 );
  cout << "2nd pyramid:" << endl;
  getParameter( side2 , height2 );
  
  volume1 = pyramidVolume( side1 , height1 );
  volume2 = pyramidVolume( side2 , height2 );
  difference = volume1 - volume2;
  if( difference < 0 ){
    difference = -difference; 
  }
  
  cout << "The volume difference of 2 pyramids is: " << difference << endl; 
}

void MakeTable( void )
{
  cout << "MakeTable" << endl;
}

double pyramidVolume ( double side , double height ){
  
  double volume;
  
  volume = side * side * height / 3;
  
  return volume;
}

void getParameter( double &side , double &height ){
  
  do{
    cout << "Enter the side of the pyramid(feet):";
    cin  >> side;
  }while( side <= 0 );
  
  do{
    cout << "Enter the height of the pyramid(feet): ";
    cin  >> height;
  }while( height <= 0 );
  
}
