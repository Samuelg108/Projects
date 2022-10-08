//MAIN SCHOLARS FILE
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "class_SCHOLAR_.h"

  //-| Assignment ID:  PROG5
  //-| TEAM: Blue           
  //-| Author: gilbertJ334 Jarrett Gilbert
  //-| Author: goodmanS671 Samuel Goodman
  //-| Author: oscearS523 Shamaya Oscear

  //-------------------------------------------------------------------
  // Default constructor: Set ID to -1111, names to xxxxx and
  //         courseID to zzzzz, testsGiven to 0, each score to -1.
  //-------------------------------------------------------------------
  SCHOLAR_ :: SCHOLAR_ (  )
  {
      ID = -1111;
      Last = First = "xxxxx";
      CourseID="xxxx";
      testsGiven=0;
     for (int k=0;k<4;k++)
         Test[k] = -1;
  };

  //-------------------------------------------------------------------
  // Constructor: Set ID to -2222, names to argument values,
  //         courseID to ?????, testsGiven to 0, each score to -2.
  //-------------------------------------------------------------------
  SCHOLAR_ :: SCHOLAR_ ( string first, string last )
  {
       ID = -2222;
      Last = last;
      First = first;
      CourseID="zzzz";
      testsGiven=0;
     for (int k=0;k<4;k++)
         Test[k] = -2;
  };

  //-------------------------------------------------------------------
  // Constructor: Set ID to -3333, names to "tbd", courseID to empty
  //         string, testsGiven to 4, copy scores from array parameter
  //         into Test field.
  //-------------------------------------------------------------------
  SCHOLAR_ :: SCHOLAR_ ( int s[] )
  {
      ID = -3333;
      Last = First = "tbd";
      CourseID="";
      testsGiven=0;
     for (int k=0;k<4;k++)
         Test[k] = s[k];
  };



  //---------------------------------------------------------
  //---- MEMBER FUNCTION PROTOTYPES
  //---------------------------------------------------------
void SCHOLAR_ :: Show_Scholar( string label)
{
   cout << endl << label << ": | " << ID << " | "
       << Last + "," + First << " | "  << CourseID << " | "
       << testsGiven << " | " ;
  for (int k =0; k<4; k++) cout << Test[k] << " ";
  cout << "|\n";
};//Show_Scholar


void SCHOLAR_ :: Set_ID( int id  )
{
   ID = id;
};

void SCHOLAR_ :: Set_CourseID ( string courseID)
{
   CourseID = courseID;
};

void SCHOLAR_ :: Set_Name( string firstname, string lastname)
{
   First = firstname;
   Last = lastname;
};

void SCHOLAR_ :: Set_NumTests( int numtests)
{
   if (numtests >=1 && numtests <= 4)
      testsGiven = numtests;
  else
     cout << "\nERROR: BAD TEST# " << numtests << endl;
};

void SCHOLAR_ :: Set_TestScore( int testNum, int score)
{  if (testNum >=1 && testNum <= 4)
     Test[testNum-1] = score;
  else
     cout << "\nERROR: NO SUCH TEST #" << testNum << endl;
};//Set_TestScore

void SCHOLAR_ :: Set_TestScores( int numtests, int score[])
{
  for (int k=0; k<numtests;k++)
      Test[k] = score[k]; 
};//Set_TestScores

void SCHOLAR_ :: Read_Scholar ( )
{
  cout << endl;
  cout << "Enter record [ID FirstName LastName CourseID #tests 4scores]: ";
  cin >> ID >> First >> Last >> CourseID
>> testsGiven;
  for (int k=0; k<4; k++) cin >> Test[k];
};//Read_Scholar

void SCHOLAR_ :: Read_Scholar (istream & schF)
{
  SCHOLAR_ scholar;
  schF >> scholar.ID >> scholar.First >> scholar.Last >> scholar.CourseID
>> scholar.testsGiven;
  for (int k=0; k<4; k++) schF >> scholar.Test[k];

};

void SCHOLAR_ :: Write_Scholar (ostream & outF)
{
    outF << ID << " "
       << First << " " << Last << " "  << CourseID << " "
       << testsGiven;
  for (int k =0; k<4; k++) outF << " " << Test[k];
  outF << endl;
};

float SCHOLAR_ :: TestAverage( )
{
    float sum = 0.0;
  for (int k=0; k<testsGiven; k++)
      if (Test[k] > 0) sum += Test[k];
  if (testsGiven > 0)
     return sum / testsGiven;
  else
     return 0.0;
};

int SCHOLAR_ :: BestScore( )
{ 
   if ( testsGiven < 1) return -99;

  int best = Test[0];
  for (int k=1; k<testsGiven; k++)
      if (best < Test[k]) best = Test[k];
  return best;
};

void SCHOLAR_ :: List_MissingTests( string Label )
{
   cout << endl << Label << " MISSING TESTS: ";
  for (int k=0; k<testsGiven; k++)
      if ( Test[k] < 0) cout << k+1 << " ";
  cout << "END\n";
};

