//Hsuan-Yu Lin(Sam) Program 6
//Weather station's record and data

#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

void loadFile( int day[] , double highTemp[] , double lowTemp[]
              , double windSpeed[] , int &numRecord );
void loadManual( int day[] , double highTemp[]
                , double lowTemp[] , double windSpeed[]
				, int &numRecord );
int mainMenu();
void displayData( int day[] , double highTemp[] , double lowTemp[]
                 , double windSpeed[] , int numRecord );
void oneDayRecord( int day[] , double highTemp[] , double lowTemp[]
                  , double windSpeed[] , int numRecord );
void WindChillEachDay( int day[] , double lowTemp[] , double windSpeed[]
                      , int numRecord );
void LargestTempDiff( int day[] , double highTemp[] , double lowTemp[]
                , int numRecord );
void dataAnalysis( double highTemp[] , double lowTemp[] , double windSpeed[]
                  , int numRecord );
void tableChartClient( double highTemp[] , double lowTemp[]
                      , double windSpeed[] , int numRecord );
double windChill( double wSpeed , double lTemp );
void avgMaxMin( double dataToAnalyze[] , int numRecord , double &avg
               , double &max , double &min );
void decadeCompute( double dataToAnalyze[] , int decade[] , int numRecord );
void tableChart( int tableOrChart , int decade[] );


int main(){
  
  int day[100];
  double highTemp[100];
  double lowTemp[100];
  double windSpeed[100];
  int numRecord;
  int loadType;
  int option;
  char loadMoreData;
  
  cout << "Welcome! this program helps you record data about the weather "
       << "including:  day(count from begining of the year), high and low "
       << "temperature(F), wind speed(miles/hr), and be able to analize them."
       << endl << endl;
  do{     
    cout << "Do you wnat to load data from file(press 1) or "
	     << " by manual(press 2): ";
    cin  >> loadType;
    while( loadType != 1 && loadType != 2 ){
      cout << "It must be 1 or 2, enter again: " << endl;
      cin  >> loadType;
    }
    if( loadType == 1 ){
      loadFile( day , highTemp , lowTemp , windSpeed , numRecord );
    }
    else{
      loadManual( day , highTemp , lowTemp , windSpeed , numRecord );
    }
    do{
      option = mainMenu();
      if( option == 1){
	    displayData( day , highTemp , lowTemp , windSpeed , numRecord );
	  }
	  else if( option == 2 ){
	    oneDayRecord( day , highTemp , lowTemp , windSpeed , numRecord );
      }
      else if( option == 3 ){
	    WindChillEachDay( day , lowTemp , windSpeed , numRecord );
	  }
	  else if( option == 4 ){
	    LargestTempDiff( day , highTemp , lowTemp , numRecord );
	  }
	  else if( option == 5 ){
	    dataAnalysis( highTemp , lowTemp , windSpeed , numRecord );
	  }
	  else if( option == 6 ){
	    tableChartClient( highTemp , lowTemp , windSpeed , numRecord );
	  }
    }while( option != 7 );
  
    cout << "Do you want to load another set of data?";
    cin  >> loadMoreData;
    
  }while( loadMoreData == 'y' );

  return 0;
}

//load data from the file
void loadFile( int day[] , double highTemp[] , double lowTemp[]
              , double windSpeed[] , int &numRecord ){

  fstream infile;
  char fileAddress[81];
  int i = 0 ;
  numRecord = 0;
  
  cout << "Enter the file address(e.g: C:\\temp\\data.txt or data.txt)" << endl;
  cin  >> fileAddress;
  
  infile.open( fileAddress , ios::in );
  
  do{
    infile >> day[i] >> highTemp[i] >> lowTemp[i] >> windSpeed[i];
    i++;
    if( day[i-1] != 0){
	  numRecord++ ;
    }     
  }while( day[i-1] != 0);
  
  infile.close();	  
}

//load data by user input
void loadManual( int day[] , double highTemp[] , double lowTemp[]
               , double windSpeed[], int &numRecord ){
	
	int i = 0;
	numRecord = 0;
	
	do{
	  cout << "Enter the ordinal day(counting from the beginning of the"
	       << " year, e.g. Feb 2 is 33. And enter 0 if you don't have"
		   << " any other data): " << endl;
	  cin  >> day[i];
	  if( day[i] != 0 ){
	    cout << "Enter the high temperature of the day(F): ";
	    cin  >> highTemp[i];
	    cout << "Enter the low temperature of the day(F): ";
	    cin  >> lowTemp[i];
	    cout << "Enter the wind speed of the day(miles/hr): ";
	    cin  >> windSpeed[i];
	    numRecord++;
	  }
	  else{
	    highTemp[i] = 0;
	    lowTemp[i] = 0;
	    windSpeed[i] = 0;
	  }
	  i++;
	}while( day[ i - 1 ] != 0 );
}

