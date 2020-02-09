#ifndef HEAP_H_
#define HEAP_H_

#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<math.h>
#include<vector>
#include"Object.h"
using namespace std;


class Heap {
private:
      Object *data;
      vector<Object> sorted;
      int heapSize;
      int arraySize;

      int getLeftChildIndex(int nodeIndex) {
            return 2 * nodeIndex + 1;
      }

      int getRightChildIndex(int nodeIndex) {
            return 2 * nodeIndex + 2;
      }

      int getParentIndex(int nodeIndex) {
            return (nodeIndex - 1) / 2;
      }

public:
      Heap(int size)
	  {
            data = new Object[size];
            heapSize = 0;
            arraySize = size;
      }

      void siftUp(int nodeIndex)
      {
            int parentIndex;
			Object tmp;
            if (nodeIndex != 0)
            {
            	//set parent index equal to parent index of curr child index
                  parentIndex = getParentIndex(nodeIndex);
                  if (data[parentIndex].GetKey() > data[nodeIndex].GetKey())
                  {
                	  //swap the two elements
                        tmp = data[parentIndex];
                        data[parentIndex] = data[nodeIndex];
                        data[nodeIndex] = tmp;
                        //bubble up until reach root
                        siftUp(parentIndex);
                  }
            }
      }

      void insert(Object value)
      {
            if (heapSize == arraySize)
            {
                throw string("Heap's underlying storage is overflow");
            }
            else
            {
            	//increment the size of the heap and insert the new object to the
            	//end of the heap. call sift up.
                  heapSize++;
                  data[heapSize - 1] = value;
                  siftUp(heapSize - 1);
            }
      }

      void heapDown(int nodeIndex)
      {
            int leftChildIndex, rightChildIndex, minIndex;
			Object tmp;
            leftChildIndex = getLeftChildIndex(nodeIndex);
            rightChildIndex = getRightChildIndex(nodeIndex);
            if (rightChildIndex >= heapSize) //if the right index is bigger or equal
            								 //to the heap size
            {
                  if (leftChildIndex >= heapSize) //if the left index exceeds the heap
                	  	  	  	  	  	  	  	  //size, end recursion and if not set
                	  	  	  	  	  	  	  	  //the minimum index as the left index
                        return;
                  else
                        minIndex = leftChildIndex;
            }
            else
            {
            	//if the key value of the left child is less than the right child,
            	//set the minimum index to left index and if not the right index
			  if (data[leftChildIndex].GetKey() <= data[rightChildIndex].GetKey())
					minIndex = leftChildIndex;
			  else
					minIndex = rightChildIndex;
            }
            //if the key value of the current root is bigger than the key of the curr
            //minIndex swap the elements and perform bubble down by calling recursive
            //heapDown method again
            if (data[nodeIndex].GetKey() > data[minIndex].GetKey())
            {
                  tmp = data[minIndex];
                  data[minIndex] = data[nodeIndex];
                  data[nodeIndex] = tmp;
                  heapDown(minIndex);
            }
      }

      void removeMin()
      {
            if (isEmpty())
            {
                throw string("Heap is empty");
            }
            else
            {
            	//push the root to the sorted vector before swapping and deleting root
            	sorted.push_back(data[0]);

			    data[0] = data[heapSize - 1];
			    heapSize--;
			    if (heapSize > 0) //as long as the size is bigger than 0 call heapDown
			    	heapDown(0);
            }
      }

      Object getMinimum()
      {
            if (isEmpty())
            {
                throw string("Heap is empty");
            }
            else
            {
            	 return data[0];
            }
      }

      void breadthFirstOrder()
      {
    	  const int TREE_FORM = 30;
		  int levels;
		  int numNodes;
		  int j;

		  numNodes = 0;

		  j = 0;

		  levels = pow(2, j);

		  //parse through heap and print out nodes
		  for(int i = 0; i < heapSize; i++)
		  {
			  //sets the formatting for each level
		  	  if(i == 0)
		  	  {
		  	  	  cout << setw(TREE_FORM);
		  	  }
		  	  else if(i == 1)
		  	  {
		  	  	  cout << setw(TREE_FORM - 10);
		  	  }
		  	  else if(i == 3)
		  	  {
		  	  	  cout << setw(TREE_FORM - 20);
		  	  }
		  	  else if(i ==7)
		  	  {
		  	  	  cout << setw(TREE_FORM - 30);
		  	  }

		  	  //doesn't print empty nodes
		  	  if(data[i].GetName() != "")
		  	  {
		  		cout << " "<< "(" << data[i].GetName() << ", "
					 << data[i].GetKey() << ")";
		  	  }

		  	  numNodes++;

		  	  //this if statement is to check whether or not to end line the output
		  	  //It should go to the next line if the tot number of nodes reaches
		  	  //the current levels variable. Increment the levels var to next level.
		  	  if(numNodes == levels)
		  	  {
		  	  	  j = levels++;

		  	  	  levels = pow(2, j);

		  	  	  cout << endl << endl;

		  	  	  numNodes = 0;
		  	  }
		  }

		  cout << endl;
      }

      void PrintSortedHeap()
      {
    	  const int TREE_FORM = 30;
		  int levels;
		  int numNodes;
		  int j;

		  numNodes = 0;

		  j = 0;

		  levels = pow(2, j);

		  //parse through vector of objects and print out node
		  for(int i = 0; i < arraySize; i++)
		  {
			  if(i == 0)
			  {
				  cout << setw(TREE_FORM);
			  }
			  else if(i == 1)
			  {
				  cout << setw(TREE_FORM - 10);
			  }
			  else if(i == 3)
			  {
				  cout << setw(TREE_FORM - 20);
			  }
			  else if(i ==7)
			  {
				  cout << setw(TREE_FORM - 30);
			  }

		  	  //doesn't print empty nodes
			  if(data[i].GetName() != "")
			  {
				cout << " "<< "(" << sorted[i].GetName() << ", "
					 << sorted[i].GetKey() << ")";
			  }

			  numNodes++;

			  //this if statement is to check whether or not to end line the output
			  //It should go to the next line if the tot number of nodes reaches
			  //the current levels variable. Increment the levels var to next level.
			  if(numNodes == levels)
			  {
				  j = levels++;

				  levels = pow(2, j);

				  cout << endl << endl;

				  numNodes = 0;
			  }
		  }

		  cout << endl;
      }

      bool isEmpty() {return (heapSize == 0);}

      ~Heap() {delete[] data;}
};



#endif /* HEAP_H_ */
