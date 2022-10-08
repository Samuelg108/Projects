//---------------------------------------------------------------------------
// File name:   starter_students.cpp
// Assign ID:   sgoodman671 
// Due Date:    September 16, 2021 
// Purpose:     Split intput file based on GPAs, calculating average GPA within
//              each group and overall.
//
// Author:      sgoodman671
//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include "STUDENT.h"
using namespace std;

struct HISTORY
{
   string Term;    // Academic term, e.g., Fall2018.
   int NHonors;    // #Honors students.
   float avgHgpa;  // Avg GPA of honors students.
   int NGood;      // #students in good standing.
   float avgGgpa;  // Avg GPA of good-standing students.
   int NRisk;      // #at-risk students.
   float avgRgpa;  // Avg GPA of at-risk students.
};

void Show_History(HISTORY H)
{
   cout << showpoint << fixed << setprecision(3);
   cout << "\n\nACADEMIC HISTORY\n";
   cout << "====================================" << endl;
   cout << "====================================" << endl;
   cout << "ACADEMIC HISTORY\n";
   cout << endl;
}

//-| -----------------------------------------------------------------
//-| WRITE student copyright to output stream.
//-| -----------------------------------------------------------------
void Write_Copyright(int year,string login,string name,ostream & outF)
{
   outF << "\n\n(c) " << year << ", " + login + " " + name + "\n\n";
}//

//-| -----------------------------------------------------------------
//-| READ a STUDENT record from keyboard.
//-| -----------------------------------------------------------------
STUDENT Read_StudentData()
{
}//


//-| -----------------------------------------------------------------
//-| READ a STUDENT record from input file stream.
//-| -----------------------------------------------------------------
void Read_StudentData(STUDENT & Stud, istream & inF)
{
}//


//-| -----------------------------------------------------------------
//-| READ a STUDENT record from file and return true if successful.
//-| -----------------------------------------------------------------
bool Read_StudentData(istream & inF, STUDENT & S)
{
}//


//-| -----------------------------------------------------------------
//-| READ a STUDENT record from file and set success flag.
//-| -----------------------------------------------------------------
void Read_StudentData(istream & studF, STUDENT & T, bool & success)
{
}//


//-| -----------------------------------------------------------------
//-| WRITE a STUDENT record to output stream. GPA with 3 decimal places.
//-| -----------------------------------------------------------------
void Write_StudentData(const STUDENT & Rec, ostream & outF)
{
}//


