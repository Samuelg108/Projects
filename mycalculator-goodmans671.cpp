// ----------------------------------------------------------------------
// File name:  mycalculator-goodman671.cpp
//
// AssignID:   PROG6
//
// Author:     goodmanS671, Samuel Goodman
//
// Purpose:    Implement a simple calculator class (implemention file), 
//             and perform a calculation via the main program.
//
// Operation:  User inputs have the following meaning:
//
//          =======    =================================================
//          command    Required action
//          -------    -------------------------------------------------
//             H     : display list of commands. 
//             B     : Turn ON calculator.
//             +     : add In to accumulator
//             -     : subtract In from accumulator
//             *     : multiply accumulator by In
//             /     : divide accumulator by In
//             < xx  : read an input value xx into In
//             >     : show last input value read.
//             A     : show current value in accumulator.
//             C     : Clear current value in accumulator to zero.
//             X     : turn OFF calculator
//          -------    -------------------------------------------------
//
//             =========================================================
// ----------------------------------------------------------------------

#include <iostream>
#include <cctype>         // **** contains upper/lower case conversion.
#include "class_CALCULATOR.h"

using namespace std;

// HELP: Display calculator commands and examples.
void ShowCommands();

// Perform user commands to manipulate the calculator.
void PerformCommand(char cmd, CALCULATOR & Calc)
{
  int inputVal;    // Input value.

  switch (toupper(cmd))
  {

    case 'B' : // Turn on calculator.
               break;

    case 'H' : // Display list of calculator commands.
               break;

    case '<' : cin >> inputVal;
               break;

    case 'X' : Calc.Turn_Off(); 
               cout << "Calculator Turned OFF\n"; 
               break;
          
    case '+' : Calc.Add();
               break;
         
    case '-' : Calc.Subtract();
               break;
          
    case '*' : Calc.Multiply();
               break;
          
    case '/' : Calc.Divide();
               break;
          
    case '>' : Calc.Get_In();
               break;
          
    case 'A' : Calc.Get_Acc();
               break;
     
    case 'C' : Calc.Clear_Acc();
               break;

    default:   cout << "UNKNOWN Command '" << cmd << "' ... retry" << endl;

  }//switch

}//PerformCommand




int main( )
{
   CALCULATOR C;  // Calculator object.

   char command;     // User command symbol.
   int  inValue;     // Input value from user.
   int accValue;     // Current value in accumlator.
   string cmdString  // List of user commands (a menu, of sorts)
        = "[ B < > A C R X + - * / % X H[elp]]" ;

   //-| ---------------------------------------------------------
   //-| 1. Display welcome message, then a help message containing
   //-|         all accumulator commands/operations.
   //-| ---------------------------------------------------------

   cout << "Welcome to myCalculator" << endl;
   cout << "(c) 2021, goodmanS671, Samuel Goodman\n\n";

   ShowCommands();

   //-| ---------------------------------------------------------
   //-| 2. Repeat until command 'X' is entered.
   //-|    2.1 Read a command.
   //-|    2.2 Perform the command.
   //-|    2.3 Display the accumulator value.
   //-| ---------------------------------------------------------
   do 
   {
      cout << "\n ... Enter Command " << cmdString << ": "; 
      cin >> command;

      PerformCommand(toupper(command), C);

      cout << "\nACCUMULATOR = " << C.Get_Acc();
   }//command_loop
   while (toupper(command) != 'X');

   //-| ---------------------------------------------------------
   //-| 3. Display termination message, then copyright.
   //-| ---------------------------------------------------------
   cout << endl << endl <<  "Terminating myCalculator" << endl << endl;
   cout << "(c) 2021, teacherK123, Dr. Jones" << endl << endl;

}//main

// Display commands and example.
void ShowCommands()
{
  string Cmd[22] = {
       "   =======    =======================================",
       "   command    Required action",
       "   -------    ---------------------------------------",
       "      B     : Turn ON accumulator",
       "      +     : add In to accumulator",
       "      -     : subtract In from accumulator",
       "      *     : multiply accumulator by In",
       "      /     : divide accumulator by In",
       "      %     : mod accumulator by In",
       "      < xx  : read an input value xx into In",
       "      >     : show last input value read.",
       "      A     : show current value in accumulator.",
       "      C     : Clear current value in accumulator to 0.",
       "      R     : Clear current value in In to 0.",
       "      H     : request THIS help menu.",
       "      X     : turn OFF calculator (exit program).",
       "   -------    ----------------------------------------",
       "      ",
       "   Example: B 3 + 5 - 4 / 2 entered as  < 3 + < 5 + < 4 - < 2 / A x",
       "          : b 3 * 3 * 3 * 3 entered as  < 3 + * * * > A  x ",
       "      "
                     };

  cout << endl << endl << "CALCULATOR COMMANDS/EXAMPLE:" << endl;
  for (int k=0; k<22;k++)
  {
     cout << "     " << Cmd[k] << endl;
  }
  cout << endl << endl;

}//ShowCommands