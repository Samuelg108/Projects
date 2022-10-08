//-------------------------------------------------------------------------
// File name: test_ACADEMICS.cpp
// Purpose:   Test each member function of class_ACADEMICS.
// Rationale: Do this before building main program.
//-------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
#include "class_SCHOLAR_.h"
#include "class_ACADEMICS.h"
/*
//---------------------------------------------------------------------------
// Function to convert integer to 2-character string: 14 ==> "14", 4 ==> " 4".
//---------------------------------------------------------------------------
string numToString(int num)
{
   string digit[10]={"0","1","2","3","4","5","6","7","8","9"};
   string NUM="";
   if (num < 0) return "BADNUM";
   if (num > 100) return "TOOBIG";
   if (num >= 10)
   {
      NUM += digit[num/10];
      NUM += digit[num % 10];
   }
   else
      NUM += " " + digit[num];
   return NUM;
}//numToString
*/


void Show_Container(ACADEMICS & acad)
{
   SCHOLAR_ temp;
   cout << "\nENTERING Show_Container ... SIZE=" << acad.Size() << " ==========\n";

   cout << "\n***START ACADEMICS LIST: \n"; 
   for (int k=1; k<= acad.Size(); k++)
   {
      temp=acad.get_Scholar(k);
      temp.Show_Scholar("NEXT ");
   }
   cout << "\nEND ACADEMICS LIST ***\n"; 
}


