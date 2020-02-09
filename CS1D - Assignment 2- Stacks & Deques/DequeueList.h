
#ifndef DEQUEUELIST_H_
#define DEQUEUELIST_H_

#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

template<class Type>
class DequeueList
{
public:
	DequeueList();
	~DequeueList();

	void InitializeList(const Type DATA[],
						const int  AR_SIZE);

	void PopFront();

	void PopBack();

	void Print();

	void SearchDestroy(Type delVal);

private:
	struct DequeueNode
	{
		Type 		dataValue;
		DequeueNode *next;
	};

	void PushFront(DequeueNode *newNode);

	void PushBack(DequeueNode *newNode);

	DequeueNode *head;
	DequeueNode *tail;

	int dataCount;
};



#endif /* DEQUEUELIST_H_ */
