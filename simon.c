
/**************************************************************************
                          SIMON SAYS 3.0

      File Description :
         simon.c file contains C code which controls the overall program.
         this file contains the main function and the functions for 
         mode 1, mode 2 and mode 3.

***************************************************************************/
//************** Header Files ***********************//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
//***************************************************//

//************* Function Declarations **************//

void button_led(int x);
void lightup(int x);
void lightup2(int x);
void mode1();
void mode2();
void mode3();
int read_button();
void count_score(int x);
void high_score(int score, int mode);

//*************************************************//

//********** Declaring Constants ******************//

char start[] = "aplay hello.wav";
char wrong[] = "aplay wrong.wav";
char end[] = "aplay goodbye.wav";
char corrects[] = "aplay correct.wav";
char m1[] = "aplay mode1.wav";
char m2[] = "aplay mode2.wav";
char m3[] = "aplay mode3.wav";
char m[] = "aplay choosemode.wav";
char hscore[] = "aplay highscore.wav";

//*************************************************//

/*******************************************************************************
 *				   Main
 * 										
 * Controls the maim do-while loop which allows the user to switch between the 
 * game modes, the user can choose between 4 choices:
 *        1. Beginner Mode
 *        2. Advanced Mode (a bit faster)
 *        3. Pro Mode 
 *        4. Exit Program
 *
*******************************************************************************/
int main ()
{
  //Temporary variable
  int  temp;

  while(read_button()!=4);
    
  //blink the led's
  system(start);
  button_led(5);
 

  //Play tunes with corresponding led's

  //Menu control
  do
    {
      system(m);
      
      //Read button press
      temp=read_button();
      switch(temp)
	{
	//If temp=1 call mode 1
	case 1 : mode1();
	         break;

	//if temp=2 call mode 2
	case 2 : mode2();
	  break;

	//If temp=3 call mode 3
	case 3 : mode3();
	  break;
	}
    }while(temp!=4); //Exit loop if temp=4

  //blink all the led's before exiting
  button_led(5);
  system(end);

  //exit program
  return 0;
}



/*******************************************************************************
 *				   mode1
 * 										
 * This mode runs the basic Simon Says game with the lights lighting up
 * for one second each.
 *
*******************************************************************************/
void mode1()
{
  //Variables required for the function
  int seq[30]={0};  //Array to hold the sequence 
  int correct = 1;
  int cnt=0, temp, i=0;

  system(m1);
  usleep(100000);
  
  //Lightup the lights with tune
  lightup(1);
  usleep(100000);
  lightup(2);
  usleep(100000);
  lightup(3);
  usleep(100000);
  lightup(4);

  sleep(1);
  //Making sure random numbers are generated
  srand(time(NULL));

  //While loop goes till user makes mistake
  while ( correct == 1 && cnt<30 )
    {
      //Generate a random number and add it to the sequence 
      temp= (rand() % 4 )+1;
      seq[cnt++]=temp;

      //light up each led in the sequence
      //also play the tune
      for(i=0;i<cnt;i++)
	{
	  lightup(seq[i]);
	  usleep(100000);
	}

      //Short pause before the input
      usleep(500000);

      //Read in the input from the buttons
      for(i=0;i<cnt;i++)
	{
	  //read button press
	  
	  temp=read_button();
	  lightup(temp);
	  
	  //check for correct input
	  if ( temp != seq[i] )
	    {
	      //If not set correct=0 and break the loop
	      correct = 0;
	      break;
	    }
	}
      if(i==cnt)
	system(corrects);
    }
  if (correct == 0)
    system(wrong);
  usleep(500000);
  count_score(cnt-1);
  high_score(cnt-1, 1);
  button_led(2);
  //pause before returning to main
  sleep(1);
}