int mainMenu(){
  
  int option;
  
  cout << "Enter your option to display the data you want: " << endl
       << "1. Display the data in the file" << endl
       << "2. Display the high tempture, low tempture, wind speed and the "
	   << "wind chill of the record for a given day" << endl
	   << "3. Display the wind chill for each day" << endl
	   << "4. Dispaly the largest difference between high tempture of "
	   << "one day nad the low temperature of the next day" << endl
	   << "5. Display the average, the maximum and the minimum of one field"
	   << endl
	   << "6. Dsiplay a chart summarizing the distribution of the values of one"
	   << " field" << endl
	   << "7. Stop analyzing this collection of data" << endl; 
  cin  >> option;
  while( option < 1 || option > 7 ){
    cout << "it must be 1 to 7, enter again: ";
    cin  >> option;
  }
  
  return option;
}

void displayData( int day[] , double highTemp[] , double lowTemp[]
                 , double windSpeed[] , int numRecord ){
  int line = 0;
  int counter = line + 10;
  char conti;

  cout << "Day\tHTemp(F)\tLTemp(F)\tWSpeed(miles/hr)" << endl;
  do{
    for( int i = line ; i < counter ; i++ ){
      cout << day[i] << "\t" << highTemp[i] << "\t\t" << lowTemp[i] << "\t\t"
           << windSpeed[i] << endl;
    }
    line += 10;
    if( line + 10 <= numRecord ){
	  counter = line + 10;
	  cout << "Enter any letter to continue displaying the data: ";
	  cin  >> conti;
	}
	else if( line <= numRecord ){
	  counter = numRecord;
	  cout << "Enter any letter to continue displaying the data: ";
	  cin  >> conti;
	}

  }while( line <= numRecord );
}

void oneDayRecord( int day[] , double highTemp[] , double lowTemp[]
                  , double windSpeed[] , int numRecord ){
  int oneDay;
  int find = 0;
  double wChill;
  
  cout << "Enter the day you want to observe: ";
  cin  >> oneDay;
  for( int i =  0 ;  i < numRecord ; i++ ){
    if( oneDay == day[i] ){
	  wChill = windChill( lowTemp[i] , windSpeed[i] );
	  cout << "Day\tHTemp(F)\tLTemp(F)\tWSpeed(miles/hr)\tWChill(F)" << endl; 
	  cout << day[i] << "\t" << highTemp[i] << "\t\t" << lowTemp[i] << "\t\t"
           << windSpeed[i] << "\t\t\t" << wChill << endl << endl;
	} 
  }
  if( find == 0 ){
    cout << "No such day with data!!" << endl << endl;
  }
  			  
}

void WindChillEachDay( int day[] , double lowTemp[] , double windSpeed[]
                      , int numRecord ){
                      
  double wChill;
  
  cout << "Day\tLTemp(F)\tWSpeed(miles/hr)\tWchill(F)" << endl;
  
  for ( int i = 0 ; i < numRecord ; i++ ){
    wChill = windChill( windSpeed[i] , lowTemp[i] );
    cout << day[i] << "\t" << lowTemp[i] << "\t\t" << windSpeed[i] << "\t\t\t"
         << wChill << endl;
  }
}

void LargestTempDiff( int day[] , double highTemp[] , double lowTemp[]
                , int numRecord ){
  
  double maxDiff = 0;
  int targetDay;
  double diff;
  
  for( int i = 0 ; i < numRecord - 1 ; i++ ){
  	diff = highTemp[i] - lowTemp[ i + 1 ];
  	if( diff < 0 ){
	  diff = -diff;    
	}
    if( maxDiff < diff ){
	  maxDiff = diff;
	  targetDay = day[i];
	}
  }	
  
  cout << "The largest difference is " << maxDiff << " and it occured between "
       << targetDay << " and " << targetDay + 1 << endl << endl;	
}

