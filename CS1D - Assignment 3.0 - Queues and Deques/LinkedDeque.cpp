#include "LinkedDeque.h"

LinkedDeque::LinkedDeque()
{
	deque.InitializeList();

	size = 0;
}

LinkedDeque::~LinkedDeque() {}

void LinkedDeque::InitializeDeque()
{
	deque.InitializeList();
}

void LinkedDeque::InsertBack(string newElem)
{
	deque.InsertBack(newElem);

	size++;
}

void LinkedDeque::EraseFront()
{
	deque.EraseFront();

	size--;
}

string LinkedDeque::Front() const
{
	return deque.Front();
}

bool LinkedDeque::IsEmpty() const
{
	return deque.IsEmpty();
}

string LinkedDeque::Print() const
{
	return deque.Print();
}

int LinkedDeque::Size() const
{
	return size;
}
