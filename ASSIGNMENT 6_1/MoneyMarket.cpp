/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#include "MoneyMarket.h"

/**************************************************************************
 * Constructor MoneyMarket() : Class MoneyMarket
 *_________________________________________________________________________
 *	This is the default MoneyMarket constructor, initializes marketInterest
 *	to .20.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Initializes the data items for an MoneyMarket object
 *************************************************************************/
MoneyMarket::MoneyMarket()
{
	marketInterest = .20;
}

/**************************************************************************
 * Constructor ~MoneyMarket() : Class MoneyMarket
 *_________________________________________________________________________
 *	This is the non-default MoneyMarket constructor, and will set all the
 *	attributes of a MoneyMarket account to specific variables by calling
 *	the constructor for the Account class, and set marketInterest to a
 *	specific value.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Will create an MoneyMarket account
 *************************************************************************/
MoneyMarket::MoneyMarket(string 		accName,
						 unsigned short accNum,
						 Date 		    accDate,
						 float 		    accBalance,
						 string		    accType,
						 float          newMarketInterest)
{
	marketInterest = newMarketInterest;

	Account::SetAccount(accName, accNum, accDate, accBalance, accType);
}

/**************************************************************************
 * Destructor ~MoneyMarket() : Class MoneyMarket
 *_________________________________________________________________________
 *	This is the default MoneyMarket Destructor. Does nothing special.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	none
 *************************************************************************/
MoneyMarket::~MoneyMarket() {}

/**************************************************************************
 * Method WithdrawAccount : Class MoneyMarket
 *_________________________________________________________________________
 *	This method withdraws a certain amount of money from a Savings account,
 *	and it will first update the interest to the balance by passing in the
 *	current balance and the currentDate. It will then withdraw an amount
 *	from the balance, penalize that balance by $1.50, and set that new
 *	withdrawn balance only if the withdraw amount is less than the current
 *	balance. At that point, it will take the balance and set the balance.
 *	Returns -> boolean
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *  outfile		: the output file variable
 *	withdrawAmt : the amount to withdraw
 *	currentDate : the updated new date of the account made a transaction
 * POST-CONDITIONS
 * 	returns a boolean of whether the withdraw was successful or not.
 *************************************************************************/
bool MoneyMarket::WithdrawAccount(ofstream &outfile,
								  float    withdrawAmt,
								  Date     currentDate)
{
	bool  withdrawSuccess;
	float currentBalance;

	withdrawSuccess = false;

	UpdateAccount(GetAccBalance(), currentDate);

	currentBalance = Account::GetAccBalance();

	if(currentBalance > withdrawAmt)
	{
		withdrawSuccess = true;

		currentBalance -= withdrawAmt;

		currentBalance -= WITHDRAW_COST;

		Account::SetAccount(currentBalance);
	}
	else
	{
		outfile << "\n*** ERROR - CAN'T WITHDRAW OVER $0.00 ***\n\n";
	}

	return withdrawSuccess;
}

/**************************************************************************
 * Method UpdateAccount : Class Account
 *_________________________________________________________________________
 *	This method updates an accounts balance by checking to see how much
 *	time has passed and then adding the appropriate marketInterest. It
 *	then sets the new balance and then updates the current date of the
 *	account to the new date.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	newBalance  : the new balance amount
 *	newDate 	: the current date of the transaction
 * POST-CONDITIONS
 * 	Adds interest to balance and resets the date of an account.
 *************************************************************************/
void MoneyMarket::UpdateAccount(float newBalance,
				 	 	   		Date  newDate)
{
	Date 		   lastDate;
	unsigned short monthsPass;

	lastDate = Account::GetAccDate();

	if(newDate.GetMonth() - lastDate.GetMonth() == 1)
	{
		newBalance = newBalance + newBalance*marketInterest;
	}
	else if(newDate.GetMonth() - lastDate.GetMonth() > 1)
	{
		monthsPass = newDate.GetMonth() - lastDate.GetMonth();

		for(int count = 1; count <= monthsPass; count++)
		{
			newBalance = newBalance + newBalance*marketInterest;
		}
	}

	Account::SetAccount(newBalance);

	Account::SetAccount(newDate);
}
