#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "SCHOLAR.h"

//========= CONSTRUCTORS for SCHOLAR.
//
//-------------------------------------------------------------------
// Default constructor: Set ID to -1111, names to xxxxx and
//         courseID to zzzzz, testsGiven to 0, each score to -1.
//-------------------------------------------------------------------
SCHOLAR :: SCHOLAR (  )
{
   ID = -1111; 
   Last = First = "xxxxx"; 
   CourseID="zzzzz"; 
   testsGiven=0;
   for (int k=0;k<4;k++) Test[k] = -1;
}

//-------------------------------------------------------------------
// Constructor: Set ID to -2222, names to argument values,
//         courseID to ?????, testsGiven to 0, each score to -2.
//-------------------------------------------------------------------
SCHOLAR :: SCHOLAR ( string first, string last )
{  
  ID = -2222;
  CourseID = ?????;
  testsGiven = 0;
  Test[k] = -2;
}

//-------------------------------------------------------------------
// Constructor: Set ID to -3333, names to "tbd", courseID to empty
//         string, testsGiven to 4, copy scores from array parameter
//         into Test field.
//-------------------------------------------------------------------
SCHOLAR :: SCHOLAR ( int s[Test[k] = -2] )
{
 ID = -3333;
 name = "tbd";
 CourseID = " ";
 testsGiven = 4;
}

//---------------------------------------------------------
//---- FUNCTION PROTOTYPES
//---------------------------------------------------------
void Show_Scholar( SCHOLAR , string);
void Set_ID( int id, SCHOLAR & );
void Set_CourseID ( string courseID, SCHOLAR & );;
void Set_Name( string firstname, string lastname, SCHOLAR & );
void Set_NumTests( int numtests, SCHOLAR & );
void Set_TestScore( int testNum, int score, SCHOLAR &);
void Set_TestScores( int numtests, int score[], SCHOLAR &);
void Read_Scholar ( SCHOLAR & );
SCHOLAR Read_Scholar (istream &);
void Write_Scholar (ostream &, SCHOLAR & );
float TestAverage( SCHOLAR );
int BestScore( SCHOLAR );
void List_MissingTests( string Label, SCHOLAR );

    // BONUS - for steps 13-16.

void Show_AllScholars (string Label, SCHOLAR s[], int numScholars );
void Save_Scholars (ostream & outF, SCHOLAR s[], int numScholars);
void Load_Scholars (istream & inF, SCHOLAR s[], int & numScholars);
float Class_TestAverage(int testNum, SCHOLAR s[], int numScholars);


