/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #3: Queue/Dequeue
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#ifndef LINKEDDDEQUEUE_H_
#define LINKEDDDEQUEUE_H_

#include "DLinkedList.h"

using namespace std;

class LinkedDeque
{
public:
	LinkedDeque();

	~LinkedDeque();

	void InsertBack(string newElem);

	void InitializeDeque();

	void EraseFront();

	int Size() const;

	string Print() const;

	bool IsEmpty() const;

	string Front() const;

private:
	DLinkedList deque;
	int			size;
};



#endif /* LinkedDeque_H_ */
