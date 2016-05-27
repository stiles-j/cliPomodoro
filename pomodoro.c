/*
Title: pomodoro.c
Author: Justice Stiles
Date: 2016/05/26
Description:  A simple, low resource comand line interface pomodoro timer.  This program will take two integer arguments from the command line.  The first argument specifies the length of the pomodoro sprint, and the second the length of the rest period between sprints.  The program will give the user an audible one minute warning when the rest period has only one minute left.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char* argv[])
{
  /*sprintLenght is the length of time in minutes for the pomodoro sprint.  restLength is the length in minutes of the interval between sprints.  These default to standard values for a pomodoro sprint*/
  
  int sprintLength = 25, restLength = 5, remainingTime, sprintsCompleted = 0;
  
  
  /*Check if we got valid command line inputs, and if we did assign variables apropriately*/
  if (argc == 3)
  {
    
    //check if the first cla is a valid input and use if it is
    if (isdigit(argv[1][0]))
    {
      sprintLength = atoi(argv[1]);   
    }//end if argv1
    //give 'em an error message if they got it wrong and punt
    else
    {
      printf("\nInvalid sprint length argument. Usage: pomodoro [int sprint length] [int rest length]");
      exit(1);
    }//end else
    
    //check second cla and process as above
    if (isdigit(argv[2][0]))
    { 
      restLength = atoi(argv[2]);
    }//end if argv2
    else
    {
      printf("\nInvalid rest length argument. Usage: pomodoro [int sprint length] [int rest length]");
      exit(1);
    }//end else

  }//end if arc == 3

  //Run this loop infinitely until the user manually stops it
  while (1)
  {
    printf("\n***Beginning %d minute pomodoro sprint!!***\n", sprintLength);
    fflush(stdout);
  
  
    //set remainingTime to sprintLenght and count down
    for (remainingTime = sprintLength; remainingTime > 0; --remainingTime)
    {
      printf("\nMinutes Remaining in Sprint: %d", remainingTime);
      fflush(stdout);

      sleep(60);
    }//end for loop
    printf("\n***Sprint is up!  Time to take a break!***");
    printf("\n***You have completed %d sprints this run.***\n", ++sprintsCompleted);

    //Time is up, so play the first alert
    system("aplay alert3.wav");


    //start the rest period, give a warning at 1 minute
    for(remainingTime = restLength; remainingTime > 1; --remainingTime)
    {
      printf("\nTime remaining in rest period: %d", remainingTime);
      fflush(stdout);
      sleep(60);
    }//end for loop
    printf("\n***One minute left in the rest period***\n");
    //give the audible one minute warning
    system("aplay alert2.wav");


    //count down the last minute
    for (remainingTime = 1; remainingTime > 0; --remainingTime)
    {
      printf("\nTime remaining in rest period: %d", remainingTime);
      fflush(stdout);
      sleep(60);
    }//end for loop
    printf("\n***Rest period is over!  Start your next sprint!***\n");

    //sound the start sprint alert
    system("aplay alert1.wav");
    
  }//end while 1
  
}//end main




































