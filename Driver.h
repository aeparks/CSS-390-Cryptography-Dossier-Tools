
//Created 30 November 2009

#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <fstream>

using namespace std;

class Driver
{
public:
   //constructor
   Driver() {}
   //destructor
   ~Driver() {}
   void programMenu(const int[], const int);
   
private:
   //displays current ciphertext block
   void displayBlock(const int[], const int) const;
   //displays character and its frequency by "character order"
   void displayByOrder(const int[], const int) const;
   //displays character and its frequency by "frequency order"
   void displayByFreq(const int[], const int);
   //displays digraphs associated with given parameter
   void displayDigraphs(const int[], const int);
   //displays trigrpahs associated with given paramter
   void displayTrigraphs(const int[], const int);

   //sets elements in parameter bool array to 'false'
   void setToFalse(bool[]);

   //for debugging
   void displayFreqArray(const int[]);
};
#endif