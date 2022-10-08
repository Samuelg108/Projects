//------------------------------------------------------------------
// File name:   class_ROBOT101.cpp
// Assign ID:   TERMproject
// Due Date:    12/9/2021      
//
// Purpose:     Base robot class implementation.
//
// Author:      goodman671 Samuel Goodman
//------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

#include "class_ROBOT101.h"

    // Constructor: default grid is (0,0) to (10,10); 
    // Make inactive, and set current position to (0,0).
    ROBOT101::ROBOT101()
    {
    xmin = ymin = 0;
    xmax = ymax = 10;
    curX = curY = 0;
    Active = false;
    }

     // Set grid to specified (Xmin, Ymin) to (Xmax, Ymax) only if
     // the grid is valid.. 
     void ROBOT101::Establish_Grid(float Xmin, float Ymin, float Xmax, float Ymax)
     {
        if (Xmin < 0 || Xmin > Xmax || Ymin < 0 || Ymin > Ymax || Ymax < 0 || Ymin < 0 ) 
           return;
         {
             xmin = Xmin,  
             ymin = Ymin,  
             xmax = Xmax,  
             ymax = Ymax;
         }
     }
     
     // Display the grid coordinates.
     void ROBOT101 :: Show_Grid(string Label)
     {
         cout << Label << " ( " << xmin << "," <<  ymin << " ) to ( " 
              << xmax << "," <<  ymax << " ) "
              << endl;
     }
     
     // Activate robot in specified starting position only if position is valid..
     void ROBOT101 :: StartUp (float xStart, float yStart)
     {
         if(xStart < xmin || xStart > xmax) return;
         if(yStart < ymin || yStart > ymax) return;
         curX = xStart;
         curY = yStart;
         Active = true;
     }
    
     // Return whether robot is active.
     bool ROBOT101 :: IsActive ()
     {
         return Active;
     }
    
     // Return current robot position x-coordinate..
     float ROBOT101 :: Get_Xcoord()
     {
         return curX;
     }
    
     // Return current robot position y-coordinate..
     float ROBOT101 :: Get_Ycoord()
     {
         return curY;
     }
     
     // Attempt move [ N S E W ] or [U D R L]. Return false when move prohibited.
     // due to: being inactive, or the move would take robot off grid.
     bool ROBOT101 :: Move (char direction)
     {
        if (!Active) return false;
    
        switch (direction)
    {
        case 'N':
        case 'U':
                 if (curY == ymax) return false;
                 curY = curY + 1;
                 return true;
                 break;
        case 'E':
        case 'R':
                 if (curX == xmax) return false;
                 curX = curX + 1;
                 return true;
                 break;
        case 'S':
        case 'D':
                 if (curY == ymin) return false;
                 curY = curY - 1;
                 return true;
                 break;
        case 'W':
        case 'L':
                 if (curX == xmin) return false;
                 curX = curX - 1;
                 return true;
                 break;
    }
     }

     // Show position of active robot; use caller-supplied label..
     void ROBOT101 :: Show_Position(string Label)
     {
         cout << Label << " (" << curX << "," <<  curY << ") " << endl;
     }

     // Shutdown (make robot inactive).
     void ROBOT101 :: ShutDown()
     {
          Active = false;
     }