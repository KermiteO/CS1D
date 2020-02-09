#include "Header.h"

void AddRear(int *&extArr,
		     int *&newExt,
             int newNum,
             int &front,
             int &rear,
             int &maxElem,
			 int newMaxElem)
{
	//will add to the rear of the circular array
	if(front != rear + 1 || rear != front + 1 ||(front != 0 && rear != maxElem))
	{
		extArr[rear + 1] = newNum;

		rear++;

		vector<char> cursArr = UpdateCursor(extArr,maxElem + 1,front,rear);

		vector<char> charArr = UpdateFrontRear(extArr, maxElem + 1,front,rear);

		Print(extArr,charArr,cursArr,front,rear,maxElem + 1);
	}
	else
	{
		//if the front and rear indeces are 1 element away from each other,
		//that means that the array is full and needs to be extended in order
		//to add the new number
		newExt = ExtendArray(extArr, maxElem + 1, front, rear, newMaxElem);

		front = 0;

		rear = maxElem + 2;

		newExt[rear] = newNum;

		maxElem = newMaxElem;

		vector<char> cursArr = UpdateCursor(newExt,maxElem + 1,front,rear);

		vector<char> charArr = UpdateFrontRear(newExt, maxElem + 1,front,rear);

		Print(newExt,charArr,cursArr,front,rear,maxElem + 1);
	}
}
