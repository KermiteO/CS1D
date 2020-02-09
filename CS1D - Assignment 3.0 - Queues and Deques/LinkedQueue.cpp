#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
	qList.InitializeDeque();
}

LinkedQueue::~LinkedQueue() {}

void LinkedQueue::Enqueue(string newStr)
{
	qList.InsertBack(newStr);
}

void LinkedQueue::Dequeue()
{
	if(!qList.IsEmpty())
	{
		qList.EraseFront();
	}
}

int LinkedQueue::Size() const
{
	return qList.Size();
}

string LinkedQueue::Front() const
{
	return qList.Front();
}

string LinkedQueue::Print() const
{
	return qList.Print();
}

bool LinkedQueue::Empty() const
{
	return qList.IsEmpty();
}
