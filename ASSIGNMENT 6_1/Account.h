/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#ifndef ASSIGNMENT_6_ACCOUNT_H_
#define ASSIGNMENT_6_ACCOUNT_H_

#include <iostream>		//for cin/cout
#include <iomanip>		//for IO manipulators
#include <string>		//for strings
#include <limits>		//limits
#include <ios>			//streamsize
#include <fstream>		//for file stream
#include "Date.h"

using namespace std;

class Account
{
public:
	/*******************************
	 ** CONSTRUCTOR & DESTRUCTORS **
	 *******************************/
	Account();							//Default constructor
	Account(string 		   accName,
			unsigned short accNum,
			Date 		   accDate,
			float 		   accBalance,
			string		   accType);	//Non default constructor

	virtual ~Account();					//Deconstructor

	/***************
	 ** MUTATORS  **
	 ***************/
	void SetAccount(string 		   accName,
					unsigned short accNum,
					Date 		   accDate,
					float 		   accBalance,
					string		   accType);   //Method that sets a full account

	void SetAccount(Date upDate);

	void SetAccount(float accBalance);		   //Method that sets the balance

	bool DepositeAccount(float  depositeAmt,
						 Date	currentDate);  //Method that deposites amount
											   //into account

	virtual bool WithdrawAccount(ofstream &outfile,
							     float    withdrawAmt,
							     Date     currentDate);//Virtual Method that
													   //withdraws from account

	virtual void UpdateAccount(float newBalance,
			 	 	   	   	   Date  newDate);		   //Virtual Method that update
													   //the balance with interest

	/****************
	 ** ACCESSORS  **
	 ****************/
	string GetAccName() const;

	unsigned short GetAccNumber() const;

	Date GetAccDate() const;

	float GetAccBalance() const;

	string GetAccType() const;

	string OutputAccount(float currentAmount) const;

private:
	string  	   name;
	unsigned short accountNum;
	Date 		   date;
	float 		   balance;
	string		   accountType;
};

/***********************************************************************
 * Account Class
 *   This class represents a Account object
 *   It manages 5 attributes: The name, accountNum, date, balance, &
 *   accountType.
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/

/***********************************************************************
 ** Account();
 **   Default Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** Account();
 **   Constructor; Initializes class attributes to the specified values
 **   Parameter: accName, accNum, accDate, accBalance, accType
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~Animal();
 **   Destructor; Does not perform any specific function
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***************
 ** MUTATORS  **
 ***************/

/***********************************************************************
 ** SetAccount
 **
 **   Mutator; This function sets the attributes of Account to specific
 **   		   values.
 **---------------------------------------------------------------------
 **   Parameter: accName, accNum, accDate, accBalance, and accType
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** SetAccount
 **
 **   Mutator; This overloaded function sets the date attribute to a
 **   		   specific variable.
 **---------------------------------------------------------------------
 **   Parameter: upDate
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** SetAccount
 **
 **   Mutator; This overloaded function sets the balance attribute to a
 **   		   specific variable.
 **---------------------------------------------------------------------
 **   Parameter: newBalance
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** DepositeAccount
 **
 **   Mutator; This function deposites an amount into an account.
 **---------------------------------------------------------------------
 **   Parameter: depositeAmt and currentDate
 **---------------------------------------------------------------------
 **   Returns: bool
 ***********************************************************************/

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

/****************
 ** ACCESSORS  **
 ****************/

/***********************************************************************
 ** GetAccName
 **
 **   Accessor; This returns the name of the account
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the name of the account
 ***********************************************************************/

/***********************************************************************
 ** GetAccNum
 **
 **   Accessor; This returns the account number of the account
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the account number
 ***********************************************************************/

/***********************************************************************
 ** GetAccDate
 **
 **   Accessor; This returns the account Date
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the Date number
 ***********************************************************************/

/***********************************************************************
 ** GetAccBalance
 **
 **   Accessor; This returns the account balance
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the account balance
 ***********************************************************************/

/***********************************************************************
 ** GetAccType
 **
 **   Accessor; This returns the account type of the account
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the account type
 ***********************************************************************/

/***********************************************************************
 ** OutputAccount
 **
 **   Accessor; This method will output an account & its info in a single
 **   			line to the output file.
 **---------------------------------------------------------------------
 **   Parameter: outfile, and currentAmount
 **---------------------------------------------------------------------
 **   Returns: string
 ***********************************************************************/


#endif /* ASSIGNMENT_6_ACCOUNT_H_ */
