
// Created 30 November 2009

#ifndef CIPHERLIST_H
#define CIPHERLIST_H

#include <iostream>

using namespace std;

class CipherList
{
public:
	//constructor
	CipherList() { head = NULL; }
	//destructor
	~CipherList() { this->makeEmpty(); }
	//copy constructor
	//CipherList(const CipherList&);
	//checks to see if list is empty
	bool isEmpty() { return head == NULL; }
	//creates new CipherList node using parameter data
	bool addNode(int, int, int);
	//deletes CipherList node and returns refs to the values being pointed at
	bool deleteNode(int&, int&, int&);
private:
	//will clear entire list
	void makeEmpty();
   
	//the node in CipherList linked list
	struct Node
	{
		int* left;          //pointer to int left of middle
		int* right;         //pointer to int right of middle
		int* center;        //pointer to int in middle
		Node* next;         //pointer to next node in CipherList
		Node* prev;         //pointer to previous node in CipherList
		Node* down;         //pointer to a node contain exact same data items
	};

	Node* head;            //pointer to first node
};
#endif