/*******************************************************************************
 *				   mode2
 * 										
 * Mode 1 but faster and without sounds!!
 *
*******************************************************************************/
void mode2()
{
  //Variables required for the function
  int seq[30];
  int correct = 1;
  int cnt=0, temp, i;

  system(m2);
  usleep(100000);
  
  //Lightup the lights with tune
  lightup2(1);
  usleep(100000);
  lightup2(2);
  usleep(100000);
  lightup2(3);
  usleep(100000);
  lightup2(4);

  sleep(1);

  //Making sure random numbers are generated
  srand(time(NULL));

  //While loop goes till user makes mistake
  while ( correct == 1 && cnt<30)
    {
      //Generate a random number and add it to the sequence 
      temp= (rand() % 4 )+1;
      seq[cnt++]=temp;
   
      //light up each led in the sequence
      //also play the tune
      for(i=0;i<cnt;i++)
	{
	  lightup2(seq[i]);
	  usleep(100000);
	}

      //Short pause before the input
      usleep(500000);

      //Read in the input from the buttons
      for(i=0;i<cnt;i++)
	{
	  //read button press
	  temp=read_button();
	  lightup2(temp);
	  //printf("\n%d\n", temp);

	  //check for correct input
	  if ( temp != seq[i] )
	    {
	      //If not set correct=0 and break the loop
	      correct = 0;
	      break;
	    }
	}
      if(i==cnt)
	system(corrects);
    }

  if (correct == 0)
    system(wrong);
  usleep(500000);
  count_score(cnt-1);
  high_score(cnt-1, 2);
  button_led(2);
  //pause before returning to main
  sleep(1);
}



/*******************************************************************************
 *				   mode3
 * 										
 * This is our take on the Simon Says game. In this mode, insted of 
 * adding one tune to the sequence every time, it increases the 
 * number of tunes added as the game progresses.   
 *
*******************************************************************************/
void mode3()
{
  //Variables required for the function
  int seq[30];
  int correct = 1;
  int cnt=0, temp, i,inc=1 ;

  system(m3);
  usleep(100000);
  
  //Light up the lights with tune
  lightup(1);
  usleep(100000);
  lightup(2);
  usleep(100000);
  lightup(3);
  usleep(100000);
  lightup(4);

  sleep(1);
  
  //Making sure random numbers are generated
  srand(time(NULL));

  //While loop goes till user makes mistake
  while ( correct == 1 && (cnt+inc)<30)
    {
      //Generate some random numbers and add to the sequence
      for( i=0;i<inc;i++)
	{
	  temp= (rand() % 4 )+1;
	  seq[cnt++]=temp;
	}
      
      //light up each led in the sequence
      //also play the tune
      for(i=0;i<cnt;i++)
	{
	  lightup(seq[i]);
	  usleep(100000);
	}

      //Pause before taking input
      usleep(500000);

      //Read in the input from the buttons 
      for(i=0;i<cnt;i++)
	{
	  //read button press
	  temp=read_button();
	  lightup(temp);
	  //printf("\n%d\n", temp);

	  //check for correct input
	  if ( temp != seq[i] )
	    {
	      //If not set correct=0 and break the loop
	      correct = 0;
	      break;
	    }
	}
      //output sound if correct
      if(i==cnt)
	system(corrects);
      //increment number of random numbers to be generated
      inc++;
    }

  if (correct == 0)
    system(wrong);
  usleep(500000);
  count_score(inc-2);
  high_score(inc-2, 3);
  button_led(2);
  //Pause before exit
  sleep(1);
}


/*******************************************************************************
 *				   high_score
 * 										
 * The function checks the previous highest score and the
 * current score and changes the high score if necessary.
 * Note : all high scores are assigned to 0
 *
*******************************************************************************/
void high_score(int score, int mode)
{
  char temp[15];
  FILE* file;
  int highscore;

  //Open the appropriate file
  if (mode == 1)
    strcpy(temp, "highscore1.txt");
  else if (mode == 2)
    strcpy(temp, "highscore2.txt");
  else
    strcpy(temp, "highscore3.txt");

  //read from the file
  file = fopen(temp, "r");
  fscanf(file, "%d", &highscore);

  //change the highest score if necesary
  if (score > highscore)
    {
      system(hscore);
      fclose(file);
      file = fopen(temp, "w");
      fprintf(file, "%d", score);
    }

  //close the file
  if (file != NULL)
    fclose(file);
}
