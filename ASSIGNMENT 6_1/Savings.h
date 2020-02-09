/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#ifndef ASSIGNMENT_6_SAVINGS_H_
#define ASSIGNMENT_6_SAVINGS_H_

#include <iostream>		//for cin/cout
#include <iomanip>		//for IO manipulators
#include <string>		//for strings
#include <limits>		//limits
#include <ios>			//streamsize
#include "Account.h"

using namespace std;

class Savings: public Account
{
public:
	/*******************************
	 ** CONSTRUCTOR & DESTRUCTORS **
	 *******************************/
	Savings();								//Default Constructor

	Savings(string 		   accName,
		    unsigned short accNum,
		    Date 		   accDate,
		    float 		   accBalance,
		    string		   accType,
		    float          marketInterest); //Non Default constructor

	virtual ~Savings();						//Deconstructor

	/***************
	 ** MUTATORS  **
	 ***************/
	virtual bool WithdrawAccount(ofstream &outfile,
								 float    withdrawAmt,
								 Date     currentDate); //Virtual Method that
	   	   	   	   	   	   	   	   	   	   	   	   	    //withdraws from account

	virtual void UpdateAccount(float newBalance,
				 	 	   	   Date  newDate);			//Virtual Method that update
														//the balance with interest

private:
	float savingsInterest;
};

/***********************************************************************
 * Savings Class
 *   This class represents a Account object
 *   It manages 1 attribute: The savingsInterest
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/

/***********************************************************************
 ** Savings();
 **   Default Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** Savings();
 **   Constructor; Initializes class attributes to the specified values
 **   Parameter: accName, accNum, accDate, accBalance, accType, &
 **   			 savingsInterest
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~Savings();
 **   Destructor; Does not perform any specific function
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***************
 ** MUTATORS  **
 ***************/

/***********************************************************************
 ** WithdrawAccount
 **
 **   Mutator; This function withdraws an amount from an account.
 **---------------------------------------------------------------------
 **   Parameter: outfile, withdrawAmt, and currentDate
 **---------------------------------------------------------------------
 **   Returns: bool
 ***********************************************************************/

/***********************************************************************
 ** UpdateAccount
 **
 **   Mutator; This function updates the balance by checking the current
 **   		   date of a new transaction and adding the respective
 **   		   interest to the balance.
 **---------------------------------------------------------------------
 **   Parameter: newBalance, newDate
 **---------------------------------------------------------------------
 **   Returns: nothing
 ***********************************************************************/


#endif /* ASSIGNMENT_6_SAVINGS_H_ */
