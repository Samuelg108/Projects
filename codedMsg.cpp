//--------------------------------------------------------------
// File name:   codedMsg.cpp
// Assign ID:   Prog2
// Due Date:    September 8, 2021
// Purpose:     Decoding words to a order
//
// Author:      sgoodman671 Samuel Goodman
//--------------------------------------------------------------
#include <iostream> 
#include <iomanip>
#include <fstream>
using namespace std;
int main (){
  
    
    //-|-------------------------------------------------------- 
    //-| Print copyright notice to screem    
    //-|-------------------------------------------------------- 
    cout << "(c) 2021, sgoodman671 Samuel Goodman " << endl << endl;
    
    //--------------------------------------------------------- 
    //-| 1. Declare Variables    
    //--------------------------------------------------------- 
    int position;
    string word, message[8];
    
    //--------------------------------------------------------- 
    //-| 2. Get input for Encoded message    
    //--------------------------------------------------------- 
    cout << endl << "Enter ENCODED Sentence: ";
    cin >> position >> word;
  
    //--------------------------------------------------------- 
    //-| 3. Send position and word through while loop    
    //--------------------------------------------------------- 
    while (position != 0 && word != "-|")
    {
         
    if(position >= 1 && position <= 8)
    {
         message[position-1]=word;
    } if(position < 0 || position > 8)
            ;{
         cout << "BAD inputs: " << position << " + " << word << endl;
    }  
          cin >> position;
          cin >> word;
    } //while
    
   //--------------------------------------------------------- 
   //-| 4. Display coded message    
   //--------------------------------------------------------- 
   cout << "DECODED: ";
   for(int i=0; i<8; i++)
   {
   if(message[i]!="")
       {
           cout << message[i] << " ";
       }
   }
  cout << ".." << endl;
  };
 //--------------------------------------------------------- 
 //-| Print copyright notice to screem    
 //--------------------------------------------------------- 