void dataAnalysis( double highTemp[] , double lowTemp[] , double windSpeed[]
                  , int numRecord ){

  double dataToAnalyze[numRecord];
  double avg , max , min ;
  int field;
  
  cout << "Enter the field you want to analyze, 1 for high temperature, "
       << "2 for low temperature, 3 for wind speed:  ";
  cin  >> field;
  while( field < 1 || field > 3 ){
    cout << "It must be 1, 2 or 3, enter again:  ";
    cin  >> field;
  }
  
  if( field == 1 ){
    for( int i = 0 ; i < numRecord ; i++ ){
	  dataToAnalyze[i] = highTemp[i];
	}
  }
  else if( field == 2 ){
    for( int i = 0 ; i < numRecord ; i++ ){
	  dataToAnalyze[i] = lowTemp[i];
	}
  }
  else{
    for( int i = 0 ; i < numRecord ; i++ ){
	  dataToAnalyze[i] = windSpeed[i];
	}
  }
  
  avgMaxMin( dataToAnalyze , numRecord , avg , max , min );		
  
  cout << "The average is: " << avg << endl
       << "The maxumun is: " << max << endl
	   << "The minimum is: " << min << endl << endl;		  
}

void tableChartClient( double highTemp[] , double lowTemp[]
                      , double windSpeed[] , int numRecord ){
  
  double dataToAnalyze[numRecord];
  int tableOrChart;
  int decade[11];
  int field;
  
  cout << "Enter the field you want to analyze, 1 for high temperature, "
       << "2 for low temperature, 3 for wind speed:  ";
  cin  >> field;
  while( field < 1 || field > 3 ){
    cout << "It must be 1, 2 or 3, enter again:  ";
    cin  >> field;
  }
  
  if( field == 1 ){
    for( int i = 0 ; i < numRecord ; i++ ){
	  dataToAnalyze[i] = highTemp[i];
	}
  }
  else if( field == 2 ){
    for( int i = 0 ; i < numRecord ; i++ ){
	  dataToAnalyze[i] = lowTemp[i];
	}
  }
  else{
    for( int i = 0 ; i < numRecord ; i++ ){
	  dataToAnalyze[i] = windSpeed[i];
	}
  }
  
  cout << "Do you want a table(1) or a chart(2): ";
  cin  >> tableOrChart;
  while( tableOrChart < 1 || tableOrChart > 2 ){
    cout << "It must be 1 or 2, enter again: ";
    cin  >> tableOrChart;
  }
  
  decadeCompute( dataToAnalyze , decade , numRecord );
  tableChart( tableOrChart , decade );			  
}
//Wind Chill Compute
double windChill( double wSpeed , double lTemp ){
  
  double result;
  
  if( lTemp <= 50 && wSpeed > 3.0 ){
    result = 35.74 + 0.6215 * lTemp 
	         + ( 0.4275 * lTemp - 35.75 )* pow( wSpeed , 0.16 );
  }
  else{
    result = lTemp;
  }
  
  return result;
}

void avgMaxMin( double dataToAnalyze[] , int numRecord , double &avg
              , double &max , double &min ){
  double sum = 0;		
  max = dataToAnalyze[0];
  min = dataToAnalyze[0];
  
  for( int i = 0 ; i < numRecord ; i++ ){
    sum = sum + dataToAnalyze[i];
    if( max < dataToAnalyze[i] ){
      max = dataToAnalyze[i];
	}
	else if( min > dataToAnalyze[i] ){
	  min = dataToAnalyze[i];
	}
  }
  avg = sum / numRecord;
}

void decadeCompute( double dataToAnalyze[] , int decade[] , int numRecord ){
  
  int decadeCounter;
  
  for( int i = 0 ; i < 11 ; i++ ){
    decade[i] = 0;
  }
  
  for( int j = 0 ; j < numRecord ; j++ ){
  	if( dataToAnalyze[j] < 0 ){
	  decade[0]++;  
	}
	else if( dataToAnalyze[j] >= 110 ){
	  decade[10]++;
	}
	else{
      decadeCounter = dataToAnalyze[j] / 10;
	  decade[decadeCounter]++ ; 
    }
  }
  
}
void tableChart( int tableOrChart , int decade[] ){
  
  cout << "decade : count" << endl;
  for( int i = 0 ; i < 10 ; i++ ){
    printf("%5d    ", i * 10 );
    if( tableOrChart == 1 ){
	  cout << decade[i] << endl;
	}
	else{
	  for( int j = 0 ; j < decade[i] ; j++ ){
	    cout << "*";
	  }
	  cout << endl;
	}
  }
  cout << " 100+" << "    ";
  if( tableOrChart == 1 ){
    cout << decade[10] << endl << endl;
  }
  else{
    for( int k = 0 ; k < decade[10] ; k++ ){
	  cout << "*";
	}
	cout << endl << endl;
  }
}
