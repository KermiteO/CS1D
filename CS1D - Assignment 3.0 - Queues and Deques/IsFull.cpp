#include "Header.h"

bool IsFull(int *array,
			int size)
{
	bool full 		= false;
	int  i 			= 0;
	int  emptyElems = 0;

	while(!full && i <= size)
	{
		if(array[i] == 0)
		{
			emptyElems += 1;
		}

		i++;
	}

	if(emptyElems == 0)
	{
		full = true;
	}

	return full;
}
