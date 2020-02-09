/*************************************************************************
 * AUTHOR		: Omar Kermiche
 * ASSIGNMENT#11: Directed Graphs
 * CLASS		: CS1D
 * SECTION 		: M/W 3pm
 * DUE DATE		: 4/12/17
 ************************************************************************/

#include "header.h"

/*************************************************************************
 * Assignment 11 - Directed Graphs, DFS, BFS
 * _______________________________________________________________________
 * This program will allow the programmer to create a directed graph.
 * It should traverse the graph in a depth first search and then a breadth
 * first search.
 * _______________________________________________________________________
 * INPUT:
 * <nothing is input from the keyboard here>
 * 		intAr		: the array of numbers holding city keys
 * 		stringAr	: the array of names that will be input for the
 * 					  heap (in form of an array)
 * OUTPUT:
 *		myGraph	: the graph variable to insert/output
 ************************************************************************/

int main()
{
	/*****************************************************************
	* CONSTANTS
	* ---------------------------------------------------------------
	* USED FOR CLASS HEADINGS - ALL WILL BE OUTPUT
	* ---------------------------------------------------------------
	* PROGRAMMER : Programmer's Name
	* CLASS		 : Student's Course
	* SECTION	 : Class Days and Times
	* LAB_NUM	 : Lab Number (specific to this lab)
	* LAB_NAME   : Title of the Lab
	* ----------------------------------------------------------------
	****************************************************************/
		//Constant Declarations
		const string PROGRAMMER = "Omar Kermiche";
		const string CLASS 	 	= "CS1D";
		const string SECTION 	= "M/W 3pm";
		const int 	 LAB_NUM	=  11;
		const string LAB_NAME 	= "Directed Graphs, BFS, DFS";

		//Calls the function PrintHeader to output the author box
		PrintHeader(PROGRAMMER, CLASS, SECTION,LAB_NUM, LAB_NAME, 'A', cout);

		//Description
		cout << "The purpose of the lab is to show the the implem. of \n"
				"of a directed graph and traversals breadth first and \n"
				"depth first. This will demonstrate knowledge of graphs\n"
				"and functions that enable the graph ADT\n\n";

	//Variable Declaration
	Graph myGraph;		//To be worked on later

	//The 2 numbers are used from their indices in cityArray
	myGraph.addEdge(1, 0, 2097);
	myGraph.addEdge(1, 2, 983);
	myGraph.addEdge(2, 3, 214);
	myGraph.addEdge(3, 4, 888);
	myGraph.addEdge(4, 5, 661);
	myGraph.addEdge(5, 6, 1187);
	myGraph.addEdge(6, 7, 239);
	myGraph.addEdge(7, 8, 496);
	myGraph.addEdge(8, 9, 599);
	myGraph.addEdge(9, 10, 1267);
	myGraph.addEdge(10, 11, 381);
	myGraph.addEdge(0, 9, 1331);
	myGraph.addEdge(0, 10, 807);
	myGraph.addEdge(9, 1, 1003);
	myGraph.addEdge(8, 1, 533);
	myGraph.addEdge(3, 1, 787);
	myGraph.addEdge(8, 3, 1260);
	myGraph.addEdge(8, 4, 864);
	myGraph.addEdge(7, 4, 781);
	myGraph.addEdge(6, 4, 810);
	myGraph.addEdge(7, 11, 1435);
	myGraph.addEdge(8, 11, 1663);
	myGraph.addEdge(11, 9, 1015);

	//Output everything in a matrix formation
	myGraph.outputAll();

	//Output everything in the DFS formation
	cout << "\nImplementing DFS... starting at Atlanta\n";
	myGraph.DFS(4,0);

//	//Output everything in the BFS formation
	cout << "\n\nImplementing BFS... starting at Atlanta\n";
	myGraph.BFS(4,0);

	cout << "\nPart C:\nI think because there is a path between all the \n"
			"vertices for both the DFS and BFS traversal algorithms and \n"
			"there never was a case where we had to use a back edge, this \n"
			"graph is strongly connected.";
 return 0;
}
