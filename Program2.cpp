// Hsuan-Yu Lin(Sam) Program #2
// #(h) volume and weight of gold ring with setting

#include<iostream>
#include<math.h>
using namespace std;

int main(){

 double Vring, Wring, Rring, Sring, Lbox, Wbox, Hbox, CPpound, Tcost;
 const double PI = 3.14159;
 const double Dgold = 0.696759;
 
   cout << "Welcome to the volume and weight of gold ring calculation system"
        << endl << endl
        << "Please type in the radius of tube forming the ring (inches): ";
   cin >> Rring;
   cout << endl;
 
   cout << "Please type in the size of ring (inches)" << endl
      << "[when the ring is laid flat,measure from the center of" << endl
	  << "the empty circle formed by the ring on the perimeter," << endl
	  << "to the center of the tube forming the ring.]: ";
   cin >> Sring;
   cout << endl;
 
     cout << "Pleast type in the length of box setting (inches): ";
     cin >> Lbox;
     cout << endl;
 
     cout << "Please type in the width of box setting (inches): ";
     cin >> Wbox;
     cout << endl;
 
     cout << "Please type in the height of box setting (inches): ";
     cin >> Hbox;
     cout << endl;
 
     cout << "Please tpye in the cost of gold ring per pound: ";
     cin >> CPpound;
     cout << endl;
 
   Vring = 2 * pow(PI,2) * Sring * pow(Rring,2) + Lbox * Wbox * Hbox;
   Wring = Vring * Dgold;
   Tcost = CPpound * Wring;
 
   cout << "Tube and size of ring is: " << Rring << " , " << Sring 
        << " (inches)" << endl
		<< "Length, width and height of box is: " 
		<< Lbox << " , " << Wbox << " , " << Hbox
		<< " (inches)" << endl << endl 
        << "Volume of gold ring is: " << Vring << " (cube in inches)" << endl
        << "Weight of gold ring is: " << Wring << " (pounds)" << endl
        << "Total cost of gold ring is: $" << Tcost << endl 
        << "Have a nice day!" << endl;
  	   
return 0;
}
