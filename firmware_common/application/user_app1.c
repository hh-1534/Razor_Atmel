/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"



/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
  
  
  LCDCommand(LCD_CLEAR_CMD);
  LCDMessage(LINE1_START_ADDR, "    THREE BUZZER");
  
  //PWMAudioSetFrequency(BUZZER1, 100);
 PWMAudioSetFrequency(BUZZER2, 500);
 
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{  
  
   static u8  au8Message[] = "GROUP 1!";
   static u32 timer=300;
   static u32 u8Counter=0;
   static u8 au8Message1[] = "GROUP 2!";
   static u8 au8Message2[] = "GROUP 3!";
   static u8 u8GameState=0;
   static u8 u8Gameok=0;
    //PWMAudioSetFrequency(BUZZER1, 600);
    
    

    /* if(IsButtonPressed(BUTTON3))
  {
    PWMAudioOn(BUZZER1);
   }
  else
  {
    PWMAudioOff(BUZZER1);
     } **/
     
     
     
 //PWMAudioSetFrequency(BUZZER2, 100);
    
 
    
    if(WasButtonPressed(BUTTON3)){
      
      ButtonAcknowledge(BUTTON3);
      if(u8GameState==0){
        
         
        
         u8GameState=1; 
         LCDCommand(LCD_CLEAR_CMD);
         LCDMessage(LINE1_START_ADDR, "GAME BEGINNING");
        
      }
      if(u8GameState==3){
        
        ButtonAcknowledge(BUTTON0);
        ButtonAcknowledge(BUTTON1);
        ButtonAcknowledge(BUTTON2);
        u8GameState=1;
      
        LedOff(WHITE);
        LedOff(PURPLE);
        LedOff(BLUE);
        LedOff(CYAN);
        LedOff(GREEN);
        LedOff(YELLOW);
        LedOff(ORANGE);
        LedOff(RED);
        PWMAudioOff(BUZZER2);
        timer=300;
        u8Counter=0;
        LCDCommand(LCD_CLEAR_CMD);
        LCDMessage(LINE1_START_ADDR, "GAME BEGINNING");
       
      
      }
      
    }
 
  
 if(u8GameState==1)
 {   
     LedOn(LCD_RED);
     LedOff(LCD_GREEN);
     
     if(WasButtonPressed(BUTTON0))
     {      
       ButtonAcknowledge(BUTTON0);
       LedOff(LCD_RED);
       LedOff(LCD_GREEN);
       LedOn(LCD_BLUE);
        LCDCommand(LCD_CLEAR_CMD);
       LCDMessage(LINE1_START_ADDR, au8Message);
       //LCDClearChars(LINE1_START_ADDR + 9, 18);
    //PWMAudioOn(BUZZER2);
    
      u8Gameok=1;
      u8GameState=2;
     }

  
      
     
    if(WasButtonPressed(BUTTON1))
    { 
        ButtonAcknowledge(BUTTON1);
        LedOff(LCD_RED);
        LedOn(LCD_GREEN);
        LedOn(LCD_BLUE);
         LCDCommand(LCD_CLEAR_CMD);
        LCDMessage(LINE1_START_ADDR, au8Message1);
       // LCDClearChars(LINE1_START_ADDR + 9, 18);
        u8Gameok=1;
        u8GameState=2;
         
    }
          
  
     
    
    if(WasButtonPressed(BUTTON2))
    { 
        ButtonAcknowledge(BUTTON2);
        LedOn(LCD_RED);
        LedOn(LCD_GREEN);
        LedOff(LCD_BLUE);
         LCDCommand(LCD_CLEAR_CMD);
        LCDMessage(LINE1_START_ADDR, au8Message2);
        //LCDClearChars(LINE1_START_ADDR + 9, 18);
        u8Gameok=1; 
        u8GameState=2;
    }
  
  
 }
  if(u8Gameok==1){  
 
  timer--;
  if(timer==0)
  {timer=300; u8Counter++;
  if(u8Counter>=2505)u8Counter=0;}
  
  
  if(u8Counter==0) 
  {LedOn(WHITE);PWMAudioOn(BUZZER2);}
  if(u8Counter==1) 
  {LedOn(PURPLE);PWMAudioOn(BUZZER2); }
  if(u8Counter==2) 
  {LedOn(BLUE);PWMAudioOn(BUZZER2);}
  if(u8Counter==3) 
   {LedOn(CYAN);PWMAudioOn(BUZZER2);}
   if(u8Counter==4) 
   {LedOn(GREEN);PWMAudioOn(BUZZER2);}
  if(u8Counter==5) 
   {LedOn(YELLOW);PWMAudioOn(BUZZER2);}
   if(u8Counter==6) 
   {LedOn(ORANGE);PWMAudioOn(BUZZER2);}
  if(u8Counter==7) 
   {LedOn(RED);PWMAudioOn(BUZZER2); }
  if(u8Counter==8) 
   {LedOff(WHITE);
  LedOff(PURPLE);
  LedOff(BLUE);
  LedOff(CYAN);
  LedOff(GREEN);
  LedOff(YELLOW);
  LedOff(ORANGE);
  LedOff(RED);
  PWMAudioOff(BUZZER2);
  u8Gameok=0;
  u8GameState=3;
   }
  }  
    
  
 }
 /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
  } /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/

