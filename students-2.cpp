g//---------------------------------------------------------------------------
// File name:   students.cpp
// Assign ID:   sgoodman671 
// Due Date:    September 17, 2021 
// Purpose:     Split intput file based on GPAs, calculating average GPA within
//              each group and overall.
//
// Author:      sgoodman671
//              (c) 2021, ewf
//Author: ewf
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
   cout << "====================================" << endl;   cout << "TERM: " << H.Term << endl;
   cout << right << setw(7) << H.NHonors << " Honors students" << endl;
   cout << right << setw(7) << H.avgHgpa << " Avg Honors GPA" << endl;
   cout << right << setw(7) << H.NGood << " Good-Standing students" << endl;
   cout << right << setw(7) << H.avgGgpa << " Avg Good-Standing GPA" << endl;
   cout << right << setw(7) << H.NRisk << " At-Risk students" << endl;
   cout << right << setw(7) << H.avgRgpa << " Avg At-Risk GPA" << endl;
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
    STUDENT S;
    
    cout << "Enter Student ID: ";
    cin >> S.ID;
    
    cout << "Enter First Name: ";
    cin >> S.First;
    
    cout << "Enter Last Name: ";
    cin >> S.Last;
    
    cout << "Enter Course Load: ";
    cin >> S.Load;
    
    cout << "Enter Total Credit Hours: ";
    cin >> S.Hours;
    
    cout << "Enter GPA: ";
    cin >> S.GPA;
    
    return S;
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
    inF >> S.ID >> S.First >> S.Last >> S.Load >> S.Hours >> S.GPA;
    if(inF.fail())
        return false;
    else 
        return true;
}//return inF.
// success =


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
    outF << showpoint << fixed << setprecision(3);
    
    outF << Rec.ID << " " << Rec.First << " " << Rec.Last
         << " " << Rec.Load << " " << Rec.Hours << " " << 
         Rec.GPA << " " << endl;
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
   cout << endl << "Enter academic term (e.g., Fall2021): ";
   cin >> Term;
    
   //-|-------------------------------------------------------------------- 
   //-| 2. Read name of input file, and open. Terminate if open failure.
   //-|--------------------------------------------------------------------  
   cout << endl << "Enter name of input file of student records: ";
   cin >> infileName;
   studF.open(infileName.c_str());
   if (studF.fail())
   {
       cout << "FATAL ERROR: Can not open file " <<
       infileName << " ... TERMINATING" << endl;
       exit(1);
   }
    
   //-|-------------------------------------------------------------------- 
   //-| 3. Open output files: honors.txt, atRisk.txt and goodStanding.txt.
   //-|-------------------------------------------------------------------- 
   honorsF.open("honors.txt");
   riskF.open("atRisk.txt");
   goodF.open("goodStanding.txt");
    
   //-|-------------------------------------------------------------------- 
   //-| 4. Repeat for each student in input file.
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
      Write_StudentData(S, honorsF);
   }
   else if(S.GPA < 2.2)
   {
      numRisk++;
      sumRiskGPA += S.GPA;
      Write_StudentData(S, riskF);
   }
   else if(S.GPA >= 2.2 && S.GPA < 3.0)
   {
      numGood++;
      sumGoodGPA += S.GPA;
      Write_StudentData(S, goodF);
   }
   }// end loop body.
   
   //-|-------------------------------------------------------------------- 
   //-| 5. Read record from keyboard.
   //-| 6. Count student.
   //-| 7. Add GPA to sumGPA. 
   //-|-------------------------------------------------------------------- 
   S = Read_StudentData();
   numStudents++;
   sumGPA = sumGPA + S.GPA;
 
   //-|-------------------------------------------------------------------- 
   //-| 8 Determine standing of student.
   //-|   8.1 when Honors: numHonors++; Add GPA to sumHonorsGPA;
   //-|           write record to Honors file.
   //-|   8.2 when At-Risk: numRisk++; Add GPA to sumRiskGPA.
   //-|           write record to atRisk file.
   //-|   8.3 otherwise: numGood++; Add GPA to sumGoodGPA.
   //-|           write record to goodStanding file.
   //-|-------------------------------------------------------------------- 
   if(S.GPA >= 3.00)
   {
       numHonors++;
       sumHonorsGPA = sumHonorsGPA + S.GPA;
       Write_StudentData(S, honorsF);
   }
   else if (S.GPA < 2.2)
   {
       numRisk++;
       sumRiskGPA = sumRiskGPA + S.GPA;
       Write_StudentData(S, riskF); 
   }
   else
   {
       numGood++;
       sumGoodGPA = sumGoodGPA + S.GPA;
       Write_StudentData(S, goodF);
    }

   //-|-------------------------------------------------------------------- 
   //-| 9. Compute GPA averages. Avoid division by zero.
   //-|-------------------------------------------------------------------- 
   if (numStudents != 0) avgGPA = sumGPA / numStudents;

   if (numHonors != 0) avgHonorsGPA = sumHonorsGPA / numHonors;
   
   if (numGood != 0) avgGoodGPA = sumGoodGPA / numGood;

   if (numRisk != 0) avgRiskGPA = sumRiskGPA / numRisk;

   //-|-------------------------------------------------------------------- 
   //-| 10. Construct the history record.
   //-| 11. Display the history record.
   //-|-------------------------------------------------------------------- 
   H.NHonors = numHonors;
    
   H.avgHgpa = avgHonorsGPA;
   
   H.NGood = numGood;
    
   H.avgGgpa = avgGoodGPA;
    
   H.NRisk = numRisk;
    
   H.avgRgpa = avgRiskGPA;
    
   H.Term = Term;

   Show_History(H);

   //-|-------------------------------------------------------------------- 
   //-| 12. Display overall student count and average GPA.
   //-|-------------------------------------------------------------------- 
   cout << "TOTAL #Students = " << numStudents << endl;
    
   cout << "AVERAGE GPA = " << avgGPA; 
   //-|-------------------------------------------------------------------- 
   //-| 13. Close all files after adding line: END <filename>
   //-|-------------------------------------------------------------------- 
   honorsF << "\n \n END honors" ;
   honorsF.close();
    
   goodF << "\n \n END goodStanding" ;
   goodF.close();
    
   riskF <<  "\n \n END atRisk" ;
   riskF.close();
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