int main()
{

              //================================================
              // Variable declarations. USE THESE!!!
              // NOTE the STYLE, clarity, consistency.
              //================================================

   string infileName;    // Name of input file of student records.
   string Term;          // Academic term.
   STUDENT S;            // Student record from file or keyboard.
   HISTORY H;            // History record compiled after inputs processed.

   int numStudents=0,    // Total #students in file and keyboard input.
       numHonors=0,      // #Honors students.
       numGood=0,        // #students in good standing.
       numRisk=0;        // #At-Risk students.

   float avgGPA=0.0,       // Overall average GPA. 
         avgHonorsGPA=0.0, // Average GPA of honors students. 
         avgGoodGPA=0.0,   // Average GPA of good-standing students. 
         avgRiskGPA=0.0;   // Average GPA of at-risk students. 

   float sumHonorsGPA=0, // Sum of honor student GPAs.
         sumGoodGPA=0,   // Sum of good-standing student GPAs.
         sumRiskGPA=0,   // Sum of at-risk student GPAs.
         sumGPA=0;       // Overall GPA sum of all students.

   ifstream studF;       // Stream for file input.
   ofstream riskF,       // Streams for known output files.
            honorsF,
            goodF;

   //-|-------------------------------------------------------------------- 
   //-| Display copyright.
   //-|-------------------------------------------------------------------- 
   Write_Copyright(2021, "goodmanS671", " Samuel Goodman", cout);

   //-|-------------------------------------------------------------------- 
   //-| 1. Read the term. 
   //-|-------------------------------------------------------------------- 
   cout << endl << "Enter academic term (e.g. Fall2021): ";
   cin >> Term;
    
   //-|-------------------------------------------------------------------- 
   //-| 2. Read name of input file, and open. Terminate if open failure.
   //-|--------------------------------------------------------------------  
   cout << endl << "Enter name of input file: ";
   cin >> infileName;
   studF.open(infileName.c_str());
   if (studF.fail())
   {
       cout << "FATAL ERROR: can not open file " <<
       infileName << " . . . TERMINATING" << endl;
       exit(1);
   }
    
   //-|-------------------------------------------------------------------- 
   //-| 3. Open output files: honors.txt, atRisk.txt and goodStanding.txt.
   //-|-------------------------------------------------------------------- 
   honorsF.open("honors.txt");
   riskF.open("atRisk.txt");
   goodF.open("goodStanding.txt");
    
   //-|-------------------------------------------------------------------- 
   //-| 4. REPEAT for each student in input file.
   //-| 4.1 Read record.
   //-| 4.2 Count student.
   //-| 4.3 Add GPA to sumGPA. 
   //-| 4.4 Determine standing of student.
   //-|     4.4.1 when Honors: numHonors++; Add GPA to sumHonorsGPA;
   //-|           write record to Honors file.:0:0:
   //-|     4.4.2 when At-Risk: numRisk++; Add GPA to sumRiskGPA.
   //-|           write record to atRisk file.
   //-|     4.4.3 otherwise: numGood++; Add GPA to sumGoodGPA.
   //-|           write record to goodStanding file.
   //-|-------------------------------------------------------------------- 
   //-| NOTE: No comments needed INSIDE the loop, since they are given
   //-|       as the numbered list 4.1 through 4.4.
   //-|-------------------------------------------------------------------- 
   while(Read_StudentData(studF, S)) // start loop body.
   {
   
   if(S.GPA >= 3.0)
   {
      numHonors++;
      sumHonorsGPA += S.GPA;
       Write_StudentData(S, honorsF)
   }
   else if(S.GPA < 2.2)
   {
       numRisk++;
       sumRiskGPA += S.GPA;
       Write_StudentData(S, riskF)
   }
   else if(S.GPA >= 2.2 && S.GPA < 3.0)
   {
       numGood++;
       sumGoodGPA += S.GPA;
       Write_StudentData(S, goodF)
   }
   }// end loop body.
   
   //-|-------------------------------------------------------------------- 
   //-| 5. Read record from keyboard.
   //-| 6. Count student.
   //-| 7. Add GPA to sumGPA. 
   //-|-------------------------------------------------------------------- 
   
 
   //-|-------------------------------------------------------------------- 
   //-| 8 Determine standing of student.
   //-|   8.1 when Honors: numHonors++; Add GPA to sumHonorsGPA;
   //-|           write record to Honors file.
   //-|   8.2 when At-Risk: numRisk++; Add GPA to sumRiskGPA.
   //-|           write record to atRisk file.
   //-|   8.3 otherwise: numGood++; Add GPA to sumGoodGPA.
   //-|           write record to goodStanding file.
   //-|-------------------------------------------------------------------- 
   if(nu)
   {
       
   }

   //-|-------------------------------------------------------------------- 
   //-| 9. Compute GPA averages. Avoid division by zero.
   //-|-------------------------------------------------------------------- 

   
   //-|-------------------------------------------------------------------- 
   //-| 10. Construct the history record.
   //-| 11. Display the history record.
   //-|-------------------------------------------------------------------- 


   Show_History(H);

   //-|-------------------------------------------------------------------- 
   //-| 12. Display overall student count and average GPA.
   //-|-------------------------------------------------------------------- 

   //-|-------------------------------------------------------------------- 
   //-| 13. Close all files after adding line: END <filename>
   //-|-------------------------------------------------------------------- 

   //-|-------------------------------------------------------------------- 
   //-| Display copyright.
   //-|-------------------------------------------------------------------- 
   Write_Copyright(2021, "teacherK123", "Dr. Jones", cout);


   //-|===================================================================
   //-| DO NOT TOUCH ... just viewing the files ...
   //-|===================================================================
   system("more honors.txt  goodStanding.txt  atRisk.txt ");
   string cmd = "more " + infileName;
   system(cmd.c_str());


   return 0;
}//main