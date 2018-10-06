
// Created 30 November 2009

#include "Driver.h"
#include "CipherList.h"
#include <iostream>
#include <iomanip>

int const NUM = 100;
int const TOP = 5;

//constructor and destructor defined in header

/* "programMenu":
 * center of activity for int-based ciphertext */
void Driver::programMenu(const int param[], const int SIZE)
{
   int userInput = -1;          //user input for switch
   int textNumbers[NUM];        //00 through 99 //user for frequency analysis
   
   //set array to zeros by default
   for (int i = 0; i < NUM; i++)
      textNumbers[i] = 0;
   
   //set number frequency
   for (int i = 0; i < SIZE; i++)
      textNumbers[param[i]] += 1;
   
   //switch menu
   while (userInput != 0)
   {
      cout << " Select action for list\n" << endl;
      cout << " (1) Display text block " << endl;
      cout << " (2) Display list (list order) " << endl;
      cout << " (3) Display list (freq order) " << endl;
      cout << " (4) Display digraphs " << endl;
      cout << " (5) Display trigraphs " << endl;
      cout << " (0) Quit\n" << endl;
      cout << " Enter choice: ";
      cin >> userInput;
      
      switch (userInput)
      {
         case 0: //exit driver
            break;
         case 1:
            displayBlock(param, SIZE);
            break;
         case 2:
            displayByOrder(textNumbers, SIZE);
            break;
         case 3:
            displayByFreq(textNumbers, SIZE);
            break;
         case 4:
            //displayDigraphs(param, SIZE);
            break;
         case 5:
            //displayTrigraphs(param, SIZE);
            break;
		 case 88:
			 //debugging
			 displayFreqArray(textNumbers);
			 break;
         default:
            cout << " invalid input " << endl;
            break;    
      }
   }
}

/* "displayBlock":
 * will display ciphertext block 25 integers per line */
void Driver::displayBlock(const int param[], const int SIZE) const
{
   for (int i = 0; i < SIZE; i++)
   {
      if (i == 0) //adds space at beginning of block (for formatting)
		  cout << " ";
      if (i != 0 && i % 5 == 0) //adds tab between sets of five (for formatting)
         cout << "   ";
      if (i != 0 && i % 20 == 0) //skip to next line (for formatting)
         cout << "\n" << " ";
      
      if (param[i] < 10) //puts leading zero on single digits (for formatting)
         cout << "0" << param[i] << " ";
      else
         cout << param[i] << " ";
   }
   cout << "\n";
}

/* "displayByOrder": 
 * will display two columns of integers and one column with doubles. The first
 * column represents the ciphertext digits, the second column represents the
 * number of times the ciphertext digit appears in the block, and the third
 * column is the ciphertext digit's percentile frequency. */
void Driver::displayByOrder(const int param[], const int SIZE) const
{
   float freq;

   cout << "\n Ciphertext | Number | Frequency " << endl;
   for (int i = 0; i < NUM; i++)
   {
      freq = 0.0;
      if (param[i] != 0)
      {
	     freq = ((float)param[i] / (float)SIZE) * 100;
         if(i < 10)
         {
            cout << setw(6) << "0" << i << setw(10) << param[i] << setw(14)
				 << setprecision(3) << freq << "%" << endl;
         }
         else
         {
            cout << setw(7) << i << setw(10) << param[i] << setw(14)
				 << setprecision(3) << freq << "%" << endl;
         }
      }
   }//end 'for' loop
}

/* "displayByFreq":
 * will display two columns of integers and one column with doubles. The first
 * column represents the ciphertext digits, the second column represents the
 * number of times the ciphertext digit appears in the block, and the third
 * column is the ciphertext digit's percentile frequency. */
void Driver::displayByFreq(const int param[], const int SIZE)
{
   /* 1) Search through "frequency" to find highest frequency integer
    * 2) set matching index of "selected" to false
    * 3) Display ciphertext number, frequency, and result of:
         cout << setprecision(4) << (frequency/SIZE) */

   float freq;
   int indexHolder = 0;  //holds index that currently contains highest frequency
   bool selected[NUM];   //index values align with param index values
   
   setToFalse(selected);
   
   cout << "\n Ciphertext | Number | Frequency " << endl;
   for (int j = 0; j < NUM; j++)
   {
	  //reset indexHolder and freq
      indexHolder = 0;
	  freq = 0.0;
      //Part 1: find highest frequency among remaining frequencies
      for (int k = 1; k < NUM; k++)
      {
         if (param[k] > param[indexHolder] && selected[k] == false)
            indexHolder = k;
      }
	  if (param[indexHolder] > 0)
	  {
         //highest frequency found
         selected[indexHolder] = true;
	     freq = ((float)param[indexHolder] / (float)SIZE) * 100;
      
         //Part 2: display ciphertext number, frequency, & frequency percentage
         if (indexHolder < 10) //adds leading zero (for formatting)
         {
            cout << setw(6) << "0" << indexHolder << setw(10) << param[indexHolder]
			     << setw(14) << setprecision(3) << freq << "%" << endl;
         }
         else
         {
            cout << setw(7) << indexHolder << setw(10) << param[indexHolder]
			     << setw(14) << setprecision(3) << freq << "%" << endl;
         }
	  }
   }//end 'for' loop
}

void Driver::displayDigraphs(const int param[], const int SIZE)
{
   /* 1) Display top 5 most frequent numbers
    * 2) Prompt user for number to associate with digraphs
	 * 2.5) Check if valid
	 * 3) Walk through 'param' array searching for user number
	 * 4) When found, make two nodes one for left, one for right
	 * 5) Search list for similiar nodes
	 * 5.5) If similar node found, link to it's "down" pointer
	 * 5.5.5) This will be used with a counter while printing
	 * 6) When finished, hand execution to private printer
	 * 7) Delete linked list */
   bool selected[NUM];

   setToFalse(selected);

   int topFive[TOP];
   int indexHolder = 0;

   for (int i = 0; i < TOP; i++)
   {
      indexHolder = 0;
      for (int k = 1; k < NUM; k++)
      {
         if (param[k] > param[indexHolder] && selected[k] == false)
            indexHolder = k;
      }
   }

}

void Driver::displayTrigraphs(const int param[], const int SIZE)
{
}

void Driver::setToFalse(bool param[])
{
	for (int i = 0; i < NUM; i++)
		param[i] = false;
}

/*** for debugging //remove when complete ***/
void Driver::displayFreqArray(const int param[])
{
   cout << " Index | Frequency " << endl;
   for (int i = 0; i < NUM; i++)
   {
      if (param[i] != 0)
      {
         if (param[i] < 10) //add space for formatting
            cout << "   " << i << "         " << param[i] << endl;
         else
            cout << "  " << i << "       " << param[i] << endl;
      }
   }
}