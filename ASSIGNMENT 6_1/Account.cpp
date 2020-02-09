/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#include "Account.h"

/**************************************************************************
 * Constructor Account() : Class Account
 *_________________________________________________________________________
 *	This is the default Account constructor, initializes balance & accNumber
 *  to 0.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Initializes the data items for an Account object
 *************************************************************************/
Account::Account()
{
	balance     = 0.0;
	accountNum  = 0;
}

/**************************************************************************
 * Constructor Account() : Class Account
 *_________________________________________________________________________
 *	This is a non-default Account constructor, initializes attributes to
 *	specific values.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	accName    : the name of the person with an account
 * 	accNum     : the account number
 * 	accDate    : the date the account was created/accessed
 * 	accBalance : the balance amount for the account ($)
 * 	accType	   : the account type
 * POST-CONDITIONS
 * 	Initializes the data items for an Account object
 *************************************************************************/
Account::Account(string 		accName,
				 unsigned short accNum,
				 Date	 		accDate,
				 float 		    accBalance,
				 string		    accType)
{
	accountNum  = accNum;
	balance     = accBalance;
	name	    = accName;
	date	    = accDate;
	accountType = accType;

}

/**************************************************************************
 * Destructor ~Account() : Class Account
 *_________________________________________________________________________
 *	This is the default Account Destructor, does nothing special
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	none
 *************************************************************************/
Account::~Account() {}


/**************************************************************************
 * Method SetAccount : Class Account
 *_________________________________________________________________________
 *	This method sets the data stored in all five attributes
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	accName    : the name of the person with an account
 * 	accNum     : the account number
 * 	accDate    : the date the account was created/accessed
 * 	accBalance : the balance amount for the account ($)
 * 	accType	   : the account type
 * POST-CONDITIONS
 * 	Sets the data stored in all the attributes
 *************************************************************************/
void Account::SetAccount(string 	    accName,
						 unsigned short accNum,
						 Date 			accDate,
						 float 		    accBalance,
						 string		    accType)
{
	name 	    = accName;
	accountNum  = accNum;
	date 	    = accDate;
	balance     = accBalance;
	accountType = accType;
}

/**************************************************************************
 * Method SetAccount : Class Account
 *_________________________________________________________________________
 *	This method sets the date attribute to a specific value.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	upDate    : the new updated date of the person with an account
 * POST-CONDITIONS
 * 	Sets the date attribute
 *************************************************************************/
void Account::SetAccount(Date upDate)
{
	date = upDate;
}

/**************************************************************************
 * Method SetAccount : Class Account
 *_________________________________________________________________________
 *	This method sets the balance attribute to a specific value.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	accBalance : the balance amount for the account ($)
 * POST-CONDITIONS
 * 	Sets the balance attribute
 *************************************************************************/
void Account::SetAccount(float accBalance)
{
	balance = accBalance;
}

/**************************************************************************
 * Method DepositeAccount : Class Account
 *_________________________________________________________________________
 *	This method deposites a certain amount of money into an account.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	depositeAmt : the amount to deposite
 *	currentDate : the updated new date of the account made a transaction
 * POST-CONDITIONS
 * 	Deposites an amount into an account.
 *************************************************************************/
bool Account::DepositeAccount(float depositeAmt,
							  Date  currentDate)
{
	bool  depositeSuccess;
	float newBalance;

	depositeSuccess = false;

	if(depositeAmt != 0)
	{
		newBalance = balance;

		UpdateAccount(newBalance, currentDate);

		balance += depositeAmt;

		depositeSuccess = true;
	}

	return depositeSuccess;
}

/**************************************************************************
 * Method WithdrawAccount : Class Account
 *_________________________________________________________________________
 *	This method withdraws a certain amount of money from an account, and
 *	because it's a virtual function, it calls the withdraw method of either
 *	Savings, Checking, or MoneyMarket depending on what type of account it
 *	is. The outfile variable is passed back by reference so error statements
 *	can be placed in the method. Returns -> boolean
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * outfile		: the output file variable
 *	withdrawAmt : the amount to withdraw
 *	currentDate : the updated new date of the account made a transaction
 * POST-CONDITIONS
 * 	returns a boolean of whether the withdraw was successful or not.
 *************************************************************************/
bool Account::WithdrawAccount(ofstream &outfile,
							  float    withdrawAmt,
							  Date     currentDate)
{
	return (WithdrawAccount(outfile, withdrawAmt, currentDate));
}

/**************************************************************************
 * Method UpdateAccount : Class Account
 *_________________________________________________________________________
 *	This method updates an accounts balance by checking to see how much
 *	time has passed and then adding the appropriate interest depending
 *	on what type of account it is. It then sets the new balance and then
 *	updates the current date of the account to the new date.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	depositeAmt : the amount to deposite
 *	currentDate : the updated new date of the account made a transaction
 * POST-CONDITIONS
 * 	Adds interest to balance and resets the date of an account.
 *************************************************************************/
void Account::UpdateAccount(float newBalance,
							Date  newDate)
{
	UpdateAccount(newBalance, newDate);
}

/**************************************************************************
 * Method GetAccName: Class Account
 *_________________________________________________________________________
 *	This method gets and returns the account Name..
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 *  returns the account name
 *************************************************************************/
string Account::GetAccName() const
{
	return name;
}

/**************************************************************************
 * Method GetAccNum: Class Account
 *_________________________________________________________________________
 *	This method gets and returns the account number.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *  none
 * POST-CONDITIONS
 *  returns the account number
 *************************************************************************/
unsigned short Account::GetAccNumber() const
{
	return accountNum;
}

/**************************************************************************
 * Method GetAccDate: Class Account
 *_________________________________________________________________________
 *	This method gets and returns the account date..
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 *  returns the account date
 *************************************************************************/
Date Account::GetAccDate() const
{
	return date;
}

/**************************************************************************
 * Method GetAccBalance: Class Account
 *_________________________________________________________________________
 *	This method gets and returns the account balance amount..
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 *  returns the account balance
 *************************************************************************/
float Account::GetAccBalance() const
{
	return balance;
}

/**************************************************************************
 * Method GetAccType: Class Account
 *_________________________________________________________________________
 *	This method gets and returns the account type.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 *  returns the account date
 *************************************************************************/
string Account::GetAccType() const
{
	return accountType;
}

/**************************************************************************
 * Method OutputAccount: Class Account
 *_________________________________________________________________________
 *	This method receives the outfile variable and an amount and outputs
 *	all the information for a single account to the output file.
 *	Returns -> string
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	outfile 	  : the output file variable
 * 	currentAmount : the current amount of money used for a transaction
 * POST-CONDITIONS
 *  Returns a string that has a single account
 *************************************************************************/
string Account::OutputAccount(float currentAmount) const
{
	ostringstream accLine;

	accLine << left;
	accLine << setw(12) << GetAccDate().DisplayDate() << setw(8) << GetAccNumber()
			<< setw(23) << GetAccName() 			  << '$'	 << right;
	accLine << fixed 	<< setprecision(2) << showpoint;
	accLine << setw(9)  << currentAmount   << setw(4) << '$'	 << setw(12)
			<< GetAccBalance();

	return accLine.str();
}
