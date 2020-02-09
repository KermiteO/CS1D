#include "QueueList.h"

template<class Type>
QueueList<Type>::QueueList()
{
	head = NULL;
	tail = head;
}

template<class Type>
QueueList<Type>::~QueueList()
{
	delete head;
	delete tail;
}

template<class Type>
void QueueList<Type>::InitializeQueueList(const Type ARRAYDATA[],
									 	  const int  AR_SIZE)
{
	QueueNode *newData;

	newData = new QueueNode;

	for(int i = 0; i < AR_SIZE; i++)
	{
		newData->dataValue = ARRAYDATA[i];

		newData->next = NULL;

		if(head == NULL)
		{
			tail = newData;

			head = tail;
		}
		else
		{
			tail->next = newData;

			tail = newData;
		}

		newData = new QueueNode;
	}
}

template<class Type>
void QueueList<Type>::DeQueueList()
{
	QueueNode *delPtr;

	delPtr = head;

	head = delPtr->next;

	delete delPtr;
}

template<class Type>
void QueueList<Type>::FindAndDelete(Type delValue)
{
	bool found = false;

	QueueNode *srchPtr;

	srchPtr = head;

	while(!found && srchPtr != NULL)
	{
		if(srchPtr->dataValue == delValue)
		{
			found = true;
		}

		DeQueueList();

		srchPtr = head;

		if(srchPtr == tail)
		{
			tail = head;
		}
	}
}

template<class Type>
void QueueList<Type>::Print()
{
	QueueNode *srchPtr;

	srchPtr = head;

	while(srchPtr != NULL)
	{
		cout << srchPtr->dataValue << ' ';

		srchPtr = srchPtr->next;
	}

	cout << endl;
}

template class QueueList<double>;
template class QueueList<string>;
