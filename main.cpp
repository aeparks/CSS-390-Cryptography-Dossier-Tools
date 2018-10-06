
//----- Program History -----//
// Version 1.0 created 30 October 2009
// Originally created for CSS390 in an attempt to derive patterns from
// from homophonic ciphertext provided by "I.M. Voynich"

/* 08 Nov 2009: Changed code to be more generalized for files.
 *              Now using dymanic arrays versus mutliple static arrays */
/* 08 Nov 2009: Parsed work into new .h and new .cpp file named "Driver" */
/* 09 Nov 2009: Added more code for newest ciphertext block */
/* 20 Nov 2009: Separated char and int functionality into different drivers */

// Version 2.0 created 25 November 2009
// Created to streamline processes in ver1.0

// Version 3.0 created 30 November 2009
/* 30 Nov 2009: Splits functionality into two programs: one for char ciphertext
 *              and one for int ciphertext */
/* 30 Nov 2009: Added new "CipherList" class to handle linked list of nodes
 *              with pointers to integers for digraphs and trigraphs appearing
 *              in the ciphertext block */

#include <iostream>
#include <fstream>
#include "Driver.h"

//ciphertext block sizes
int const SIZE_1 = 160;              //voynich01_int.txt
int const SIZE_2 = 100;              //voynich02_int.txt

int const NUM = 100;

int main()
{
   cout << "\n CSS 390 Dossier Project (Fall 2009) " << endl;
   cout << " Analysis for Integer-based Ciphertexts " << endl;
   cout << " ======================================= " << endl;
   
   Driver newDriver;
   int* ciphertext = NULL;        //pointer to integer array
   int userInput = -1;                
   int arrayPtr = 0;
   
   //read in external files
   ifstream text_01("voynich01_int.txt");
   ifstream text_02("voynich02_int.txt");
   //more added as necessary
   
   //file choice menu
   while (userInput != 0)
   {
		cout << " Select ciphertext: \n" << endl;
		cout << " (1) URGENT 28-10 " << endl;
		cout << " (2) URGENT 08-11 " << endl;
		//more added as necessary
		cout << " (0) Quit " << endl;
		cout << " Enter choice: ";
		cin >> userInput;
      
		switch (userInput)
		{
        case 0: //exit program
            break;
        case 1: //using URGENT 28-10
            ciphertext = new int[SIZE_1];
            if (!text_01)
               cerr << " File could not be opened! " << endl;
            else
            {
				while(text_01 >> ciphertext[arrayPtr])
                  arrayPtr++;
            }
				cout << "\n Known information:" << endl;
				cout << " >> Enciphered using homophonic substitution cipher\n\n";
				//pass to driver
				newDriver.programMenu(ciphertext,SIZE_1);
				userInput = 0;
            break;
        case 2: //using URGENT 08-11
            ciphertext = new int[SIZE_2];
            if (!text_02)
               cerr << " File could not be opened! " << endl;
            else
            {
				while(text_02 >> ciphertext[arrayPtr])
					arrayPtr++;
            }
				cout << "\n Known information: " << endl;;
				cout << " >> \"The key is seven(7)\"\n\n";
				cout << " >> Uses digits 00 through 99 with no repeats\n\n";
				//pass to driver
				newDriver.programMenu(ciphertext,SIZE_2);
				userInput = 0;
            break; 
        default:
            cout << " invalid input " << endl;
            break;
		}
   }
   delete [] ciphertext; 
   return 0;
};