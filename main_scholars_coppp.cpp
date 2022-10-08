#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "SCHOLAR.h"

class SCHOLAR_
{
   int ID;           // ID.
   string Last,      // Scholar name.
          First;
   string CourseID;  // Course ID, eg., COP3014c.
   int testsGiven;   // #tests taken.
   int Test[4];      // Test scores. Negative ==> test not taken.

   SCHOLAR_ ( )
   {  ID = -1111; Last = First = "xxxxx"; CourseID="xxxx"; testsGiven=0;
      for (int k=0;k<4;k++) Test[k] = -1;
   }
   SCHOLAR_ ( string first, string last )
   {  ID = -2222; Last = last; First = first; CourseID="zzzz"; testsGiven=0;
      for (int k=0;k<4;k++) Test[k] = -2;
   }
   SCHOLAR_ ( int s[] )
   {  ID = -3333; Last = First = "tbd"; CourseID=""; testsGiven=0;
      for (int k=0;k<4;k++) Test[k] = s[k];
   }
};

SCHOLAR_
{  ID = -1111; Last = First = "xxxxx"; CourseID="xxxx"; testsGiven=0;
      for (int k=0;k<4;k++) Test[k] = -1;
}
SCHOLAR_ :: SCHOLAR_ ( string first, string last )
{  ID = -2222; Last = last; First = first; CourseID="zzzz"; testsGiven=0;
      for (int k=0;k<4;k++) Test[k] = -2;
}
SCHOLAR_ :: SCHOLAR_ ( int s[] )
{  ID = -3333; Last = First = "tbd"; CourseID=""; testsGiven=0;
      for (int k=0;k<4;k++) Test[k] = s[k];
}
//---------------------------------------------------------
//---- FUNCTION PROTOTYPES
//---------------------------------------------------------
    void Show_Scholar( SCHOLAR_ , string);
    void Set_ID( int id, SCHOLAR_ & );
    void Set_CourseID ( string courseID, SCHOLAR_ & );;
    void Set_Name( string firstname, string lastname, SCHOLAR_ & );
    void Set_NumTests( int numtests, SCHOLAR & );
    void Set_TestScore( int testNum, int score, SCHOLAR_ &);
    void Set_TestScores( int numtests, int score[], SCHOLAR_ &);
    void Read_Scholar ( SCHOLAR_ & );
    SCHOLAR_ Read_Scholar (istream &);
    void Write_Scholar (ostream &, SCHOLAR_ & );
    float TestAverage( SCHOLAR_ );
    int BestScore( SCHOLAR_ );
    void List_MissingTests( string Label, SCHOLAR_ );


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
   SCHOLAR_ S1, S4, S5, S6;
   Show_Scholar.S1, "S1";

   //-|---------------------------------------------------------------------- 
   //-| 2. Create scholar S2 for Pace Maker  using second constructor. 
   //-|    Display S2.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 2 ====\n";
   SCHOLAR_.S2("Pace","Maker");
   Show_Scholar.S2, "S2";

   //-|---------------------------------------------------------------------- 
   //-| 3. Create scholar S3 with scores 0, 59,87, 0 using the third constructor.
   //-|    Display S3.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 3 ====\n";
   int scores[] = {0,59,87,0};
   SCHOLAR_ S3(scores);
   Show_Scholar.S3, "S3";
   
   //-|---------------------------------------------------------------------- 
   //-| 3a. Update S3 with name John Doe, and ID 2357.  Set courseID 
   //-|     to "TEST123". Display S3.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 3a ====\n";
   Set_Name ("John", "Doe", S3);
   Set_CourseID("TEST123", S3);
   Set_ID(2357, S3);
   Show_Scholar.S3, "S3";

   //-|---------------------------------------------------------------------- 
   //-| 4. Load scholar S4 from the keyboard. Display S4.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 4 ====\n";
   Read_Scholar.S4;
   Show_Scholar.S4, "S4";

   //-|---------------------------------------------------------------------- 
   //-| 5. Load scholar S5 and S6 from file 'students.txt'; Display S5, S6
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 5 ====\n";
   ifstream inF("students.txt");
   S5 = Read_Scholar(inF);
   Show_Scholar(S5, "S5");
   S6 = Read_Scholar(inF);
   Show_Scholar(S6, "S6");

   //-|---------------------------------------------------------------------- 
   //-| 6. Read a test# and score from keyboard. Update the score in S3. 
   //-|    Display S3.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 6 ====\n";
   int testNum, testScore;
   cout << "\nEnter test# and test score: ";
   cin >> testNum >> testScore;
   Set_TestScore(testNum, testScore, S3);
   Show_Scholar(S3, "S3");

   //-|---------------------------------------------------------------------- 
   //-| 7. Read number of tests taken from keyboard. 
   //-|    Update testsGiven in S3. Display S3.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 7 ====\n";
   int numTests;
   cout << "\nEnter #tests taken: ";
   cin >> numTests;
   Set_NumTests(numTests, S3);
   Show_Scholar(S3, "S3");


   //-|---------------------------------------------------------------------- 
   //-| 8. Compute the average test score for S3.  Display as
   //-| 
   //-|          S3 AVERAGE = xx.xx
   //-|---------------------------------------------------------------------- 
   cout << fixed << showpoint;
   cout << "\nSTEP 8 ====\n";
   cout << "S3 AVERAGE = " << setprecision(2) << TestAverage(S3) << endl; 

   //-|---------------------------------------------------------------------- 
   //-| 9. Read a test# and score from keyboard. Update the score in S3. 
   //-|    Display S3. List missing scores in S3.
   //-|---------------------------------------------------------------------- 
   int pts;
   cout << "\nSTEP 9 ====\n";
   cout << "\nEnter test# [1-4] and a score: ";
   cin >> testNum >> pts;
   Set_TestScore(testNum, pts, S3);
   Show_Scholar(S3, "S3");
   List_MissingTests("S3 ", S3);

   //-|---------------------------------------------------------------------- 
   //-| 10. Determine the highest test score for S3.
   //-| 
   //-|          S3 HIGHEST SCORE = xx
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 10 ====\n";
   cout << "S3 HIGHEST SCORE = " << BestScore(S3) << endl;

 
   //-|---------------------------------------------------------------------- 
   //-| 11. Display S6. Then list the missing test scores for S6.  Display as
   //-| 
   //-|          S6 MISSING TESTS: xx xx xx xx  END  
   //-|     
   //-|     Examples:
   //-| 
   //-|          S6 MISSING TESTS: 1 4 END  
   //-|          S6 MISSING TESTS: END  
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 11 ====\n";
   Show_Scholar(S6, "S6");
   List_MissingTests("S6 ", S6);
   cout << endl;


   //-|---------------------------------------------------------------------- 
   //-| 12. Display S5. Then determine the highest test score for S5. Display as
   //-| 
   //-|          S5 MAX TEST SCORE = xx
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 12 ====\n";
   cout << "S5 MAX TEST SCORE = " << BestScore(S5) << endl;

   //-|---------------------------------------------------------------------- 
   //-| 13. Write scholar records S1 - S7 to file 'allScholars.txt'.
   //-|---------------------------------------------------------------------- 
   cout << "\nSTEP 13 ====\n";
   ofstream outF("allScholars.txt");
   Write_Scholar (outF, S1);
   Write_Scholar (outF, S2);
   Write_Scholar (outF, S3);
   Write_Scholar (outF, S4);
   Write_Scholar (outF, S5);
   Write_Scholar (outF, S6);

   system ("more allScholars.txt");
  
   //-|---------------------------------------------------------------------- 
   //-| Display copyright and stop.
   //-|---------------------------------------------------------------------- 
   cout << "\n\n(c) 2021, teacherK123 Dr. Jones\n\n";
   

   return 0;
}//main

