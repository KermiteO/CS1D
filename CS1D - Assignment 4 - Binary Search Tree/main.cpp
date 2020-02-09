/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #4: Binary Search Tree
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#include "Header.h"
#include "BinarySrchTree.h"

int main()
{
	//Constant Declarations go here
	const char   PROJECT_TYPE = 'A';
	const string PROGRAMMER   = "Omar Kermiche";
	const int	 LAB_NUM      = 4;
	const string LAB_NAME     = "Binary Search Tree";

	BinarySearchTree theTree;
	string prompt = "* This assignment implements a linked list as a binary \n"
					"* search tree.It stores some number of elements & performs\n"
					"* in order, pre order, post order, and breadth first \n"
					"* traversals.";

	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME, prompt);

	theTree.insert(11);
	theTree.insert(12);
	theTree.insert(24);
	theTree.insert(14);
	theTree.insert(5);
	theTree.insert(86);
	theTree.insert(47);
	theTree.insert(88);
	theTree.insert(19);
	theTree.insert(13);
	theTree.insert(109);
	theTree.insert(18);
	theTree.insert(44);

	cout << "\nIN-ORDER TRAVERSAL:\n";
	theTree.print_inorder();

	cout << "\n\nPRE-ORDER TRAVERSAL:\n";
	theTree.print_preorder();

	cout << "\n\nPOST-ORDER TRAVERSAL:\n";
	theTree.print_postorder();

	cout << "\n\nBREADTH FIRST TRAVERSAL:\n";
	theTree.breadthFirstOrder();


	return 0;
}

