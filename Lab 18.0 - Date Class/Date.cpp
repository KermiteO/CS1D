/**********************************************************************
 * AUTHOR(S)	: Kermite & Miss Lame
 * Lab #18		: Date Class
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 4/28/15
 *********************************************************************/

#include "Date.h"

/**************************************************************************
 * Constructor Date() : Class Date
 *_________________________________________________________________________
 *	This is the default Date constructor, initializes all the attributes
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Initializes the data items for a Date object
 *************************************************************************/
Date::Date()
{
	month = 0;
	day   = 1;
	year  = 1900;
}

/**************************************************************************
 * Non-Default Constructor Date() : Class Date
 *_________________________________________________________________________
 *	This is the non default Date constructor, initializes all the attributes
 *	to their values in current time.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	dateMonth : a specific month value for the date
 * 	dateDay   : a specific day value for the date
 * 	dateYear  : a specific year value for the date
 * POST-CONDITIONS
 * 	Initializes the date attributes to current time
 *************************************************************************/
Date::Date(unsigned short dateMonth,
		   unsigned short dateDay,
		   unsigned short dateYear)
{
	time_t now;
	tm	   *currentTime;

	now = time(NULL);
	currentTime = localtime(&now);

	dateYear  = 1900 + currentTime->tm_year;
	dateMonth = currentTime->tm_mon + 1;
	dateDay   = currentTime->tm_mday;

	SetDate(dateMonth, dateDay, dateYear);
}

/**************************************************************************
 * Method SetDate : Class Date
 *_________________________________________________________________________
 *	This initializes the attributes to the three values passed in
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	dateMonth : a specific month value for the date
 * 	dateDay   : a specific day value for the date
 * 	dateYear  : a specific year value for the date
 * POST-CONDITIONS
 * 	Initializes the attributes to three values
 *************************************************************************/
void Date::SetDate(unsigned short dateMonth,
				   unsigned short dateDay,
				   unsigned short dateYear)
{
	month = dateMonth;
	day   = dateDay;
	year  = dateYear;
}

bool Date::CheckDate(unsigned short dateMonth,
					 unsigned short dateDay,
					 unsigned short dateYear) const
{
	if(ValidateDate(dateMonth,dateDay,dateYear))
	{
		cout << "\nYour date entered is valid!\n";
	}
	else
	{
		cout << "\nYour date entered is not valid!\n";
	}


	return ValidateDate(dateMonth,dateDay,dateYear);
}
/**************************************************************************
 * Method GetDate : Class Date
 *_________________________________________________________________________
 *	This sets the three values passed in to their correspoding attributes
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	dateMonth : a specific month value for the date
 * 	dateDay   : a specific day value for the date
 * 	dateYear  : a specific year value for the date
 * POST-CONDITIONS
 * 	Sets the three variables to corresponding attributes
 *************************************************************************/
void Date::GetDate(unsigned short &dateMonth,
				   unsigned short &dateDay,
				   unsigned short &dateYear) const
{
	dateMonth = month;
	dateDay   = day;
	dateYear  = year;
}

/**************************************************************************
 * Method GetYear : Class Date
 *_________________________________________________________________________
 *	This returns the year attributes
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Returns the year attribute
 *************************************************************************/
unsigned short Date::GetYear() const
{
	return year;
}

/**************************************************************************
 * Method GetMonth : Class Date
 *_________________________________________________________________________
 *	This returns the month attributes
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Returns the month attribute
 *************************************************************************/
unsigned short Date::GetMonth() const
{
	return month;
}

/**************************************************************************
 * Method GetDay : Class Date
 *_________________________________________________________________________
 *	This returns the day attributes
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Returns the day attribute
 *************************************************************************/
unsigned short Date::GetDay() const
{
	return day;
}

/**************************************************************************
 * Method DisplayDate : Class Date
 *_________________________________________________________________________
 *	This converts the three attributes to strings and then stores &
 *	concatenates all of them into a string and returns that string
 *	them into a
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Returns the full date as a string
 *************************************************************************/
string Date::DisplayDate() const
{
	string		   monthString;
	string		   dayString;
	string		   yearString;
	string		   dateDisplay;
	ostringstream  convertMonth;
	ostringstream  convertDay;
	ostringstream  convertYear;

	convertMonth << month;
	convertDay   << day;
	convertYear  << year;

	monthString = convertMonth.str();
	dayString   = convertDay.str();
	yearString = convertYear.str();

	dateDisplay = monthString + "/" + dayString + "/" + yearString;

	return dateDisplay;
}

