#include "StackList.h"

template<class Type>
StackList<Type>::StackList()
{
	head = NULL;
	dataCounter = 0;
}

template<class Type>
StackList<Type>::~StackList()
{
	delete head;
}

template<class Type>
void StackList<Type>::InitializeStack(const Type ARRAYDATA[],
								 	  const int  AR_SIZE)
{
	StackNode *newData;

	newData = new StackNode;

	for(int i = 0; i < AR_SIZE; i++)
	{
		newData->dataValue = ARRAYDATA[i];

		newData->next = head;

		head = newData;

		newData = new StackNode;

		dataCounter++;
	}
}

template<class Type>
void StackList<Type>::PushData(Type newData)
{
	StackNode *newNode;

	newNode = new StackNode;

	newNode->dataValue = newData;

	if(head == NULL)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = head;
	}

	head = newNode;

	dataCounter++;
}

template<class Type>
Type StackList<Type>::Top() const
{
	return head->dataValue;
}

template<class Type>
int StackList<Type>::GetDataCounter() const
{
	return dataCounter;
}

template<class Type>
void StackList<Type>::PopData()
{
	StackNode *perPtr;

	perPtr = head;

	if(!IsEmpty())
	{
		head = perPtr->next;
	}

	dataCounter--;

	delete perPtr;
}

template<class Type>
bool StackList<Type>::IsEmpty() const
{
	return head == NULL;
}

template<class Type>
void StackList<Type>::DisplayDataTable()
{
	StackNode *delPtr;

	delPtr = head;

	while(delPtr != NULL)
	{
		cout << delPtr->dataValue << ' ';

		PopData();

		delPtr = head;
	}

	cout << endl;
}

template<class Type>
void StackList<Type>::FindAndDeleteData(Type delValue)
{
	bool found = false;
	StackNode *srchPtr;

	srchPtr = head;

	 while(!found && srchPtr != NULL)
	 {
		 if(srchPtr->dataValue == delValue)
		 {
			 found = true;
		 }

		 PopData();

		 srchPtr = head;

		 dataCounter--;
	 }
}

template<class Type>
void StackList<Type>::Print() const
{

	StackNode *srchPtr;

	srchPtr = head;

	while(srchPtr != NULL)
	{
		cout << srchPtr->dataValue << ' ';

		srchPtr = srchPtr->next;
	}

	cout << endl;

}

template class StackList<string>;
template class StackList<double>;
template class StackList<char>;
