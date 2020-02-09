/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #3: Queue/Dequeue
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_

#include "LinkedDeque.h"

class LinkedQueue
{
public:
	LinkedQueue();

	~LinkedQueue();

	void Enqueue(string newStr);

	void Dequeue();

	int Size() const;

	string Front() const;

	string Print() const;

	bool Empty() const;

private:
	LinkedDeque qList;
};



#endif /* LINKEDQUEUE_H_ */