int main()
{
  
   //-|---------------------------------------------------------------------- 
   //-| 0. Display copyright.
   //-|---------------------------------------------------------------------- 
   cout << "\n\n(c) 2021, teacherK123 Dr. Jones\n\n";

   //-|---------------------------------------------------------------------- 
   //-| 1. Create scholars S1, S4, S5, S6 using default constructor. 
   //-|    Display S1.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 1 ====\n";
   SCHOLAR.S1;
   SCHOLAR.S4;
   SCHOLAR.S5;
   SCHOLAR.S6; 
   printScholar(S1);
   //-|---------------------------------------------------------------------- 
   //-| 2. Create scholar S2 for Pace Maker  using second constructor. 
   //-|    Display S2.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 2 ====\n";
   
   //-|---------------------------------------------------------------------- 
   //-| 3. Create scholar S3 with scores 0, 59,87, 0 using the third constructor.
   //-|    Display S3.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 3 ====\n";
   
   //-|---------------------------------------------------------------------- 
   //-| 3a. Update S3 with name John Doe, and ID 2357.  Display S3.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 3a ====\n";

   //-|---------------------------------------------------------------------- 
   //-| 4. Load scholar S4 from the keyboard. Display S4.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 4 ====\n";

   //-|---------------------------------------------------------------------- 
   //-| 5. Load scholar S5 and S6 from file 'students.txt'; Display S5, S6
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 5 ====\n";
   ifstream inF("students.txt");

   //-|---------------------------------------------------------------------- 
   //-| 6. Display S3. Read a test# and score from keyboard. 
   //-|    Update the score in S3. Display S3.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 6 ====\n";

   //-|---------------------------------------------------------------------- 
   //-| 7. Read number of tests taken from keyboard. 
   //-|    Update testsGiven in S3. Display S3.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 7 ====\n";
   int numTests;


   //-|---------------------------------------------------------------------- 
   //-| 8. For S3 and S1: Display record, then compute the average test score.
   //-| 
   //-|          S3 AVERAGE = xx.xx
   //-|          S1 AVERAGE = xx.xx
   //-|---------------------------------------------------------------------- 
   cout << fixed << showpoint;
   cout << "\nSTEP 8 ====\n";

   //-|---------------------------------------------------------------------- 
   //-| 9. Repeat 2 times:
   //-|    9.1 Display S3. 
   //-|    9.2 List missing test scores in S3.
   //-|    9.3 Read a test# and test score from keyboard. 
   //-|    9.4 Update the corresponding test score in S3. 
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 9 ====\n";
   for (int t=1; t<=2; t++)
   {
   }

   //-|---------------------------------------------------------------------- 
   //-| 10. For S3 and S2: Display record and determine the highest test score.
   //-| 
   //-|          S3 HIGHEST SCORE = xx
   //-|          S2 HIGHEST SCORE = xx
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 10 ====\n";

   //-|---------------------------------------------------------------------- 
   //-| 11. Display S5. Then determine the highest test score for S5. Display as
   //-| 
   //-|          S5 MAX TEST SCORE = xx
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 11 ====\n";

   //-|---------------------------------------------------------------------- 
   //-| 12. Write scholar records S1 - S6 to file 'allScholars.txt'.
   //-|     Use system call to display contents of allScholars.txt
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 12 ====\n";
   ofstream allF("allScholars.txt");

   allF << endl;
   allF.close();

   cout << "\nallscholars.txt CONTENTS below:\n";
   system ("cat allScholars.txt");
 
   //-|---------------------------------------------------------------------- 
   //-| Display copyright and stop.
   //-|---------------------------------------------------------------------- 
   cout << "\n\n(c) 2021, teacherK123 Dr. Jones\n\n";
   return 0;

   //-|----------------------------------------------------------------------
   //-| ****** BONUS STARTS HERE ******** 
   //-|----------------------------------------------------------------------

   //-|----------------------------------------------------------------------
   //-| 13. Load student records from file 'bonusScholars.txt' into SCHOLAR array
   //-|     Class. Display all members in array Class.
   //-|----------------------------------------------------------------------
 

   //-|----------------------------------------------------------------------
   //-| 14. Compute test2 average for Class. Display average with 3 decimals.
   //-|     Compute test1 average for Class. Display average with 3 decimals.
   //-|     Compute test4 average for Class. Display average with 2 decimals.
   //-|     Compute test4 3verage for Class. Display average with 2 decimals.
   //-|----------------------------------------------------------------------
 

   //-|----------------------------------------------------------------------
   //-| 15. For each student in class, increase the taken score (>=0)
   //-|     on test 1 by 7 points.
   //-|     Display all members in Class.
   //-|     Display the class average for test 1 using 1 decimal place.
   //-|----------------------------------------------------------------------
 

   //-|----------------------------------------------------------------------
   //-| 16. Save Class array to file finalScholars.txt.
   //-|     Issue system call to display content of finalScholars.txt
   //-|----------------------------------------------------------------------
 

   //-|----------------------------------------------------------------------
   //-| Display copyright and stop.
   //-|----------------------------------------------------------------------
 

   return 0;
}//main

//---------------------------------------------------------
//---- FUNCTION BODIES.
//---------------------------------------------------------

