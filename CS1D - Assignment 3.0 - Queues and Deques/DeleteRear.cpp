#include "Header.h"

void DeleteRear(int *&extArr,
				int &front,
				int rear,
				int maxElem)
{
	extArr[rear] = 0;

	rear--;
}