int main()
{
  //-|----------------------------------------------------------------------
  //-| 0. Display copyright.
  //-|----------------------------------------------------------------------
  cout << "\n\n(c) 2021, gilbertJ334 Jarrett Gilbert, oscearS523 Shamaya Oscear, goodmanS671 Samuel Goodman\n\n";

  //-|----------------------------------------------------------------------
  //-| 1. Create scholars S1, S4, S5, S6 using default constructor.
  //-|    Display S1.
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 1 ====\n";
  SCHOLAR_ S1, S4, S5, S6;
  S1.Show_Scholar("S1");   

  //-|----------------------------------------------------------------------
  //-| 2. Create scholar S2 for Pace Maker  using second constructor.
  //-|    Display S2.
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 2 ====\n";
  SCHOLAR_ S2("Pace","Maker");
  S2.Show_Scholar("S2");

  //-|----------------------------------------------------------------------
  //-| 3. Create scholar S3 with scores 0, 59,87, 0 using the third constructor.
  //-|    Display S3.
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 3 ====\n";
  int scores[] = {0,59,87,0};
  SCHOLAR_ S3(scores);
  S3.Show_Scholar("S3");

  //-|----------------------------------------------------------------------
  //-| 3a. Update S3 with name John Doe, and ID 2357.  Set courseID
  //-|     to "TEST123". Display S3.
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 3a ====\n";
  S3.Set_Name ("John", "Doe");
  S3.Set_CourseID("TEST123");
  S3.Set_ID(2357);
  S3.Show_Scholar("S3");

  //-|----------------------------------------------------------------------
  //-| 4. Load scholar S4 from the keyboard. Display S4.
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 4 ====\n";
  S4.Read_Scholar( );
  S4.Show_Scholar("S4");

  //-|----------------------------------------------------------------------
  //-| 5. Load scholar S5 and S6 from file 'students.txt'; Display S5, S6
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 5 ====\n";
  ifstream inF("students.txt");
  S5.Read_Scholar(inF);
  S5.Show_Scholar("S5");
  S6.Read_Scholar(inF);
  S6.Show_Scholar("S6");

  //-|----------------------------------------------------------------------
  //-| 6. Read a test# and score from keyboard. Update the score in S3.
  //-|    Display S3.
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 6 ====\n";
  int testNum, testScore;
  cout << "\nEnter test# and test score: ";
  cin >> testNum >> testScore;
  S3.Set_TestScore(testNum, testScore);
  S3.Show_Scholar("S3");

  //-|----------------------------------------------------------------------
  //-| 7. Read number of tests taken from keyboard.
  //-|    Update testsGiven in S3. Display S3.
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 7 ====\n";
  int numTests;
  cout << "\nEnter #tests taken: ";
  cin >> numTests;
  S3.Set_NumTests(numTests);
  S3.Show_Scholar("S3");

  //-|----------------------------------------------------------------------
  //-| 8. Compute the average test score for S3.  Display as
  //-|
  //-|          S3 AVERAGE = xx.xx
  //-|----------------------------------------------------------------------
  cout << fixed << showpoint;
  cout << "\nSTEP 8 ====\n";
  cout << "S3 AVERAGE = " << setprecision(2) << S3.TestAverage( ) << endl;

  //-|----------------------------------------------------------------------
  //-| 9. Read a test# and score from keyboard. Update the score in S3.
  //-|    Display S3. List missing scores in S3.
  //-|----------------------------------------------------------------------
  int pts;
  cout << "\nSTEP 9 ====\n";
  cout << "\nEnter test# [1-4] and a score: ";
  cin >> testNum >> pts;
  S3.Set_TestScore(testNum, pts);
  S3.Show_Scholar("S3");
  S3.List_MissingTests("S3");

  //-|----------------------------------------------------------------------
  //-| 10. Determine the highest test score for S3.
  //-|
  //-|          S3 HIGHEST SCORE = xx
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 10 ====\n";
  cout << "S3 HIGHEST SCORE = " << S3.BestScore( ) << endl;

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
  S6.Show_Scholar("S6");
  S6.List_MissingTests("S6");
  cout << endl;

  //-|----------------------------------------------------------------------
  //-| 12. Display S5. Then determine the highest test score for S5. Display as
  //-|
  //-|          S5 MAX TEST SCORE = xx
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 12 ====\n";
  cout << "S5 MAX TEST SCORE = " << S5.BestScore( ) << endl;

  //-|----------------------------------------------------------------------
  //-| 13. Write scholar records S1 - S7 to file 'allScholars.txt'.
  //-|----------------------------------------------------------------------
  cout << "\nSTEP 13 ====\n";
  ofstream outF("allScholars.txt");
  S1.Write_Scholar (outF);
  S2.Write_Scholar (outF);
  S3.Write_Scholar (outF);
  S4.Write_Scholar (outF);
  S5.Write_Scholar (outF);
  S6.Write_Scholar (outF);

  system ("more allScholars.txt");   

  //-|----------------------------------------------------------------------
  //-| Display copyright and stop.
  //-|----------------------------------------------------------------------
  cout << "\n\n(c) 2021, gilbertJ334 Jarrett Gilbert, oscearS523 Shamaya Oscear, goodmanS671 Samuel Goodman\n\n";


  return 0;
}//main