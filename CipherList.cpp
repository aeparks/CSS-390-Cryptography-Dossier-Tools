
// Created 30 November 2009

#include <iostream>
#include "CipherList.h"

//"constructor" defined in header
//CipherList::CipherList() { head = NULL; }

//"destructor" defined in header
//CipherList::~CipherList() { this->makeEmpty(); }

//copy constructor not needed
//CipherList::CipherList(const CipherList& param) {}

//"isEmpty" defined in header
//bool CipherList::isEmpty() { return head == NULL; }

//"addNode": will add a new node to linked list
//  New node may point to two or three integers as well as other nodes in list
bool CipherList::addNode(int left, int right, int middle)
{
   return true;
}

//"deleteNode": will remove a node from linked list
//   Will hand back references to int values being pointed to by removed node
bool CipherList::deleteNode(int& refLeft, int& refRight, int& refMiddle)
{
   return true;
}

//"makeEmpty": will delete entire linked list
void CipherList::makeEmpty()
{
   //delete everything
}