//---------------------------------------------------------
//---- FUNCTION BODIES.
//---------------------------------------------------------

//--------------------------------------------------------------------
// Display record in to screen with '|' separating fields.
//--------------------------------------------------------------------
void Show_Scholar( SCHOLAR_ S, string label)
{
   cout << endl << label << ": | " << S.ID << " | " 
        << S.Last + "," + S.First << " | "  << S.CourseID << " | " 
        << S.testsGiven << " | " ;
   for (int k =0; k<4; k++) cout << S.Test[k] << " ";
   cout << "|\n";
}//Show_Scholar

//--------------------------------------------------------------------
// Set ID field.
//--------------------------------------------------------------------
void Set_ID( int id, SCHOLAR_ & s)
{
   s.ID = id;
}//Set_ID

//--------------------------------------------------------------------
// Set CourseID field.
//--------------------------------------------------------------------
void Set_CourseID ( string courseID, SCHOLAR_ & S)
{
   S.CourseID = courseID;

}//Set_CourseID

//--------------------------------------------------------------------
// Set name fields. 
//--------------------------------------------------------------------
void Set_Name( string firstname, string lastname, SCHOLAR & s)
{
   s.First = firstname;   s.Last = lastname;
}//Set_Name

//--------------------------------------------------------------------
// Set number of tests, if first argument is valid.
// Otherwise, display error message.
//--------------------------------------------------------------------
void Set_NumTests( int numtests, SCHOLAR_ & S)
{
   if (numtests >=1 && numtests <= 4)
       S.testsGiven = numtests;
   else
      cout << "\nERROR: BAD TEST# " << numtests << endl;
}//Set_NumTests

//--------------------------------------------------------------------
// Set specified test score if testNum is valid.
// Otherwise, display error message.
//--------------------------------------------------------------------
void Set_TestScore( int testNum, int score, SCHOLAR_ & scholar)
{
   if (testNum >=1 && testNum <= 4)
      scholar.Test[testNum-1] = score;
   else
      cout << "\nERROR: NO SUCH TEST #" << testNum << endl;
}//Set_TestScore

//--------------------------------------------------------------------
// Set scores for all test from array parameter.
//--------------------------------------------------------------------
void Set_TestScores( int numtests, int score[], SCHOLAR_ & student)
{
   for (int k=0; k<numtests;k++)
       student.Test[k] = score[k];  
}//Set_TestScores

