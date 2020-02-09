/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#include "BankList.h"

/**************************************************************************
 * Constructor BankList() : Class BankList
 *_________________________________________________________________________
 *	This is the default BankList constructor, initializes head to NULL.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Initializes the data items for an BankList variable
 *************************************************************************/
BankList::BankList()
{
	head = NULL;
	tail = NULL;
}

/**************************************************************************
 * Destructor ~BankList() : Class BankList
 *_________________________________________________________________________
 *	This is the default BankList Destructor, and will clear the entire
 *	list.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	will delete all the nodes in the list until empty.
 *************************************************************************/
BankList::~BankList()
{
	AccountNode *deletePointer;

	while(head != NULL)
	{
		deletePointer = head;
		head = head -> next;

		delete deletePointer;
	}
	tail = head;

	deletePointer = NULL;
}

/**************************************************************************
 * Method AddAccount : Class BankList
 *_________________________________________________________________________
 *	This method receives an account from main by reference and will add
 *	said account to a doubly linked list. Returns -> nothing.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	newAccount : a new account
 * POST-CONDITIONS
 * 	Will add an account to a double link list
 *************************************************************************/
void BankList::AddAccount(Account *&newAccount)
{
	AccountNode   *accountPtr;

	accountPtr = new AccountNode;
	accountPtr -> next = NULL;
	accountPtr -> prev = NULL;

	accountPtr->myAccount = newAccount;

	if(IsEmpty())
	{
		head = accountPtr;
		tail = head;
	}
	else
	{
		accountPtr->next = head;
		head->prev = accountPtr;
		head = accountPtr;
	}
}

/**************************************************************************
 * Method TransferAmount : Class BankList
 *_________________________________________________________________________
 *	This method receives a link to an output file, a date, a transfer amount,
 *	and two account numbers and will use that transfer amount to tranfer
 *	money between two accounts by first using the two account #'s to find
 *	their corresponding accounts and then withdrawing the transferAmt from
 *	the "from account" and depositing the same amount of money into the
 *	"to account". Returns -> boolean.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	outfile	    : the output file variable
 * 	currentDate : the current date the transaction has taken place
 * 	transferAmt : the transfer amount
 * 	toAccNum	: the account number that receives the transfer
 * 	fromAccNum  : the account number that deposites the transfer.
 * POST-CONDITIONS
 * 	Will return a boolean that indicates the transfer was successful.
 *************************************************************************/
bool BankList::TransferAmount(ofstream		 &outfile,
							  Date			 currentDate,
							  float 		 transferAmt,
							  unsigned short toAccNum,
							  unsigned short fromAccNum)
{
	bool 	 transferSuccess;
	Account *fromAccount;
	Account *toAccount;

	transferSuccess = false;

	FindAccount(fromAccNum, fromAccount);

	FindAccount(toAccNum, toAccount);

	if(fromAccount->GetAccBalance() > 0)
	{
		if(fromAccount != toAccount)
		{
			toAccount->DepositeAccount(transferAmt, currentDate);

			fromAccount->WithdrawAccount(outfile, transferAmt, currentDate);

			transferSuccess = true;
		}
		else
		{
			outfile << "\n*** ERROR - CAN'T TRANSFER INTO THE SAME ACCOUNT "
					<< "***\n\n";
		}
	}
	else
	{
		outfile << left << endl;
		outfile << "*** TRANSFER FROM " << fromAccount->GetAccNumber()
				<< " TO "   << toAccount->GetAccNumber() << " NOT ALLOWED! ***\n";
		outfile << "***"    << right    << setw(33)
				<< "DUE TO INSUFFICIENT FUNDS" << setw(11) << "***"
				<< endl << endl;
	}

	return transferSuccess;
}

/**************************************************************************
 * Method OutputLinkList : Class BankList
 *_________________________________________________________________________
 *	This method receives a link to an output file and will output to that
 *	file all the accounts and their corresponding information.
 *	Returns -> nothing
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	outfile	    : the output file variable
 * POST-CONDITIONS
 * 	Will output all the accounts in the link list.
 *************************************************************************/
