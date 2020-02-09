#include "Header.h"

vector<char> UpdateFrontRear(int circArr[],
							 int size,
							 int front,
			   	     	     int rear)
{
	vector<char> charArr(size);

	for(int i = 0; i < size; i++)
	{
		if(i == front)
		{
			charArr[i] = 'F';
		}
		else if(i == rear)
		{
			charArr[i] = 'R';
		}
		else
		{
			charArr[i] = ' ';
		}
	}

	return charArr;
}

vector<char> UpdateCursor(int circArr[],
						  int size,
						  int front,
						  int rear)
{
	vector<char> cursArr(size);

		for(int i = 0; i < size; i++)
		{
			if(i == front || i == rear)
			{
				cursArr[i] = '^';
			}
			else
			{
				cursArr[i] = ' ';
			}
		}

		return cursArr;
}