//--------------------------------------------------------------------
// Read SCHOLAR record from keyboard.
//--------------------------------------------------------------------
void Read_Scholar ( SCHOLAR_ & s)
{
   cout << endl;
   cout << "Enter record [ID FirstName LastName CourseID #tests 4scores]: ";
   cin >> s.ID >> s.First >> s.Last >> s.CourseID 
       >> s.testsGiven;
   for (int k=0; k<4; k++) cin >> s.Test[k];
}//Read_Scholar

//--------------------------------------------------------------------
// Read SCHOLAR record from input file.
//--------------------------------------------------------------------
SCHOLAR Read_Scholar (istream & schF)
{
   SCHOLAR_ scholar;
   schF >> scholar.ID >> scholar.First >> scholar.Last >> scholar.CourseID 
       >> scholar.testsGiven;
   for (int k=0; k<4; k++) schF >> scholar.Test[k];
   return scholar;
}//Read_Scholar

//--------------------------------------------------------------------
void Write_Scholar (ostream & outF, SCHOLAR_ & S )
//--------------------------------------------------------------------
{
   outF << S.ID << " " 
        << S.First << " " << S.Last << " "  << S.CourseID << " " 
        << S.testsGiven;
   for (int k =0; k<4; k++) outF << " " << S.Test[k];
   outF << endl;
}


//--------------------------------------------------------------------
// Compute and return average test score for student. Missed tests
// are worth 0 points.
//--------------------------------------------------------------------
float TestAverage( SCHOLAR_ student)
{
   float sum = 0.0;
   for (int k=0; k<student.testsGiven; k++)
       if (student.Test[k] > 0) sum += student.Test[k];
   if (student.testsGiven > 0)
      return sum / student.testsGiven;
   else
      return 0.0;
}//TestAverage


//--------------------------------------------------------------------
// Return the highest score of the tests given for S3. D
// Return -99 when no tests have been given.
//--------------------------------------------------------------------
int BestScore( SCHOLAR_ pupil)
{
   if ( pupil.testsGiven < 1) return -99;

   int best = pupil.Test[0];
   for (int k=1; k<pupil.testsGiven; k++)
       if (best < pupil.Test[k]) best = pupil.Test[k];
   return best;
}//BestScore


//--------------------------------------------------------------------
// List all the tests missed by scholar. 
//--------------------------------------------------------------------
void List_MissingTests( string Label, SCHOLAR_ s)
{
   cout << endl << Label << " MISSING TESTS: ";
   for (int k=0; k<s.testsGiven; k++)
       if ( s.Test[k] < 0) cout << k+1 << " ";
   cout << "END\n";
}//List_MissingTests

//--------------------------------------------------------------------
// Return class average on specified test.
// NOTE: Return 0 when testNum is invalid.
// NOTE: Negative scores (test not taken) are not included in the 
//       calculation.
//--------------------------------------------------------------------
float Class_TestAverage(int testNum, SCHOLAR s[], int numScholars)
{
   float sum = 0.00;
   int numScores = 0;

   if (testNum < 1 || testNum > 4)
   {
      cout << "\nClass_TestAverage ERROR: BAD TEST# " << testNum << endl;
      return 0.00; 
   }

   for (int k=0; k<numScholars; k++)
   {
      if (s[k].Test[testNum-1] >= 0)
      {
          sum += s[k].Test[testNum-1];
          numScores++;
      }
   }

   if (numScores > 0)
      return sum / numScores;
   else
      return 0.0;
}//Class_TestAverage


//--------------------------------------------------------------------
// Load all scholars in input stream into array. 
//--------------------------------------------------------------------
void Load_Scholars (istream & inF, SCHOLAR_ s[], int & numScholars )
{
   SCHOLAR_ scholar;
   numScholars = 0;
   scholar = Read_Scholar(inF);
   while ( ! inF.fail() )
   {
       s[numScholars++] = scholar;
       scholar = Read_Scholar(inF);
   }
}//Load_Scholars


//--------------------------------------------------------------------
// Save all scholars in array to output stream. 
//--------------------------------------------------------------------
void Save_Scholars (ostream & outF, SCHOLAR_ s[], int numScholars )
{
   for (int k=0; k<numScholars; k++)
       Write_Scholar(outF, s[k]);
}//Save_Scholars

//--------------------------------------------------------------------
// Display all scholars in the array to the screen.
//--------------------------------------------------------------------
void Show_AllScholars (SCHOLAR s[], int numScholars )
{
   string Label[21] = {"1 ","2 ", "3 ", "4 ", "5 ", "6 ","7 ", "8 ", "9 ",
                       "10","11", "12", "13", "14", "15","16","17", "18",
                       "19", "20"};

   cout << "\nALL SCHOLARS BEGIN -------------\n\n";
   for (int k=0; k<numScholars; k++)
   {
       Show_Scholar(s[k], "Scholar"+Label[k]);
   }
   cout << "\nALL SCHOLARS END -------------\n\n";
}//Show_AllScholars


