//-----------------------------------------------------------------------------
// Program description: tutorial for enumerated data type
//
// 02/01/17 by: Atomkey / atomkey.net
// GitHub: Arduino Adjunct and Prototype Studio
//-----------------------------------------------------------------------------
// create an enumerated data type for readability and to set names 
// for anything that is unique to your coding paradigm. 

void clearSerialMonitor(void); // function prototype

enum day_of_week {mon = 1, tue, wed, thu, fri, sat, sun};

day_of_week dow;   // declare a variable of enumerated type day_of_week
                   // this can also be declared at the end of the type
                   // definition before the ;
                   
int test;          // an interget to play with.

// if you don't set the initial value [mon=1] of the first item in
// your enum, it will default to zero. From the first item the
// remainder increment by 1. e.g if mon = 1, then tue = 2.
// you can also set explicit and/or intermittent values. 
//   enum planets {mercury = 3, venus = 10, earth = 100, mars = 20};
// and you can apply the same value to more than one name
//   enum decision {no_, yes_, dont_care = 0};
// no_ and dont_care are both zero. yes_ is 1.

/***********************************************************************setup**/
void setup()
{
  // open the serial monitor so you can see what is going on
  Serial.begin(9600);

  dow = 0;       // oops - I've set the variable out of scope. What happens?
  test = -1;     // let's use test as a counter [see below]
  clearSerialMonitor();
}

/************************************************************************loop**/
void loop()
{
    
  // dow++; // this doesn't work becuase the ++ operator is not recognized

              // but if you want to increment this type, you can do this..
  test++;     // on first iteration this should become zero
  dow = test; // type incremented

  // dow = tuesday; // but the beauty of the enum type is to write code that
                    // looks, organizes, and reads better  
  
  switch(dow)
   {
       case 0: Serial.println("out_of_range 0"); break;
     case mon: Serial.println("Monday");         break;
     case tue: Serial.println("Tuesday");        break;
     case wed: Serial.println("Wednesday");      break;
     case thu: Serial.println("Thrusday");       break;
     case fri: Serial.println("Friday");         break;
     case sat: Serial.println("Saturday");       break;
     case sun: Serial.println("Sunday");         break;
       case 8: Serial.println("out_of_range 8"); break;
   }

 if(test >= 8)              // at the end?
  {
     delay(1500);
     test = -1;             // start from the beginning
     clearSerialMonitor();  
  }

 delay(250);                // give me a moment to read the screen
}

/**********************************************************clearSerialMonitor**/
void clearSerialMonitor(void)
{
  int line_feed = 100;  
  // blast a bunch of line feeds to the serial monitor to wipe it clear
  while(line_feed--) Serial.println();  
}

// end of code [enum_example.ino]

//========== NOTES ==========
//Enumerated data types allow for the explicit assignment of values to user defined 
//names. This provides for more eloquent code that is easier to 'code/type-in' - organize, 
//and read. It also makes the interpretation of code to someone else easier to follow 
//when reading for the first time.
//
// output:
//
//out_of_range 0
//Monday
//Tuesday
//Wednesday
//Thrusday
//Friday
//Saturday
//Sunday
//out_of_range 8
