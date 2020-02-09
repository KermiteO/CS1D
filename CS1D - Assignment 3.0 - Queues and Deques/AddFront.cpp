#include "Header.h"

void AddFront(int *&extArr,
		      int *&newExt,
              int newNum,
              int &front,
              int &rear,
              int &maxElem,
              int newMaxElem)
{
	if(front == rear + 1 || IsFull(extArr, maxElem))
	{
		//if the front and rear indeces are 1 element away from each
		//other, that means that the array is full & needs to be extended in
		//order to add the new number
		newExt = ExtendArray(extArr, maxElem + 1,front,rear,newMaxElem);

		front = 0;

		rear = maxElem + 1;

		newExt[front] = newNum;

		maxElem = newMaxElem;

		vector<char> cursArr = UpdateCursor(newExt,maxElem + 1,front,rear);

		vector<char> charArr =UpdateFrontRear(newExt, maxElem + 1,front,rear);

		Print(newExt,charArr,cursArr,front,rear,maxElem + 1);
	}
	else
	{
		//if the front of the list is the beginning of the array, add the
		//new number to the end of the array
		if(front != 0 && extArr[maxElem] != 0)
		{
			//if not then add to the element right before the index of front
			extArr[front - 1] = newNum;

			front--;
		}
		else
		{
			front = maxElem;

			extArr[front] = newNum;
		}

		vector<char> cursArr = UpdateCursor(extArr,maxElem + 1,front,rear);

		vector<char> charArr =UpdateFrontRear(extArr, maxElem + 1,front,rear);

		Print(extArr,charArr,cursArr,front,rear,maxElem + 1);
	}
}
