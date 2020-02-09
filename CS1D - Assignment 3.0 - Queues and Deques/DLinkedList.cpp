#include "DLinkedList.h"

DLinkedList::DLinkedList()
{
	InitializeList();
}

DLinkedList::~DLinkedList()
{
	while(!IsEmpty())
	{
		EraseFront();
	}

	delete head;
	delete tail;
}

void DLinkedList::InitializeList()
{
	head = NULL;
	tail = NULL;
}

bool DLinkedList::IsEmpty() const
{
	return(head == NULL && tail == NULL);
}

void DLinkedList::EraseFront()
{
	DNode *tempHead;

	tempHead = head;

	//Condition if there's only 1 node in the list
	if(head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else //if there are 1 or more nodes in the list
	{
		head = tempHead->next;
		tempHead->next->prev = NULL;
	}

	delete tempHead;
}

string DLinkedList::Front() const
{
	return head->data;
}

string DLinkedList::Print() const
{
	ostringstream output;
	DNode *srchPtr;

	srchPtr = head;

	while(srchPtr != NULL)
	{
		output << "(" << srchPtr->data << ") ";

		srchPtr = srchPtr->next;
	}

	return output.str();
}

void DLinkedList::InsertBack(string newElem)
{
	DNode *newNode;

	newNode = new DNode;

	newNode->data = newElem;

	newNode->next = NULL;
	newNode->prev = NULL;

	//IF THE LSIT ISN'T EMPTY
	if(!IsEmpty())
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else
	{
		head = newNode;
		tail = newNode;
	}
}
