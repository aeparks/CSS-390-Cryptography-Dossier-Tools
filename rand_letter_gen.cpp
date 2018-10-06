
#include <iostream>
#include <math.h>

using namespace std;

int const ALPHA = 27;
int const LENGTH = 26;
int const SPACING = 5;

//* simple program to generate 10 random lower case letters *//

int main()
{
   int numLetters = 0;
   int index;
   char alphabet[ALPHA] = "abcdefghijklmnopqrstuvwxyz";
   bool selected[LENGTH];

   for (int z = 1; z <= 10; z++)
   {
	   //set to false
      for (int i = 0; i < LENGTH; i++)
	      selected[i] = false;

	   index = 0;
	   numLetters = 0;
      cout << " Permutation " << z << endl;
	   cout << " ============ " << endl;
	   for (;;)
	   {
         index = rand() % LENGTH;
		   if (selected[index] == false)
		   {
		      if (numLetters % SPACING == 0) //space
			      cout << " ";
		      cout << alphabet[index];
		      selected[index] = true;
		      numLetters++;
		   }
		   if (numLetters >= 26)
		      break;
      }
	   cout << "\n" << endl;
   }//end outside for loop
   cout << "\n" << endl;

   return 0;
}