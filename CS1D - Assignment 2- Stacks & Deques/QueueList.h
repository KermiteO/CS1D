
#ifndef QUEUELIST_H_
#define QUEUELIST_H_

#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

template<class Type>
class QueueList
{
	public:
		QueueList();

		~QueueList();

		void InitializeQueueList(const Type ARRAYDATA[],
								 const int  AR_SIZE);

		void DeQueueList();

		void FindAndDelete(Type delValue);

		void Print();

	private:
		struct QueueNode
		{
			Type dataValue;
			QueueNode *next;
		};

		QueueNode *head;
		QueueNode *tail;
};



#endif /* QUEUELIST_H_ */
