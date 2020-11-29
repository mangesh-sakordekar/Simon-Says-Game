#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

//Declare the necessary constants
char z0[] = "aplay 0.wav";
char z1[] = "aplay 1.wav";
char z2[] = "aplay 2.wav";
char z3[] = "aplay 3.wav";
char z4[] = "aplay 4.wav";
char z5[] = "aplay 5.wav";
char z6[] = "aplay 6.wav";
char z7[] = "aplay 7.wav";
char z8[] = "aplay 8.wav";
char z9[] = "aplay 9.wav";
char z10[] = "aplay 10.wav";

char o1[] = "aplay 11.wav";
char o2[] = "aplay 12.wav";
char o3[] = "aplay 13.wav";
char o4[] = "aplay 14.wav";
char o5[] = "aplay 15.wav";
char o6[] = "aplay 16.wav";
char o7[] = "aplay 17.wav";
char o8[] = "aplay 18.wav";
char o9[] = "aplay 19.wav";

char t0[] = "aplay 20.wav";
char th[] = "aplay 30.wav";

char say[] = "aplay score.wav";


/*******************************************************************************
 *				   count_score
 * 										
 * plays the audio file saying the score
 *
*******************************************************************************/
void count_score(int x)
{
  system(say);
  switch(x)
    {
    case 0 :system(z0);
      break;
    case 1 :system(z1);
      break;
    case 2 :system(z2);
      break;
    case 3 :system(z3);
      break;
    case 4 :system(z4);
      break;
    case 5 :system(z5);
      break;
    case 6 :system(z6);
      break;
    case 7 :system(z7);
      break;
    case 8 :system(z8);
      break;
    case 9 :system(z9);
      break;
    case 10 :system(z10);
      break;
    case 11 :system(o1);
      break;
    case 12 :system(o2);
      break;
    case 13 :system(o3);
      break;
    case 14 :system(o4);
      break;
    case 15 :system(o5);
      break;
    case 16 :system(o6);
      break;
    case 17 :system(o7);
      break;
    case 18 :system(o8);
      break;
    case 19 :system(o9);
      break;
    case 20 :system(t0);
      break;
    case 21 :system(t0);
      system(z1);
      break;
    case 22 :system(t0);
      system(z2);
      break;
    case 23 :system(t0);
      system(z3);
      break;
    case 24 :system(t0);
      system(z4);
      break;
    case 25 :system(t0);
      system(z5);
      break;
    case 26 :system(t0);
      system(z6);
      break;
    case 27 :system(t0);
      system(z7);
      break;
    case 28 :system(t0);
      system(z8);
      break;
    case 29 :system(t0);
      system(z9);
      break;
    case 30 :system(t0);
      break;
    }
}
      
