//------------------------------------------------------------------------------
// File name: class_ACADEMICS.h
// Purpose:   Specification file for class ACADEMICS.
// HELP with vectors: https://www.cplusplus.com/reference/vector/vector/
// Author: goodmanS671 Samuel Goodman
//         hoodD966 Donovan Hood
//         corbinR197 Rahsaan Corbin
//         thomasX622 Xavier Thomas
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "class_SCHOLAR_.h"
#include "class_ACADEMICS.h"
     //---------------------------------------------------------------------------
     // UTILITY Function to convert integer to 2-character string: 
     // Example:  14 ==> "14", 4 ==> " 4".
     //
     // Purpose:  Use the string as the label when displaying all scholars.
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
     } 

     //---------------------------------------------------------------------
     // Default constructor, initializes container to empty.
     //---------------------------------------------------------------------
     ACADEMICS::ACADEMICS()
     {
         C.resize(0);
     }

     //---------------------------------------------------------------------
     // Return #scholars in container.
     //---------------------------------------------------------------------
     int ACADEMICS::Size()
     {
         return C.size();
     }

     //---------------------------------------------------------------------
     // Store scholar as last item in container.
     //---------------------------------------------------------------------
     void ACADEMICS::Store_Last(SCHOLAR_ s)
     {
         C.push_back(s);
     }

     //---------------------------------------------------------------------
     // Remove first scholar from container.
     //---------------------------------------------------------------------
     void ACADEMICS::Remove_First()
     {
         if (C.size() > 0)
             C.erase(C.begin());
     }

     //---------------------------------------------------------------------
     // Remove last scholar from container.
     //---------------------------------------------------------------------
     void ACADEMICS::Remove_Last()
     {
        if (C.size() > 0)
            C.pop_back();
     }

     //---------------------------------------------------------------------
     // Search for scholar by ID.
     //---------------------------------------------------------------------
     bool ACADEMICS::Found(int ID)
     {
        for(int i = 0; i < C.size(); i++)
        {
            if(ID == C[i].Get_ID())
            return true;
        }
    
		return false;
	 }

     //---------------------------------------------------------------------
     //Return index of scholar in collection.
     //---------------------------------------------------------------------
     int ACADEMICS::Locate(int ID)
     {
        for(int i = 0; i < C.size(); i++)
        {
           if(C[i].Get_ID() == ID)
               return i;
            
        }
         return -1;
     } 

     //---------------------------------------------------------------------
     // Sort collection in ascending order by ID
     //---------------------------------------------------------------------
     void ACADEMICS::SortUpByID()
     {
    if (C.size() == 0 ) return;
       for ( int pass = 1; pass <= C.size()-1; pass++)
           {
           for ( int k =0; k < C.size()-pass; k++)
           {
                if (C[k].Get_ID() > C[k+1].Get_ID() )
                {
                  SCHOLAR_ temp = C[k];
                  C[k] = C[k+1];
                  C[k+1] = temp;
                }           
           }
       }
     }


     //---------------------------------------------------------------------
     // Sort collection in descending order by ID.
     //---------------------------------------------------------------------
     void ACADEMICS::SortDownByID()
     {
     if (C.size() == 0 ) return;
     for ( int pass = 1; pass <= C.size()-1; pass++)
         {
           for ( int k =0; k < C.size()-pass; k++)
           {
                if (C[k].Get_ID() < C[k+1].Get_ID() )
                {
                  SCHOLAR_ temp = C[k];
                  C[k] = C[k+1];
                  C[k+1] = temp;
                  
                }
           }
         }
     }

     //---------------------------------------------------------------------
     // Create and return new ACADEMICS object containing only
     // scholars with average test score >= thresholdAvg.
     //---------------------------------------------------------------------
     ACADEMICS ACADEMICS::Select (float thresholdAvg)
     {
       ACADEMICS A;
       SCHOLAR_ S;213;
         for ( int t = 1; t <= C.size(); t++ )
         {
             if ( C[t].TestAverage() >= thresholdAvg)
             {
                 A.Store_Last(C[t]);
             }
         }
         return A;
     }

     //---------------------------------------------------------------------
     // Display all scholars..
     //---------------------------------------------------------------------
     void ACADEMICS::Show(string Label)
     {
        cout << endl << Label << endl;
        for (int i = 0; i < C.size(); i++ )
        {
            C[i].Show_Scholar("temp");
        }
     }

     //---------------------------------------------------------------------
     // Return k'th scholar object (k=1,2,3,...)
     // Precondition: k must be within range 1-size_of_collection.
     //---------------------------------------------------------------------
     SCHOLAR_ ACADEMICS::get_Scholar(int k)
     {
        if (k>=1 && k <= C.size())
            return C[k-1];
        else
        {
            SCHOLAR_ temp;
            return temp;
        }
     }
     