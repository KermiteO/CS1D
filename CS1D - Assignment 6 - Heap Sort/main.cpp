
#include "Header.h"
#include "Heap.h"



int main()
{
	//Constant Declarations go here
	const char   PROJECT_TYPE = 'A';
	const string PROGRAMMER   = "Omar Kermiche";
	const int	 LAB_NUM      = 6;
	const string LAB_NAME     = "Heap Sort";

	//Variable declarations
	string prompt = "* In this assignment the goal is to be able to insert 10\n"
					"* team objects into a heap and then sort that heap by\n"
					"* swapping the root of the heap(which is the object with\n"
					"* the absolute minimum key value in the heap) with the\n"
					"* last node in the heap. We first store the root in a\n"
					"* vector and we delete the root by decrementing\n"
					"* the heap size by 1 and then utilizing a recursive \n"
					"* function called DownHeap, we sift the current root\n"
					"* down level by level until the heap order is restored. \n"
					"* We then repeat this whole process until all the nodes\n"
					"* have been removed from the heap. We then finally \n"
					"* output the vector which contains the sorted heap.\n";

	Heap h(10);

	Object t1("Rams", 33);
	Object t2("Vikings", 22);
	Object t3("Lions", 12);
	Object t4("Dolphins", 44);
	Object t5("Patriots", 123);
	Object t6("Bengals", 44);
	Object t7("Packers", 69);
	Object t8("Broncos", 24);
	Object t9("Bears", 13);
	Object t10("Chargers", 42);

	//OUTPUT - ASSIGNMENT HEADER
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME, prompt);

	//INPUT - insert all the teams into the heap and output each intermediate heap
	cout << "AFTER ADDING THE RAMS TO THE HEAP:\n\n";
	h.insert(t1);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE VIKINGS TO THE HEAP:\n\n";
	h.insert(t2);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE LIONS TO THE HEAP:\n\n";
	h.insert(t3);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE DOLPHINS TO THE HEAP:\n\n";
	h.insert(t4);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE PATRIOTS TO THE HEAP:\n\n";
	h.insert(t5);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE BENGALS TO THE HEAP:\n\n";
	h.insert(t6);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE PACKERS TO THE HEAP:\n\n";
	h.insert(t7);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE BRONCOS TO THE HEAP:\n\n";
	h.insert(t8);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE BEARS TO THE HEAP:\n\n";
	h.insert(t9);
	h.breadthFirstOrder();
	cout << "AFTER ADDING THE CHARGERS TO THE HEAP:\n\n";
	h.insert(t10);
	h.breadthFirstOrder();

	//PROC/OUTPUT - perform the heap sort by calling removeMin and output the
	//resulting heap. keep removing until the list is empty
	cout << "\n\nREMOVING 1ST NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 2ND NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 3RD NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 4TH NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 5TH NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 6TH NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 7TH NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 8TH NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 9TH NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();
	cout << "\n\nREMOVING 10TH NODE FROM THE ROOT YIELDS:\n";
	h.removeMin();
	h.breadthFirstOrder();

	//OUTPUT - print the sorted heap
	cout << "\n\nAFTER REMOVING ALL THE NODES THE SORTED HEAP LOOKS LIKE THIS:\n";
	h.PrintSortedHeap();


	cout << endl;

	return 0;
}
main.cpp
Open with
Displaying main.cpp.

