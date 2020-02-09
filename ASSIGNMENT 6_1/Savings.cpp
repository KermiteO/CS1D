/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#include "Savings.h"

/**************************************************************************
 * Constructor Savings() : Class Savings
 *_________________________________________________________________________
 *	This is the default Savings constructor, initializes savingsInterest
 *	to .10.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Initializes the interest for savings to .10.
 *************************************************************************/
Savings::Savings()
{
	savingsInterest  = .10;
}

/**************************************************************************
 * Constructor ~Savings() : Class Savings
 *_________________________________________________________________________
 *	This is the non-default Savings constructor, and will set all the
 *	attributes of a Checking account to specific variables by calling
 *	the constructor for the base class, and initializing savingsInterest
 *	to a specific variable.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Will create a Savings account
 *************************************************************************/
Savings::Savings(string 		accName,
		         unsigned short accNum,
		         Date 		    accDate,
		         float 		    accBalance,
		         string		    accType,
		         float          marketInterest)
				 :Account(accName, accNum, accDate, accBalance, accType)
{
	savingsInterest  = marketInterest;
}

/**************************************************************************
 * Destructor ~Savings() : Class Savings
 *_________________________________________________________________________
 *	This is the default Savings Destructor. Does nothing special.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	none
 *************************************************************************/
Savings::~Savings() {}

/**************************************************************************
 * Method WithdrawAccount : Class Savings
 *_________________________________________________________________________
 *	This method withdraws a certain amount of money from a Savings account,
 *	and it will first update the interest to the balance by passing in the
 *	current balance and the currentDate. It will then withdraw an amount
 *	from the balance and set that new withdrawn balance only if the withdraw
 *	amount is less than the current balance. At that point, it will take the
 *	balance and set the balance.
 *	Returns -> boolean
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *  outfile		: the output file variable
 *	withdrawAmt : the amount to withdraw
 *	currentDate : the updated new date of the account made a transaction
 * POST-CONDITIONS
 * 	returns a boolean of whether the withdraw was successful or not.
 *************************************************************************/
bool Savings::WithdrawAccount(ofstream &outfile,
							  float    withdrawAmt,
							  Date     currentDate)
{
	bool     withdrawSuccess;
	float 	 currentBalance;

	withdrawSuccess = false;

	UpdateAccount(GetAccBalance(), currentDate);

	currentBalance = Account::GetAccBalance();

	if(currentBalance > withdrawAmt)
	{
		withdrawSuccess = true;

		currentBalance -= withdrawAmt;

		Account::SetAccount(currentBalance);
	}
	else
	{
		outfile << "\n*** ERROR - CAN'T WITHDRAW OVER $0.00 ***\n\n";
	}

	return withdrawSuccess;
}

/**************************************************************************
 * Method UpdateAccount : Class Savings
 *_________________________________________________________________________
 *	This method updates an accounts balance by checking to see how much
 *	time has passed and then adding the the savingsInterest.
 *	It then sets the new balance and then updates the current date of the
 *	account to the new date.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	newBalance  : the new balance amount
 *	newDate 	: the current date of the transaction
 * POST-CONDITIONS
 * 	Adds interest to balance and resets the date and new balance of an
 * 	account.
 *************************************************************************/
void Savings::UpdateAccount(float newBalance,
				 	 	   	Date  newDate)
{
	Date 		   lastDate;
	unsigned short monthsPass;

	lastDate = Account::GetAccDate();

	if(newDate.GetMonth() - lastDate.GetMonth() == 1)
	{
		newBalance = newBalance + newBalance*savingsInterest;
	}
	else if(newDate.GetMonth() - lastDate.GetMonth() > 1)
	{
		monthsPass = newDate.GetMonth() - lastDate.GetMonth();

		for(int count = 1; count <= monthsPass; count++)
		{
			newBalance = newBalance + newBalance*savingsInterest;
		}
	}

	Account::SetAccount(newBalance);

	Account::SetAccount(newDate);
}
