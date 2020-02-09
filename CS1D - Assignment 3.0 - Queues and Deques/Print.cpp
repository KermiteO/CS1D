#include "Header.h"

void Print(int  numArray[],
		   int  size)
{
	for(int i = 0; i < size; i++)
	{
		cout << numArray[i] << ' ';
	}
}

void Print(int  		numArray[],
		   vector<char> charArr,
		   vector<char> cursArr,
		   int			front,
		   int			rear,
		   int  		size)
{
	for(int i = 0; i < size; i++)
	{
		cout << numArray[i] << ' ';
	}
	cout << endl;

	for(int i = 0; i < size; i++)
	{
		cout << cursArr[i] << ' ';
	}
	cout << endl;

	for(int i = 0; i < size; i++)
	{
		cout << charArr[i] << ' ';
	}
}
