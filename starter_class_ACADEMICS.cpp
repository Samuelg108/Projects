// File name: class_ACADEMICS.cpp
// Purpose:   Implementation file for class ACADEMICS.
#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>
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
}//numToString

//---------------------------------------------------------------------
// Default constructor, initializes container to empty.
//---------------------------------------------------------------------
ACADEMICS :: ACADEMICS()
{ 
  C.resize(0);
}//constructor

