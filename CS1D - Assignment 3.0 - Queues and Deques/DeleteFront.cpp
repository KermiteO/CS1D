#include "Header.h"

void DeleteFront(int *&extArr,
				 int &front,
				 int rear,
				 int maxElem)
{
	extArr[front] = 0;

	if(front == maxElem)
	{
		front = 0;
	}
	else
	{
		front++;
	}
}
