// ------------------------------------------------------------------
// File name:  menu_driven.cpp
// Assign ID:  PROG_7
// Due Date:   11/13/21 at 2359
//
// Purpose: Menu driven program that  manages scholar records from
// SCHOLAR_ class and ACADEMICS (vector) that allows for records to be
// added and removed.  
//
// Author: goodmanS671 Samuel Goodman
//         hoodD966 Donovan Hood
//         corbinR197 Rahsaan Corbin
//         thomasX622 Xavier Thomas
//
// ------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

#include "class_SCHOLAR_.h"
#include "class_ACADEMICS.h"
void ShowMenu()
  {    
  string Cmd[22] =
  {
   "--------------------------------------------------------------",
   "     Enter choice [H L V + I i v R D # X Q]:",
   "NOTE: entering H must produce the detailed HELP menu below:",
     "H - Provide detailed HELP menu",
     "L - Load container with all scholars in file allStudents.txt",
     "V - Display contents of container as a numbered list, e.g.,",
     "    [ 1] | xxx | xxx | xxx | xxx",
     "    [ 2] | xxx | xxx | xxx | xxx",
     "   ...  ",
     "+ - Add scholar to container.",
     "I - Sort collection ascending by ID",
     "i - Sort collection descending by ID",
     "v - Show specific scholar based on position (1,2,...)",
     "    or message: BAD POSITION xx",
     "R - Remove first scholar from container",
     "D - Drop/Remove last scholar from container",
     "# - Display size of container.",      
     "X - Build container (extract) students with test",
     "    average at or above threshold",
     "Q - terminate program",
     "------------------------------------------------------------",
   };
   
  for (int k=0; k<22; k++)
  {
     cout << "     " << Cmd[k] << endl;
  }
  cout << endl << endl;
 } // end ShowMenu


void PerformChoice(char choice, ACADEMICS & A)
{
    SCHOLAR_ S;
    int k, ID;
    bool success;
    float minAvg;
    ifstream allStud("allStudents.txt");
   
   switch (choice)
   {
     case 'H': ShowMenu();
               break;
           
     case 'L': cout << "\n Load container from file" << endl;
           if(allStud.fail())
           {
               cout << "\n File 'allStudents.txt'NOT FOUND. \n";
               return;
           }
           S.Read_Scholar (allStud, success);
           while(success)
           {
               A.Store_Last(S);
               S.Read_Scholar (allStud, success);
           }
               break;
           
     case 'V': cout <<"\n Display contents of container \n";
           A.Show("temp");
           break;
           
       case '+': cout << "\n Add a Scholar \n";
           S.Read_Scholar();
           A.Store_Last(S);
           break;
           
       case 'I': cout << "\n Sort collection ascending by ID \n";
           A.SortUpByID();
           break;
           
       case 'i': cout <<"\n Sort collection descending by ID \n";
           A.SortDownByID();
           break;
           
       case 'v': "\n Enter POSITION \n";
           cin >> k;
           if(k >= 1 && k <= A.Size())
           {
           cout << "\n Good position " << k << "\n";
           SCHOLAR_ S = A.get_Scholar(k);
           S.Show_Scholar("temp");    
           }
           else
               cout << "\n BAD POSITION" << k << "\n";
           break;
           
       case 'R': cout << "\n Remove first scholar \n";
           A.Remove_First();
           break;
           
       case 'D': cout << "\n Drop/Remove last scholar";
           A.Remove_Last();
           break;
           
       case '#': cout << "\n Dsplay size of container";
           A.Size();
           break;
           
       case 'X': cout << "\n Build container (extract) students with test average";
           cout << "Enter the Score: \n";
           cin >> minAvg;
           A.Select(minAvg);
           break;
           
     case 'Q': cout << "terminate program \n";
               break;

     default:  cout << "BAD MENU CHOICE -- ignored." << endl;
               break;
   }

}
 
int main()
{
   // ----------------------------------------------------------------------
   //  Declare variables
   // ----------------------------------------------------------------------
   char choice;   // Menu choice.
   ifstream studf;
   ACADEMICS A;
   
   do
   {
       cout << endl <<  " Enter choice [H L V + I i v R D # X Q]: ";
       cin >> choice;
       
       PerformChoice(choice, A);
   }
   while (choice != 'Q');
   
 
   return 0;

}//main

