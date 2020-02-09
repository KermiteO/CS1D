/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Template
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 1/20/15
 *********************************************************************/
#include "HeaderFile.h"

//Constant declarations go here
const int PROMPT_COL = 30;
const int PROMPT2_COL = 31;

int main()
{
	//Variable declarations go here
	int age;					  //INPUT 	    - prompt user for an age
	int count;					  //PROCESSING  - counts the kid number
	int parkFee;				  //PROCESSING  - displays park fee
	int totParkFee;				  //CALCULATING - calculates total park fee
	float foodCost;				  //PROCESSING  - displays the food cost
	float totFoodCost;			  //CALCULATING - calculates the total
								  //			  food cost
	float totCost;				  //OUTPUT 		- calculates & outputs the
								  //			  total cost for food and
								  //			  admission
	float avgCost;				  //OUTPUT 		- calculates & outputs the
								  //			  average cost
								  //			  for each individual kid
	string name;				  //INPUT 		- prompts user for a name
	string foodChoice;			  //PROCESSING  - displays the food
								  //			  preference
	string attractionChoice;	  //PROCESSING  - displays the attraction
								  //			  preference
	char vegeValid;				  //INPUT		- prompts user for
								  //			  vegetarian validation
	char cheeseValid;			  //INPUT		- prompts user for whether
								  //			  he/she likes cheese

	//Calls the print header function back to main
	PrintHeader();

	cout << "Welcome to the Theme Park Planner! Please input each kid's "
		 << "information.\n\n";

	//Initializes the total park fee and the total food cost to zero
	totParkFee = 0;
	totFoodCost = 0;

/*************************************************************************
    INPUT/PROCESSING - the loop that prompts the user for a name, an age,
					   validation of whether the user is a vegetarian, &
					   validation of whether the user likes cheese, and
					   displays the attraction and food the given user
					   will require.
**************************************************************************/
	for(count = 1; count <= 10; count++)
	{
		cout << left;
		cout << "Kid #" << count << ":\n";
		cout << setw(PROMPT_COL) << "What is your kid's name?";
		cin  >> name;
		cin.ignore(1000, '\n');
		cout << setw(PROMPT_COL) << "How old is the kid?";
		cin  >> age;
		cin.ignore(1000, '\n');

		//PROCESSING - the manipulators that account for the decimal #'s

		cout << fixed << showpoint << setprecision(2);

		//PROCESSING - displays the given admission fee and attraction
		//			   based on the age entered
		if(age < 5)
		{
			parkFee = 0;
			totParkFee += parkFee;
			attractionChoice = "Ferris Wheel and the Sheep Petting Zoo";
		}
		else if(age >= 5 && age <= 12)
		{
			parkFee = 15;
			totParkFee += parkFee;
			attractionChoice = "Tea Cups and will be playing Laser Tag";
		}
		else if(age > 12)
		{
			parkFee = 20;
			totParkFee += parkFee;
			attractionChoice = "Roller Coaster and the Zip Line";
		}

		//INPUT - prompts the user for validation of whether the user is
		//		  a vegetarian and whether or not he/she likes cheese
		cout << setw(PROMPT_COL) << "Vegetarian (Y/N)?";
		cin.get(vegeValid);
		cin.ignore(1000, '\n');
		cout << setw(PROMPT_COL) << "Does he/she like cheese(Y/N)?";
		cin.get(cheeseValid);
		cin.ignore(1000, '\n');

		//PROCESSING - displays the food choice and accumulates the total
		//			   food cost depending on the two validations entered
		if(vegeValid == 'Y' && cheeseValid == 'Y')
		{
			foodChoice = "Cheese Pizza";
			foodCost = 2.50;
			totFoodCost += foodCost;
		}
		else if(vegeValid == 'Y' && cheeseValid == 'N')
		{
			foodChoice = "Happy Garden meal";
			foodCost = 1.75;
			totFoodCost += foodCost;
		}
		else if(vegeValid == 'N' && cheeseValid == 'N')
		{
			foodChoice = "Hamburger";
			foodCost = 3.25;
			totFoodCost += foodCost;
		}
		else if(vegeValid == 'N' && cheeseValid == 'Y')
		{
			foodChoice = "CheeseBurger";
			foodCost = 3.50;
			totFoodCost += foodCost;
		}
		else
		{
			foodChoice = "Invalid";
		}

		//PROCESSING/OUTPUT - displays the kid and what attraction & food
		//					  he/she will get at the theme park
		cout << endl;
		cout << name << " will be going on the " << attractionChoice
			 << "."  << endl;
		cout << "Pack a " << foodChoice << " for " << name << "!\n\n\n";
	}

	/**********************************************************************
		CALCULATING - calculates the total cost for admission and food,
		 	 	 	  and the average cost for each kid
	**********************************************************************/

	totCost = totParkFee + totFoodCost;
	avgCost = totCost/10.00;

	/**********************************************************************
		//OUTPUT - outputs the total cost and the average cost
	**********************************************************************/
	cout << "\n..." << endl;
	cout << setw(PROMPT2_COL) << "The total cost for the day is:" << "$ "
		 << totCost << endl;
	cout << setw(PROMPT2_COL) << "The average cost per kid is:" << "$  "
		 <<  avgCost;

	return 0;
}
