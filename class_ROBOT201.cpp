//------------------------------------------------------------------
// File name:   class_ROBOT201.cpp
// Assign ID:   TERMproject
// Due Date:    12/9/2021      
//
// Purpose:     Base robot class implementation.
//
// Author:      goodmanS671 Samuel Goodman
//------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifndef LOCATION_STRUCT
#define LOCATION_STRUCT
struct LOCATION
{
   float xpos, ypos;
};
#endif

#include "class_ROBOT101.h"
#include "class_ROBOT201.h"

//-----------------------------------------------------------------
// Constructor: use specified grid (MINx, MINy) to (MAXx, MAXy)..
//-----------------------------------------------------------------
ROBOT201 :: ROBOT201( ) : ROBOT101()
{
   inService = false;
   Current.xpos = Current.ypos = 0;
   gridLO.xpos = gridLO.ypos = 0;
   gridHI.xpos = gridHI.ypos = 20;
   Power = 500;
   totDist = 0;
}
// Set Grid.
     void ROBOT201 :: Set_Grid(LOCATION MIN, LOCATION MAX)
     {
         if (MIN.xpos < 0 || MIN.xpos > MAX.xpos || MIN.ypos < 0 ||
             MIN.ypos > MAX.ypos || MAX.ypos < 0 || MIN.xpos < 0) return;
         gridLO.ypos = MIN.ypos;
         gridLO.xpos = MIN.xpos;
         gridHI.xpos = MAX.xpos;
         gridHI.ypos = MAX.ypos;
         
         Establish_Grid(gridLO.xpos, gridLO.ypos, gridHI.xpos, gridHI.ypos);
       
         
     }
     // Set Robot ID.
     void ROBOT201 :: Set_RobotID(string ID)
     {
         RobotID = ID;
     }
     // Set Robot Power.
     void ROBOT201 :: Set_Power(float power )
     {
         Power = power;
     }
     // Get current power level.
     float ROBOT201 :: Get_Power()
     {
         return Power;
     }
     // Get distance moved while in service.
     float ROBOT201 :: Get_Distance()
     {
         return totDist;
     }
     // Return whether robot is in service.
     bool ROBOT201 :: InService()
     {
        return inService;
     }
     // Place make robot in-service.
     void ROBOT201 :: Place_InService()
     {
         if (! IsActive()) StartUp(0, 0);
         
         Current.xpos=Get_Xcoord();
         Current.ypos=Get_Ycoord();
         inService = true;
     }
    
     // Return current location. 
     LOCATION ROBOT201 :: Get_CurLocation()
     {
         Current.xpos = Get_Xcoord();
         Current.ypos = Get_Ycoord();
         return Current;
     }
     // Move from current location to destination if robot .
     bool ROBOT201 :: MoveTo(LOCATION dest)
     {
         if (! inService) return false;
         if (dest.xpos < gridLO.xpos || dest.xpos > gridHI.xpos || dest.ypos < gridLO.ypos || dest.ypos > gridHI.ypos)
             return false;
         else
         {
             if (dest.xpos > Current.xpos)
             {
                 for (int i = 0; i < (dest.xpos - Current.xpos); i++)
                 {
                      Move ('R'); totDist++; Power--;
                 }
             }
             else
                 for (int j = 0; j < (Current.xpos - dest.xpos); j++)
                 {
                        Move('L'); totDist++; Power--;
                 }
             if (dest.ypos > Current.ypos)
             {
                 for (int i = 0; i < (dest.ypos - Current.ypos); i++)
                 {
                      Move ('U'); totDist++; Power--;
                 }   
             }
             else
                 for (int j = 0; j < (Current.ypos - dest.ypos); j++)
                 {
                      Move('D'); totDist++; Power--;
                 }
                    
             Current.xpos = dest.xpos;
             Current.ypos = dest.ypos;
         }
         return true;
      }

     // Take robot out of service.
     void ROBOT201 :: Take_OutOfService()
     {
         inService = false;
     }