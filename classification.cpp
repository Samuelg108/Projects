//---------------------------------------------------------------------------
// File name:   classification.cpp
// Assign ID:   Prog1
// Due Date:    August 31, 2021
// Purpose:     Determine how many students are in a classification
//
// Author:      goodmans671 Samuel Goodman
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main()
{
   //----------------------------------------------------------------------
   // 1. Declare variables
   //----------------------------------------------------------------------
    int credithrs, o=0, i=0, j=0, k=0, l=0;
    string full_name, classification;
    
   //-|----------------------------------------------------------------------
   //-|2. Print the copyright notice, to screen
   //-|----------------------------------------------------------------------
   cout << endl << endl << "(c) 2021, goodmans671 Samuel Goodman" << endl << endl; 


   //-|----------------------------------------------------------------------
   //-| 3. Read credit hours and Full Name
   //-|----------------------------------------------------------------------
   for (int p = 0; p <= 3; p++){
         
    cout << "Enter credit hours and full name (e.g, 14 Ed Jones): ";
    cin >> credithrs;
    getline(cin, full_name);
       
   //-|----------------------------------------------------------------------
   //-| 4. check classification and count classification
   //-|----------------------------------------------------------------------
    if (credithrs < 30){
        classification = "freshman";
        o++;
            
    } else if (credithrs >= 30 && credithrs <=59){
        classification = "sophomore";
        j++;
       
    } else if (credithrs >=60 && credithrs <=89){
        classification = "junior";
         k++;
      
    }else {
        classification = "senior";
        l++;
        
    }cout << endl << full_name << " (" << credithrs <<
        " credits) is a " << classification << "." << endl << endl;
    }
    
   //-|----------------------------------------------------------------------
   //-| 5. Print the classification count
   //-|----------------------------------------------------------------------
    cout << "Number of freshmen = " << o << endl << endl
         << "Number of sophomores = " << j<< endl << endl
         << "Number of juniors = " << k << endl << endl
         << "Number of seniors = " << l << endl;
    
   //-|----------------------------------------------------------------------
   //-|6. Print the copyright notice to monitor.
   //-|----------------------------------------------------------------------
   cout << endl << endl << "(c) 2021, goodmans671 Samuel Goodman" << endl << endl; 

   return 0;

}//main