//--------------------------------------------------------------------
// Display record in to screen with '|' separating fields.
//--------------------------------------------------------------------
void Show_Scholar( SCHOLAR S, string label)
{
}//Show_Scholar

//--------------------------------------------------------------------
// Set ID field.
//--------------------------------------------------------------------
void Set_ID( int id, SCHOLAR & s)
{
}//Set_ID

//--------------------------------------------------------------------
// Set CourseID field.
//--------------------------------------------------------------------
void Set_CourseID ( string courseID, SCHOLAR & S)
{
}//Set_CourseID

//--------------------------------------------------------------------
// Set name fields. 
//--------------------------------------------------------------------
void Set_Name( string firstname, string lastname, SCHOLAR & s)
{
}//Set_Name

//--------------------------------------------------------------------
// Set number of tests, if first argument is valid.
// Otherwise, display error message.
//--------------------------------------------------------------------
void Set_NumTests( int numtests, SCHOLAR & S)
{
   if (numtests >=1 && numtests <= 4)
       S.testsGiven = numtests;
}//Set_NumTests

//--------------------------------------------------------------------
// Set specified test score if testNum is valid.
// Otherwise, display error message.
//--------------------------------------------------------------------
void Set_TestScore( int testNum, int score, SCHOLAR & scholar)
{
}//Set_TestScore

//--------------------------------------------------------------------
// Set scores for all test from array parameter.
//--------------------------------------------------------------------
void Set_TestScores( int numtests, int score[], SCHOLAR & student)
{
}//Set_TestScores

//--------------------------------------------------------------------
// Read SCHOLAR record from keyboard.
//--------------------------------------------------------------------
void Read_Scholar ( SCHOLAR & s)
{
}//Read_Scholar

//--------------------------------------------------------------------
// Read SCHOLAR record from input file.
//--------------------------------------------------------------------
SCHOLAR Read_Scholar (istream & schF)
{
}//Read_Scholar

//--------------------------------------------------------------------
void Write_Scholar (ostream & outF, SCHOLAR & S )
//--------------------------------------------------------------------
{

   outF << endl;
}


//--------------------------------------------------------------------
// Compute and return average test score for student. Missed tests
// are worth 0 points.
//--------------------------------------------------------------------
float TestAverage( SCHOLAR student)
{
   float sum = 0.0;
}//TestAverage


//--------------------------------------------------------------------
// Return the highest score of the tests given for S3. Display as
// 
//--------------------------------------------------------------------
int BestScore( SCHOLAR pupil)
{
}//BestScore


//--------------------------------------------------------------------
// List all the tests missed by scholar. 
//--------------------------------------------------------------------
void List_MissingTests( string Label, SCHOLAR s)
{
}//List_MissingTests

//--------------------------------------------------------------------
// Return class average on specified test.
// NOTE: Return 0 when testNum is invalid.
// NOTE: Negative scores (test not taken) are not included in the 
//       calculation.
//--------------------------------------------------------------------
float Class_TestAverage(int testNum, SCHOLAR s[], int numScholars)
{
}//Class_TestAverage


//--------------------------------------------------------------------
// Load all scholars in input stream into array. 
//--------------------------------------------------------------------
void Load_Scholars (istream & inF, SCHOLAR s[], int & numScholars )
{
}//Load_Scholars


//--------------------------------------------------------------------
// Save all scholars in array to output stream. 
//--------------------------------------------------------------------
void Save_Scholars (ostream & outF, SCHOLAR s[], int numScholars )
{
}//Save_Scholars

//--------------------------------------------------------------------
// Display all scholars in the array to the screen.
//--------------------------------------------------------------------
void Show_AllScholars (string Label, SCHOLAR s[], int numScholars )
{
   string Tag[21] = {"1 ","2 ", "3 ", "4 ", "5 ", "6 ","7 ", "8 ", "9 ",
                       "10","11", "12", "13", "14", "15","16","17", "18",
                       "19", "20"};

}//Show_AllScholars

