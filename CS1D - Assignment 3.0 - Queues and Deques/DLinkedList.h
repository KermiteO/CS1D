/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #3: Queue/Dequeue
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct DNode
{
	DNode *next;
	string data;
	DNode *prev;
};

class DLinkedList
{
public:
	DLinkedList();

	~DLinkedList();

	void InitializeList();

	void InsertBack(string newElem);

	void EraseFront();

	bool IsEmpty() const;

	string Print() const;

	string Front() const;

private:
	DNode *head;
	DNode *tail;
	int   size;
};


#endif /* DLINKEDLIST_H_ */
