/****************************************************************************
* Project 4: pgm4.c - Averages
*
* Programmer:Ali S Ahmad
*
* Due Date:10/20/2016
*
* EGRE 245 Fall 2016
*
* Pledge: I have neither given nor received unauthorized aid on the program.
*
* Description: prints out average temp. in a month from given temps in a dat file also puts + sign next to squence of *			temps > mean temperture 
*
* Inputs: temp.dat, sum, 
*
* Output: mean, tempertures, squences with '+' 
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){

        FILE *fp;
        char string[256];      // for transport / translation of string variables to numbers
        int  temp[31];        // declares int array with the max number of days in month 
	unsigned int line;   // line numbers (used in for loop) 
        unsigned int ndays; // the number of days in a month 
        int sum=0;	   // addition of all the values 
        float mean;       // for later mean calc 

/* * * * * * * * Variables Declared * * * * * * * */ 

        
        if(fgets(string,256,stdin)==NULL) 
        {
        return 0;                               // if file is empty it returns 0 
        }
        
        ndays = atoi(string);     //sets the first line to the number of days    
        
        for ( line = 0; line < ndays; line++ ) { // asssigns all the values of the file to the content of the temperture array
          fgets(string,256,stdin);
          temp[line] = atoi(string);
          sum += temp[line];
        }
        
          
       mean = (float)sum/(float)ndays;  // determines the mean of all the values 
       printf(" Average Temperture %0.2f\n", mean);
       
       
        //for loop plus rules for '+' sign
       
       
       for (int i = 0; i < ndays; i++){ // loops through array 
         
          
          if ( (i < ndays-2) && (temp[i] > mean) && (temp[i+1] > mean) && (temp[i+2] > mean ) ) {
           printf("%2d %2d+\n", i+1, temp[i]);  // checks the current block and next 2 to see if greater than mean and if so 
                                               // places a + sign  (for first few blocks)
           } 
           
           else if ( (i > 2) && (temp[i-2]>mean) && (temp[i-1] > mean) && (temp[i] > mean ) ){
                printf("%2d %2d+\n", i+1, temp[i]); //checks current block and past 2 to see if greater than mean 
                }                                  // to place a + sign (for last few blocks) 
           
           else { 
           printf("%2d %2d\n",i+1, temp[i]); // if wasnt greater than mean then print out the value. 
           }
           
       }
}
