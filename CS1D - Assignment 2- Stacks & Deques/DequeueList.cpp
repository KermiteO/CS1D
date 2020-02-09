#include "DequeueList.h"

template<class Type>
DequeueList<Type>::DequeueList()
{
	head = NULL;
	tail = head;

	dataCount = 0;
}

template<class Type>
DequeueList<Type>::~DequeueList()
{
	delete head;
	delete tail;
}

template<class Type>
void DequeueList<Type>::InitializeList(const Type DATA[],
	 	  	  	  	  	  	  	  	   const int  AR_SIZE)
{
	DequeueNode *newData;
	DequeueNode *oddData;
	DequeueNode *evenData;

	newData = new DequeueNode;
	oddData = new DequeueNode;
	evenData= new DequeueNode;

	for(int i = 1; i <= AR_SIZE/2; i++)
	{
		newData->next = NULL;
		oddData->next = NULL;
		evenData->next = NULL;

		//PROC - every even number index and every odd numbered indesx gets
		//		 stored in respective nodes. Then call the PushBack and
		//		 PushFront methods to add even and odd nodes to front and
		//		 back of list
		evenData->dataValue = DATA[(2*i) - 2];

		oddData->dataValue = DATA[(2*i) - 1];

		PushBack(oddData);

		PushFront(evenData);

		newData = new DequeueNode;
		oddData = new DequeueNode;
		evenData= new DequeueNode;

		dataCount++;
	}
}

template<class Type>
void DequeueList<Type>::PushFront(DequeueNode *newNode)
{
	if(head != NULL && tail != NULL)
	{
		newNode->next = head;
	}
	else
	{
		tail = newNode;
	}

	head = newNode;

	dataCount++;
}

template<class Type>
void DequeueList<Type>::PushBack(DequeueNode *newNode)
{
	if(head != NULL && tail != NULL)
	{
		tail->next = newNode;
	}
	else
	{
		head = newNode;
	}

	tail = newNode;

	dataCount++;
}

template<class Type>
void DequeueList<Type>::PopBack()
{
	DequeueNode *srchPtr;
	DequeueNode *delPtr;
	bool		found = false;

	srchPtr = head;

	while(!found && srchPtr->next != NULL)
	{
		if(srchPtr->next->dataValue == tail->dataValue)
		{
			found = true;
		}
		else
		{
			srchPtr = srchPtr->next;
		}
	}

	srchPtr->next = NULL;

	delPtr = tail;

	tail = srchPtr;

	delete delPtr;

	dataCount--;
}

template<class Type>
void DequeueList<Type>::PopFront()
{
	DequeueNode *perPtr;

	perPtr = head;

	head = perPtr->next;

	delete perPtr;

	dataCount--;
}

template<class Type>
void DequeueList<Type>::Print()
{
	DequeueNode *srchPtr;

	srchPtr = head;

	while(srchPtr != NULL)
	{
		cout << srchPtr->dataValue << ' ';

		srchPtr = srchPtr->next;
	}

	cout << endl;
}

template<class Type>
void DequeueList<Type>::SearchDestroy(Type delVal)
{
	DequeueNode *headPtr;
	DequeueNode *tailPtr;

	bool found = false;

	headPtr = head;
	tailPtr = tail;

	while(!found && (headPtr->next != tailPtr))
	{
		if(tailPtr->dataValue == delVal || headPtr->dataValue == delVal)
		{
			found = true;

			if(tailPtr->dataValue == delVal)
			{
				PopBack();
			}
			else if(headPtr->dataValue == delVal)
			{
				PopFront();
			}
		}
		else
		{
			PopBack();

			PopFront();

			headPtr = head;
			tailPtr = tail;
		}
	}
}

template class DequeueList<string>;
template class DequeueList<double>;