/**************************************************************************
 * Deconstructor ~Date() : Class Date
 *_________________________________________________________________________
 *	This is the  deconstructor that terminates the Date class
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Terminates the Date object
 *************************************************************************/
Date::~Date() {}

/**************************************************************************
 * Method GetDaysInMonth : Class Date
 *_________________________________________________________________________
 *	This calculates the number of days within a specific month and stores
 *	that number into an integer variable and returns it
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	dateMonth : a specific month value for the date
 * 	dateYear  : a specific year value for the date
 * POST-CONDITIONS
 * 	Returns the # of days in a month
 *************************************************************************/
unsigned short Date::GetDaysInMonth(unsigned short dateMonth,
							        unsigned short dateYear) const
{
	int daysInMonth;

	if(dateMonth == 0 || dateMonth == 2 || dateMonth == 4
	|| dateMonth == 6 || dateMonth == 7 || dateMonth == 9
	|| dateMonth == 11)
	{
		daysInMonth = 31;
	}
	else if(dateMonth == 1)
	{
		if(IsLeapYear(dateYear))
		{
			daysInMonth = 29;
		}
		else
		{
			daysInMonth = 28;
		}
	}
	else
	{
		daysInMonth = 30;
	}

	return daysInMonth;
}

/**************************************************************************
 * Method IsLeapYear : Class Date
 *_________________________________________________________________________
 *	This checks if the year is a leap year or not
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	 dateYear  : The year being checked
 * POST-CONDITIONS
 * 	returns a boolean condition that checks if it's a leap year or not
 *************************************************************************/
bool Date::IsLeapYear(unsigned short dateYear) const
{
	return ((dateYear % 4 == 0 && dateYear % 400 == 0) ||
			(dateYear % 4 == 0 && dateYear % 100 != 0));
}

/**************************************************************************
 * Method ValidateMonth : Class Date
 *_________________________________________________________________________
 *	This checks if the month is valid or not
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	 dateMonth  : The month being checked
 * POST-CONDITIONS
 * 	returns a boolean condition that checks if it's a valid month or not
 *************************************************************************/
bool Date::ValidateMonth(unsigned short dateMonth) const
{
	return(dateMonth <= DECEMBER);
}

/**************************************************************************
 * Method ValidateDay : Class Date
 *_________________________________________________________________________
 *	This checks if the day is valid or not
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	dateMonth : a specific month value for the date
 * 	dateDay   : a specific day value for the date
 * 	dateYear  : a specific year value for the date
 * POST-CONDITIONS
 * 	returns a boolean condition that checks if it's a valid day or not
 *************************************************************************/
bool Date::ValidateDay(unsigned short dateMonth,
					   unsigned short dateDay,
					   unsigned short dateYear) const
{
	return(dateDay <= GetDaysInMonth(dateMonth, dateYear));
}

/**************************************************************************
 * Method ValidateYear : Class Date
 *_________________________________________________________________________
 *	This checks if the year is valid or not
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	 dateYear  : The year being checked
 * POST-CONDITIONS
 * 	returns a boolean condition that checks if it's a valid year or not
 *************************************************************************/
bool Date::ValidateYear(unsigned short dateYear) const
{
	return(dateYear >= FIRST_YEAR);
}

/**************************************************************************
 * Method ValidateDate : Class Date
 *_________________________________________________________________________
 *	This checks if the date is valid period
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	dateMonth : a specific month value for the date
 * 	dateDay   : a specific day value for the date
 * 	dateYear  : a specific year value for the date
 * POST-CONDITIONS
 * 	returns a boolean condition that checks if it's a valid year or not
 *************************************************************************/
bool Date::ValidateDate(unsigned short &dateMonth,
						unsigned short &dateDay,
						unsigned short &dateYear) const
{
	bool validDate;
	bool dateBeforeCurrent;

	dateBeforeCurrent = false;

	validDate = ValidateMonth(dateMonth)
			 && ValidateDay(dateMonth,dateDay,dateYear)
			 && ValidateYear(dateYear);

	if((dateMonth >= month && dateDay >= day && dateYear < year)
	 || (dateMonth <= month && dateDay >= day && dateYear < year)
	 || (dateMonth <= month && dateDay <= day && dateYear == year))
	{
		dateBeforeCurrent = true;
	}

	return(validDate && dateBeforeCurrent);
}
