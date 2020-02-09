/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/

#include "Header.h"

/***************************************************************************
 * Assignment 6 - Saddleback Bank - OOP
 *_____________________________________________________________________
 * This program is meant to act as a banking program. It will basically
 * use information from two input files to create a list of accounts, and
 * perform different transactions on each account using different concepts
 * of polymorphism, overloading, inheritance, and different classes and
 * derived classes. First, the program will open the input file that has
 * all the accounts to be processed, and then it will create an individual
 * account based on the type and it will add each account to a doubly linked
 * list and output all those accounts to the output file. Then, the program
 * will open the 2nd input file that has all the transactions. It will
 * process the transactions one line at a time (i.e. one transaction at a
 * time) and will call methods to either deposite, withdraw, or transfer an
 * amount to that one account. If the transaction was successful, the program
 * will then call a method that will output the account and its transaction
 * to the output file. The program will continue to do this until the end
 * of the transactions input file is reached.
 *_____________________________________________________________________
 * INPUT:
 *		infile		   : the first input file that has all the accounts
 *		infile2		   : the second input file that contains all transactions
 * OUTPUT:
 *		myBank		   : the list of accounts
 *		transacAccount : a single account that made a transaction
 ***************************************************************************/
int main()
{
	//Constant Declarations go here
	const string WELCOME = "***********************************\n"
						   "* WELCOME TO THE SADDLEBACK BANK! *\n"
						   "***********************************\n";

	//Variable Declarations go here
	Account		  *theAccount;         // PROC&OUT    - represents general object
	Account		  *transacAccount;     // PROC&OUT    - acc. after transaction
	Checking	  *newCheckAcc;        // PROC&OUT    - new Checking account
	Savings		  *newSavingAcc;       // PROC&OUT    - new Savings account
	MoneyMarket   *newMarketAcc;       // PROC&OUT    - new MM account
	BankList 	   myBank;             // PROC        - accesses BankList methods
	ifstream	   infile;             // PROC        - accounts input file var.
	ifstream 	   infile2;            // PROC        - transacs. input file var.
	ofstream	   outfile;            // PROC        - output file variable
	unsigned short dateMonth;          // IN&PROC     - 1st month of opening date
	unsigned short dateYear;           // IN&PROC     - 1st year of opening date
	unsigned short dateDay;            // IN&PROC     - 1st day of opening date
	unsigned short currentMonth;       // IN&PROC     - updated month of transac.
	unsigned short currentDay;         // IN&PROC     - updated day of transac.
	unsigned short currentYear;        // IN&PROC     - updated year of transac.
	unsigned short currentAccNum;      // IN&PROC     - current acc. # of transac.
	unsigned short fromAccNum;         // IN&PROC&OUT - acc.# making the transfer
	unsigned short newAccNum;          // IN&PROC     - acc.# receiving the transfer
	float		   currentAmount;      // IN&PROC&OUT - curr. amount for transac.
	float		   newBal;             // IN&PROC     - intitial balance amount
	Date		   newDate;            // IN&PROC     - intial opening date
	string		   currentTransac;     // IN&PROC&OUT - current transaction in list
	string		   newAccType;         // IN&PROC     - the account type
	string		   newName;            // IN&PROC     - name of person w/ account
	bool		   transactionSuccess; // PROC        - condition that varifies
									   //				if transac. was a success

	// IN&PROC - a specific date
	Date currentDate(currentMonth, currentDay, currentYear);

	PrintHeaderOstream(cout, "Saddleback Bank - OOP", 'A', "6", "Kermite");

/*****************************************************************************
 * INPUT - Will open an input file that has all the accounts and will read
 * 		   in information for 1 specific account, store those in variables, &
 * 		   will create a specific account object depending on what the account
 * 		   type is. It will then call a method that adds that account to a
 * 		   doubly linked list. It will do this for however many accounts are
 * 		   in the input file.
 *****************************************************************************/
	cout << WELCOME;

	// IN/PROC - the command that will create a list of accounts and will open
	//			 the 1st input file and output file
	cout << "\nHit ENTER to open new accounts:\n";
	cin.get();

	infile.open("AccountsInFile.txt");

	outfile.open("OFile.txt");

	// PROC - will loop through list and add specific number of accounts to
	//		  a list by reading from the file one line at a time
	for(int count = 0; count < MAX_ACCS; count++)
	{
		infile >> dateMonth >> dateDay >> dateYear;

		newDate.SetDate(dateMonth, dateDay, dateYear);

		infile >> newAccNum;
		infile >> newAccType;
		infile >> newBal;
		getline(infile, newName);

		// PROC - if the accType read in was one of these 3, then either a
		//		  Checking, Savings, or MoneyMarket (MM) object is created
		//		  and gets assigned to an Account object
		if(newAccType == "Checking")
		{
			newCheckAcc = new Checking(newName, newAccNum, newDate, newBal,
									   newAccType);
			theAccount = newCheckAcc;
		}
		else if(newAccType == "Savings")
		{
			 newSavingAcc = new Savings(newName, newAccNum, newDate,
										newBal, newAccType, 0.1);
			 theAccount = newSavingAcc;
		}
		else if(newAccType == "MM")
		{
			newMarketAcc = new MoneyMarket(newName, newAccNum, newDate,
										   newBal, newAccType, 0.2);
			theAccount = newMarketAcc;
		}//END IF

		myBank.AddAccount(theAccount);
	}//END FOR

	// OUT - the entire list of accounts to the output file
	myBank.OutputLinkList(outfile);

	outfile << endl;

	infile.close();

	//OUT - indicates that all accounts were added to the list & outputed
	//		correctly
	cout << right << setw(18) << ".\n"
		 << setw(18) << ".\n"
		 << setw(19) << ".\n\n";
	cout << left << "All accounts have been opened!\n\n";

/*****************************************************************************
 * PROCESSING & - Will open a second input file that has a list of specific
 * OUTPUT		transactions on the accounts, and will enter a loop that
 * 				reads from the file 1 line at a time. It will take the account
 * 				number found in the 2nd input file and use that to call a
 * 				method that will search the list of existing accounts for that
 * 				specific one and pass it back by reference. Then, depending
 * 				on the transaction read from the file, different methods
 * 				will be called to either deposite, withdraw, or transfer from
 * 				accounts. If the transaction was a success, then a method
 * 				will be called that will display that account to the output
 * 				file.
 *****************************************************************************/

	// IN/PROC - prompts a command that will process all the transactions and
	//			 open the 2nd input file
	cout << "Hit ENTER to perform transactions on accounts:\n";
	cin.get();

	infile2.open("TransactionsInFile.txt");

	// PROC - the lcv in this case is 1 line from the input file
	infile2 >> currentMonth >> currentDay >> currentYear;

	currentDate.SetDate(currentMonth, currentDay, currentYear);

	infile2 >> currentAccNum;
	infile2 >> currentAmount;
	getline(infile2, currentTransac);

	// PROC - will keep looping until the end of the file is reached
	while(infile2)
	{
		// PROC - will call a method in BankList that will search the list
		//		  for a specific account.
		myBank.FindAccount(currentAccNum, transacAccount);

		// PROC - will call 1 of three different transaction methods based on
		//		  the transaction type that was read in
		if(currentTransac ==  " Deposit")
		{
			transactionSuccess = transacAccount->DepositeAccount(currentAmount,
																 currentDate);

		}
		else if(currentTransac == " Withdrawal")
		{
			transactionSuccess = transacAccount->WithdrawAccount(outfile,
																 currentAmount,
															     currentDate);
		}
		else
		{
			infile2 >> fromAccNum;

			transactionSuccess = myBank.TransferAmount(outfile,
													   currentDate,
													   currentAmount,
													   currentAccNum,
													   fromAccNum);
		}//END IF

		// OUT - if the boolean that was returned from the transaction method
		//		 was true, then the account gets displayed to the output file.
		if(transactionSuccess)
		{
			myBank.DisplayTransaction(currentTransac, currentAmount,
									  fromAccNum, transacAccount, outfile);
		}//END IF

		// PROC - reads the next line of the file
		infile2 >> currentMonth >> currentDay >> currentYear;

		currentDate.SetDate(currentMonth, currentDay, currentYear);

		infile2 >> currentAccNum;
		infile2 >> currentAmount;
		getline(infile2, currentTransac);
	}//END WHILE

	infile2.close();

	outfile.close();

	// OUT - indicates that all the accounts were transacted successfully
	cout << right << setw(18) << ".\n"
		 << setw(18) << ".\n"
		 << setw(19) << ".\n\n";
	cout << "All account transactions have been processed!\n\n"
		 << "Thank you for using Saddleback Bank!";

	return 0;
}
