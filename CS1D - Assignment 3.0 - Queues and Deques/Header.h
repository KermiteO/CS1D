/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #3: Queue/Deque
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

//Global constants go here
const int HEADER = 13;

string PrintHeader(char   prType,
				   string programmer,
				   int	  prNum,
				   string prName,
				   string prompt);

int *ExtendArray(int *&array,
				 int n,
                 int &front,
                 int &rear,
                 int &maxElem);

void AddFront(int *&extArr,
		      int *&newExt,
              int newNum,
              int &front,
              int &rear,
              int &maxElem,
              int newMaxElem);

void AddRear(int *&extArr,
		     int *&newExt,
             int newNum,
             int &front,
             int &rear,
             int &maxElem,
			 int newMaxElem);

void DeleteFront(int *&extArr,
				 int &front,
				 int rear,
				 int maxElem);

void DeleteRear(int *&extArr,
				int &front,
				int rear,
				int maxElem);

void Print(int  numArray[],
		   int  size);

void Print(int  		numArray[],
		   vector<char> charArr,
		   vector<char> cursArr,
		   int			front,
		   int			rear,
		   int  		size);

vector<char> UpdateFrontRear(int circArr[],
							 int size,
							 int front,
							 int rear);

vector<char> UpdateCursor(int circArr[],
						  int size,
						  int front,
						  int rear);

bool IsFull(int *array,
			int size);


#endif /* HEADER_H_ */