void BankList::OutputLinkList(ofstream &outfile) const
{
	AccountNode *searchPtr;
	Date		 outputDate;
	string		 fullDate;

	outfile << left;
	outfile << setw(19) 	<< "TRANSACTION"   << setw(12)     << "DATE"
			<< "ACCT # " 	<< setw(23) 	   << " ACCT NAME" << right << setw(11)
			<< "AMOUNT" 	<< setw(16)		   << "BALANCE"    << setw(14)
			<< "FROM ACCT#" << setw(18) 	   << "FROM ACCT BAL\n";

	outfile << left    << setw(19)     << "-----------" << setw(12) << "----------"
			<< setw(8) << "-----"      << setw(23) << "--------------------"
			<< setw(13)<< "----------" << setw(17) << "-------------"
			<< setw(14)<< "----------" << "-------------\n";

	searchPtr = tail;

	while(searchPtr != NULL)
	{
		outfile << left << setw(19);

		if(searchPtr ->myAccount ->GetAccType() == "Checking")
		{
			outfile << "OPEN CHECKING";
		}
		else if(searchPtr->myAccount->GetAccType() == "Savings")
		{
			outfile << "OPEN SAVINGS";
		}
		else
		{
			outfile << "OPEN Money Market";
		}

		outputDate = searchPtr->myAccount->GetAccDate();

		fullDate = outputDate.DisplayDate();

		outfile << setw(12) << fullDate << setw(8);
		outfile << searchPtr->myAccount->GetAccNumber() << setw(23);
		outfile << searchPtr->myAccount->GetAccName() << '$' << right;
		outfile << fixed << setprecision(2) << showpoint;

		outfile << setw(9) << searchPtr->myAccount->GetAccBalance() << setw(4)
				<< "$" << setw(12) << searchPtr->myAccount->GetAccBalance()
				<< endl;

		searchPtr = searchPtr->prev;
	}
}

/*************************************************************************
 * Method IsEmpty: Class FarmList
 *_____________________________________________________________________
 *   Checks to see if the link list is empty. It returns a boolean
 *   condition
 *_____________________________________________________________________
 *  PRE-CONDITIONS:
 *    None
 *  POST-CONDITIONS:
 *    The list is cleared
 *************************************************************************/
bool BankList::IsEmpty() const
{
	return head == NULL;
}

/**************************************************************************
 * Method FindAccount : Class BankList
 *_________________________________________________________________________
 *	This method receives an account number and a pointer of type Account and
 *	will search the link list for the account with the corresponding
 *	account number. Once it finds it, it will assign said account to the
 *	pointer and pass it back by reference. Returns -> Account
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	thisAccNum : an account number to search for
 * 	thisAccount: a pointer of type Account
 * POST-CONDITIONS
 * 	Will return an account by reference.
 *************************************************************************/
void BankList::FindAccount(unsigned short thisAccNum,
						   Account		 *&thisAccount) const
{
	bool 	 	 found;
	AccountNode *srchPtr;

	found = false;

	srchPtr = head;

	while(!found && srchPtr != NULL)
	{
		if(srchPtr->myAccount->GetAccNumber() == thisAccNum)
		{
			found = true;

			thisAccount = srchPtr->myAccount;
		}
		else
		{
			srchPtr=srchPtr->next;
		}
	}
}

/**************************************************************************
 * Method DisplayTransaction : Class BankList
 *_________________________________________________________________________
 *	This method receives a transaction type, an amount, and an account #
 *	from an input file that was processed in main; as well as a pointer
 *	to a transacted account, and an output file variable, and will display
 *	all of that info in a single line to the output file.
 *	 Returns -> nothing.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *  transacType   : the transaction type
 *  currentAmount : the current amount used for the transaction
 *  currentAccNum : the current account number
 *  transacAccount: the account that has performed a transaction
 * 	outfile	      : the output file variable
 * POST-CONDITIONS
 * 	Will display the account and it's transaction.
 *************************************************************************/
void BankList::DisplayTransaction(string 		 transacType,
								  float  		 currentAmount,
								  unsigned short currentAccNum,
								  Account		*&transacAccount,
								  ofstream       &outfile) const
{
	Account  *currentAccount;

	FindAccount(currentAccNum, currentAccount);

	outfile << left << setw(19);

	if(transacType == " Deposit")
	{
		outfile << " Deposit";
	}
	else if(transacType == " Withdrawal")
	{
		outfile << " Withdrawal";
	}
	else if(transacType == " Transfer")
	{
		outfile << " Transfer";
	}

	outfile << transacAccount->OutputAccount(currentAmount);

	if(transacType == " Transfer")
	{
		outfile << right;
		outfile << setw(8) << currentAccount->GetAccNumber() << setw(10) << '$'
				<< setw(13) << currentAccount->GetAccBalance() << endl;
	}
	else
	{
		outfile << endl;
	}
}
