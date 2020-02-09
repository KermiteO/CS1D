/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #3: Queue/Deque
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#include "Header.h"

string PrintHeader(char   prType,
				   string programmer,
				   int	  prNum,
				   string prName,
				   string prompt)
{
	ostringstream output;

	output << left;
	output << "*************************************************************\n";
	output << "* PROGRAMMED BY : " << programmer;
	output << "\n*" << setw(15) << " CLASS" << ": CS1D\n";
	output << "*"   << setw(15) << " PROFESSOR" << ": Jerry Lebowitz\n";
	output << "*";

	if(toupper(prType) == 'L')
	{
		output << " Lab #" << setw(9);
	}
	else
	{
		output << " ASSIGNMENT #" << setw(2);
	}
	output << prNum << ": " << prName;
	output << "\n*\n* Description:\n" << prompt << endl;
	output <<"*************************************************************\n";
	output << right;

	return output.str();
}
