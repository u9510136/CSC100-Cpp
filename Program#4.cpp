//Hsuan-Yu Lin Program #4
//Population Growth

#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){
	
  int overPopulation;
  double dieByOver;
  int method;
  int initial;
  double birthRate , deathRate;
  int immiRate , emiRate;
  int years , bunnies;
  char table;
  double growthRate , migrationRate;
  int totalBunnies;
  int numOfYears;
  char again;  
  
  cout << "This program computes the final population of bunnies by years"
       << endl << "or years to pass a specific number of bunnies." 
	   << endl << endl;
  

    cout << "First, enter the overcrowding threshold population of bunnies:  ";
    cin  >> overPopulation;
    while( overPopulation < 0 ){
	  cout << "Invalid number, it must be more than or equals to 0."
	       << " Enter again:  ";
	  cin  >> overPopulation;
	}
	cout << endl;
  
    cout << "Enter the percentage that die from overpopulation(%):  ";
    cin  >> dieByOver;
    while ( dieByOver < 0 || dieByOver > 100 ){
	  cout << "Invalid number, it must be between 0 to 100. Enter again(%):  ";
	  cin  >> dieByOver;
    }   
    cout << endl;
    
  do{
	cout << "Do you want to compute the final population of bunnies by years"
	     << endl << " or years to pass a specific number of bunnies?" << endl
	     << "if it's first one, press 1, or press 2 for second one:   ";
    cin  >> method;
    while( method != 1 && method != 2 ){
	  cout << "Invalid number. Enter 1 or 2:  ";
	  cin  >> method;
	}
	cout << endl;
	
	cout << "What is the initial population of bunnies:  ";
	cin  >> initial;
	while( initial < 2 ){
	  cout << "Invalid number, it must be more than or equal to 2"
	       << " Enter again:  ";
	  cin  >> initial;  
	}
	cout << endl;
	
	cout << "What is the birthrate per year(%):  ";
	cin  >> birthRate;
	while( birthRate < 0 ){
	  cout << "Invalid number, it must be more than or equal to 0. "
	       << "Enter again:  ";
	  cin >> birthRate;
	}
	cout << endl;
	
	cout << "What is the deathtare per year?(0 ~ 100):  ";
	cin  >> deathRate;
	while( deathRate < 0 || deathRate > 100 ){
	  cout << "Invalid number, it must be between 0 to 100. Enter again:  ";
	  cin  >> deathRate;
	}
	cout << endl;
	
	cout << "Enter the immigration rate per year(# of bunnies, not %):  ";
	cin  >> immiRate;
	while( immiRate < 0 ){
	  cout << "Invalid number, it must be more than or equal to 0. "
	       << "Enter again:  ";
	  cin  >> immiRate;
	}
	cout << endl;
	
		cout << "Enter the emigration rate per year(# of bunnies, not %):  ";
	cin  >> emiRate;
	while( emiRate < 0 ){
	  cout << "Invalid number, it must be more than or equal to 0. "
	       << "Enter again:  ";
	  cin  >> emiRate;
	}
	cout << endl;
    
    if( method == 1 ){
	  cout << "How many years to compute the number of bunnies:  ";
	  cin >> years;
	  while ( years <= 0 ){
	    cout << "Invalid number, it must be positive. Enter again:  ";
	    cin  >> years;
	  }
	  cout << endl;
	}
	else{
	  cout << "How many bunnies do you want to see:  ";
	  cin >> bunnies;
	  while( bunnies < initial || bunnies > overPopulation ){
	    cout << "Invalid number, it must be between the initial number of "
	         << "bunnies and the overcrowding threshold bunnies." << endl
			 << "Enter again:  ";
		cin  >> bunnies;  
	  }
	  cout << endl;
	}
	
	cout << "Do you need a table to show the population of bunnies "
	     << "by every years?(y/n):  ";
	cin  >> table;
	while((table != 'y' && table != 'Y') && (table != 'n' && table != 'N')){
	  cout << "Invalid enter, it must be y or n. Enter again:  ";
	  cin  >> table;
	}
	cout << endl;
	
	growthRate = birthRate - deathRate;
	migrationRate = immiRate - emiRate;
	totalBunnies = initial;
	
	if( method == 1){
	  if(table == 'y' || table == 'Y' ){
	    cout << "Year    Population" << endl;
	  }
	  for ( int i = 0 ; i <= years ; i++ ){  
	    if(table == 'y'){
		  printf(" %3d    %10d\n", i , totalBunnies);
		}
		if ( i != years ){
		  totalBunnies = round(totalBunnies * ( 1 + growthRate / 100 )
		                 + migrationRate);
	    }
		if( totalBunnies > overPopulation && i != years ){
		  totalBunnies = round(totalBunnies * ( 1 - dieByOver / 100 ));
		}
	  }
	  cout << "The total bunnies after " << years << " is " << totalBunnies
	       << " bunnies." << endl << endl;
	}
	else{
	  if( table == 'y' || table == 'Y'){
	    cout << "Year    Population" << endl;
	  }
	  numOfYears = 0;
	  while(totalBunnies < bunnies ){
	    if (table == 'y' || table == 'Y'){
		  printf(" %3d    %10d\n", numOfYears , totalBunnies);
	    }
		if ( numOfYears != years ){
		  totalBunnies = round(totalBunnies * ( 1 + growthRate / 100 )
		                 + migrationRate);
	    }
		if( totalBunnies > overPopulation && numOfYears != years ){
		  totalBunnies = round(totalBunnies * ( 1 - dieByOver / 100 ));
		}
		numOfYears++;
	  }
	  if (table == 'y' || table == 'Y'){
	    printf( " %3d    %10d\n", numOfYears , totalBunnies);
	  }
	  cout << "The required years to pass " << bunnies << " bunnies are "
	       << numOfYears << endl << endl;
	}
	
	
    cout << "Do you want to try again?(y/n):  ";
    cin  >> again;
    while( again != 'y' && again != 'Y' && again != 'n' && again != 'N'){
	  cout << "Invalid enter, it must be y or n. Enter again:  ";
	  cin  >> again;
    }
    cout << endl;
  }while( again == 'y' );
  return 0;
}