int main()
{
   ACADEMICS A, PICK;  // Main, selected collections.

   SCHOLAR_ S, S2, S3, S4;

   cout << fixed << showpoint << setprecision(2);

   //-|--------------------------------------------------------------------------
   //-| TEST1. Test constructor: size should be 0.
   //-|--------------------------------------------------------------------------
   cout << "constructor:: COLLECTION size = " << A.Size() 
        << " ... 0 EXPECTED\n";


   //-|--------------------------------------------------------------------------
   //-| TEST2. Test member functions when collection is empty.
   //-|--------------------------------------------------------------------------
   cout << "testing EMPTY Found 123456: " << A.Found(123456) << endl;
   cout << "testing EMPTY Locate 123456: " << A.Locate (123456) << endl;

   cout << "testing SORT UP By ID:: " << endl;
   A.SortUpByID();
   A.Show("test_ACADMICS - Sort UP");

   cout << "testing SORT DOWN By ID:: " << endl;
   A.SortDownByID();
   A.Show("test_ACADMICS - Sort DOWN");

   //-|--------------------------------------------------------------------------
   //-| TEST3. Add 3 scholars to container, then repeat tests.
   //-|--------------------------------------------------------------------------
   S.Set_ID(124);
   S.Set_CourseID("EZ101");
   S.Set_Name("Miller", "Steven");
   int s[]={76,86,96,46};
   S.Set_TestScores(4, s);
   S.Set_NumTests(0);
   S.Show_Scholar("Record 1");
   A.Store_Last(S);

   S.Set_Name("Bobby", "Dawkins");
   S.Set_ID(4238);
   S.Set_NumTests(2);
   S.Show_Scholar("Record 2");
   A.Store_Last(S);
   S.Set_Name("Richard", "Jenkins");
   int t[]={100,100,100,100};
   S.Set_TestScores(4, t);
   S.Set_ID(9999990);
   A.Store_Last(S);
   S.Show_Scholar("Record 3");

   cout << "testing SORT UP By ID:: " << endl;
   A.SortUpByID();
   A.Show("AFTER SortUpByID");
   cout << "testing SORT DOWN By ID:: " << endl;
   A.SortDownByID();
   A.Show("AFTER SortDownByID");

   //-|--------------------------------------------------------------------------
   //-| TEST4. Add 3 more to container.
   //-|--------------------------------------------------------------------------
   S2 = S;
   S2.Set_ID(268833);
   S2.Set_CourseID("EZ592");
   S2.Set_Name("Smith", "Adams");
   S2.Set_NumTests(3);
   int s2[]={0,1,1,64};
   S2.Set_TestScores(4, s2);
   S2.Show_Scholar("Record 4");
   A.Store_Last(S2);
   cout << A.Size() << " IN CONTAINER\n";
   Show_Container(A);

   S3 = S;
   S3.Set_ID(338242);
   S3.Set_CourseID("HELP444");
   S3.Set_Name("Gettin", "Better");
   S3.Set_NumTests(0);
   int s3[]={88,96,93,100};
   S3.Set_TestScores(4, s3);
   S3.Show_Scholar("Record 5 ");
   A.Store_Last(S3);

   S4 = S;
   S4.Set_ID(2468012);
   S4.Set_CourseID("DONE999");
   S4.Set_Name("Almost", "Done");
   S4.Set_NumTests(1);
   int s4[]={100,96,93,100};
   S4.Set_TestScores(4, s4);
   S4.Show_Scholar("Record 6 ");
   A.Store_Last(S4);
 
   A.Show("6 SCHOLARS NOW");


   //-|--------------------------------------------------------------------------
   //-| TEST4. Test search operations. Known keys: 2468012 4328.
   //-|--------------------------------------------------------------------------
   int idlist[] = {2468012, 4328, 11111, 777};
   for (int t=0; t<4; t++)
   {
      cout << "\nTesting Locate for " << idlist[t] <<" ... RESULT = ";
      cout << A.Locate(idlist[t]) << endl;
      cout << "\nTesting Found for " << idlist[t] << " ... RESULT = ";
      cout << A.Found(idlist[t]) << endl;
   }

   //-|--------------------------------------------------------------------------
   //-| TEST5. Test sort operations. 
   //-|--------------------------------------------------------------------------
   A.Show("test_ACADMICS - BEFORE Sort UP");
   cout << "testing SORT UP By ID:: " << endl;
   A.SortUpByID();
   A.Show("test_ACADMICS - AFTER Sort UP");

   cout << "testing SORT DOWN By ID:: " << endl;
   A.SortDownByID();
   A.Show("test_ACADMICS - AFTER Sort DOWN");


   //-|--------------------------------------------------------------------------
   //-| TEST6. Test extraction.
   //-|     1. Show all test averages.
   //-|     2. Extract avg > 200  [0]
   //-|     3. Extract highest avg [1]
   //-|     4. Extract lowest avg [6];
   //-|     5. Extract lowest+.01 [5] 
   //-|     6. Extract above 0.00 [6]
   //-|--------------------------------------------------------------------------
   for (int k=0; k < A.Size(); k++)
   {
      SCHOLAR_ S = A.get_Scholar(k+1);
      cout << endl << S.ID << " SCHOLAR #" <<  k+1 << " testAVG = " << S.TestAverage();
   }
   cout << endl;
   float testAVG[] = {0.00, 200.0, 100.0, 0.05, 69.0};
   string testCASE[] = {"0.00", "200.0", "100.0", "0.05", "69.0"};

   for (int k=0; k<5; k++)
   {
      PICK = A.Select(testAVG[k]);
      PICK.Show(testCASE[k] + " SELECTION");
   }


   //-|--------------------------------------------------------------------------
   //-| TEST7. Delete Operations
   //-|     1. Show container A.
   //-|     2. Repeat 4 times:
   //-|        2.1 Delete first.
   //-|        2.2 Delete last.
   //-|        2.3 Show container A.
   //-|--------------------------------------------------------------------------
   A.Show("test_ACADMICS - BEFORE DELETIONS");
   for (int k=1; k <= 4; k++)
   {
      A.Remove_First();
      A.Remove_Last();
      cout << A.Size() << " REMAIN IN container A\n";
      A.Show("test_ACADMICS - AFTER DELETING first and last");
   }
   cout << endl;

   //-|--------------------------------------------------------------------------
   //-| TEST8. Test file read using file containing 3 records.
   //-|--------------------------------------------------------------------------
   cout << "\nTESTING SCHOLAR_ Read_Scholar (istream &, bool &)\n";
   ifstream scholarsF("test_scholars.txt");
   SCHOLAR_ testIn;
   bool goodRead;
   for (int c=1; c<=4; c++)
   {
      testIn.Read_Scholar(scholarsF, goodRead); 
      if ( goodRead )
         testIn.Show_Scholar("GOOD FILE READ");
       else
          cout << "\nBAD FILE READ #" << c << endl;
   }
   scholarsF.close();

   cout << endl; return 0;
}//main

