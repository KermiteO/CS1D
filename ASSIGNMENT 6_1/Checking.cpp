/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#include "Checking.h"

/**************************************************************************
 * Constructor Checking() : Class Checking
 *_________________________________________________________________________
 *	This is the default Checking constructor, and does nothing special.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Initializes the data items for an Checking object
 *************************************************************************/
Checking::Checking() {}

/**************************************************************************
 * Constructor ~Checking() : Class Checking
 *_________________________________________________________________________
 *	This is the non-default Checking constructor, and will set all the
 *	attributes of a Checking account to specific variables by calling
 *	the constructor for the base class.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Will create an account
 *************************************************************************/
Checking::Checking(string 		  accName,
			       unsigned short accNum,
			       Date 		  accDate,
			       float 		  accBalance,
			       string		  accType)
				   :Account(accName, accNum, accDate, accBalance, accType) {}

/**************************************************************************
 * Destructor ~Checking() : Class Checking
 *_________________________________________________________________________
 *	This is the default Checking Destructor. Does nothing special.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	none
 *************************************************************************/
Checking::~Checking() {}

/**************************************************************************
 * Method WithdrawAccount : Class Checking
 *_________________________________________________________________________
 *	This method withdraws a certain amount of money from a Checking account,
 *	and it will first get the date and current balance from Account, and
 *	then it will update the interest to the balance by passing in the
 *	current balance and the date. At that point, it will check to see
 *	that the current balance hasn't reached overdraw limit of $-200.00,
 *	and if it hasn't it will withdraw an amount from the account, or
 *	withdraw and penalize the account if it's in the negative. At that point,
 *	it will take the balance and set the balance.
 *	Returns -> boolean
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *  outfile		: the output file variable
 *	withdrawAmt : the amount to withdraw
 *	currentDate : the updated new date of the account made a transaction
 * POST-CONDITIONS
 * 	returns a boolean of whether the withdraw was successful or not.
 *************************************************************************/
bool Checking::WithdrawAccount(ofstream &outfile,
							   float    withdrawAmt,
							   Date  	currentDate)
{
	bool  withdrawSuccess;
	float currentBalance;
	Date  lastDate;

	withdrawSuccess = false;

	lastDate = Account::GetAccDate();

	currentBalance = Account::GetAccBalance();

	UpdateAccount(currentBalance, currentDate);

	if(currentBalance > OVERDRAW_LIMIT)
	{
		withdrawSuccess = true;

		currentBalance -= withdrawAmt;

		if(currentBalance < 0)
		{
			currentBalance -= PENALIZED;
		}

		Account::SetAccount(currentBalance);
	}
	else
	{
		outfile << "\n*** ERROR - CAN'T OVERDRAW PASSED $-200.00 ***\n\n";
	}

	return withdrawSuccess;
}

/**************************************************************************
 * Method UpdateAccount : Class Checking
 *_________________________________________________________________________
 *	This method updates an accounts balance by checking to see how much
 *	time has passed and then penalizing the balance only if the balance
 *	is in the negative. It then sets the new balance and then
 *	updates the current date of the account to the new date.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	newBalance  : the new balance amount
 *	newDate 	: the current date of the transaction
 * POST-CONDITIONS
 * 	Penalizes the balance if it's (-) and resets the date of an account.
 *************************************************************************/
void Checking::UpdateAccount(float newBalance,
					 	 	 Date  newDate)
{
	unsigned short monthsPass;
	Date		   lastDate;

	lastDate = Account::GetAccDate();

	monthsPass = newDate.GetMonth() - lastDate.GetMonth();

	if(newBalance < 0)
	{
		if(monthsPass == 1)
		{
			newBalance -= PENALIZED;
		}
		else
		{
			newBalance -= PENALIZED*monthsPass;
		}
	}
	Account::SetAccount(newBalance);

	Account::SetAccount(newDate);
}
