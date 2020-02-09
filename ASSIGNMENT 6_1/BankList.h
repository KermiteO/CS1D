/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#ifndef ASSIGNMENT_6_BANKLIST_H_
#define ASSIGNMENT_6_BANKLIST_H_

#include <iostream>		//for cin/cout
#include <iomanip>		//for IO manipulators
#include <string>		//for strings
#include <limits>		//limits
#include <ios>			//streamsize
#include <fstream>		//for file stream
#include "Account.h"

using namespace std;

class BankList
{
public:
	/*******************************
	 ** CONSTRUCTOR & DESTRUCTORS **
	 *******************************/
	BankList();	  // Constructor
	~BankList();  // Deconstructor


	/***************
	 ** MUTATORS  **
	 ***************/
	void AddAccount(Account *&newAccount);			// method to adds a new account

	bool TransferAmount(ofstream       &outfile,
			            Date	       currentDate,
			            float 		   transferAmt,
			            unsigned short toAccNum,
			            unsigned short fromAccNum);//method that transfers amount
												   //between 2 accounts

	/***************
	 ** ACCESSORS **
	 ***************/
	void OutputLinkList(ofstream &outfile) const;  //method that outputs d.l.l.

	bool IsEmpty() const;						   //method that checks if list
												   //is empty

	void FindAccount(unsigned short thisAccNum,
				   	 Account	   *&thisAccount) const; //method that finds an
														 //an account

	void DisplayTransaction(string 		   transacType,
							float  		   currentAmount,
							unsigned short currentAccNum,
							Account		   *&transacAccount,
							ofstream       &outfile) const;//method that outputs
														   //one account

private:
	struct AccountNode
	{
		Account     *myAccount;
		AccountNode *next;
		AccountNode *prev;
	};

	AccountNode *head;
	AccountNode *tail;
};

/***********************************************************************
 * BankList Class
 *   This class represents a BankList object
 *   It manages 2 attributes: head and tail of a doubly linked list
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/

/***********************************************************************
 ** BankList();
 **   Default Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns  : Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~BankList();
 **   Destructor; Will clear the link list
 **   Parameter: None
 **   Returns  : Nothing
 ***********************************************************************/

/***************
 ** MUTATORS  **
 ***************/

/***********************************************************************
 ** AddAccount
 **
 **   Mutator; This function will add an account to a doubly linked list
 **---------------------------------------------------------------------
 **   Parameter: newAccount (Account)
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** TransferAmount
 **
 **   Mutator; This function will transfer an amount from one account
 **   		   to another account by utilizing the deposite and withdraw
 **   		   methods of Account.
 **---------------------------------------------------------------------
 **   Parameter: outfile 	 (ofstream)
 **   			 currentDate (Date)
 **   			 transferAmt (float)
 **   			 toAccNum	 (short)
 **   			 fromAccNum	 (short)
 **---------------------------------------------------------------------
 **   Returns: transferSuccess (boolean)
 ***********************************************************************/

/****************
 ** ACCESSORS  **
 ****************/

/***********************************************************************
 ** OutputLinkList
 **
 **   Accessor; This function will output a table heading and all the
 **  		    accounts in the link list to the output file.
 **---------------------------------------------------------------------
 **   Parameter: outfile (ofstream)
 **---------------------------------------------------------------------
 **   Returns: outfile (by reference)
 ***********************************************************************/

/***********************************************************************
 ** IsEmpty
 **
 **   Accessor; This returns a condition that indicates the list is
 **   			empty.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: head == NULL (boolean)
 ***********************************************************************/

/***********************************************************************
 ** FindAccount
 **
 **   Accessor; This returns a pointer to an account by reference & will
 **   			search a link list for a specific account.
 **---------------------------------------------------------------------
 **   Parameter: thisAccNum  (short)
 **   			 thisAccount (Account)
 **---------------------------------------------------------------------
 **   Returns: a pointer to an account
 ***********************************************************************/

/***********************************************************************
 ** DisplayTransaction
 **
 **   Accessor; This method will display an account transaction to an
 **   			input file.
 **---------------------------------------------------------------------
 **   Parameter: transacType    (string)
 **   			 currentAmount  (float)
 **   			 currentAccNum  (short)
 **   			 transacAccount (Account)
 **   			 outfile	    (ofstream)
 **---------------------------------------------------------------------
 **   Returns: nothing
 ***********************************************************************/


#endif /* ASSIGNMENT_6_BANKLIST_H_ */
