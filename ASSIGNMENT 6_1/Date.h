/**************************************************************************
 * AUTHOR		 : Kermite
 * Assignment #6 : Saddleback Bank - OOP
 * CLASS		 : CS1B
 * SECTION		 : TTh 0800
 * DUE DATE		 : 5/12/15
 *************************************************************************/
#ifndef ASSIGNMENT_6_DATE_H_
#define ASSIGNMENT_6_DATE_H_

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
using namespace std;

// Global Constants go here
const int DECEMBER = 11;
const int FIRST_YEAR = 1900;

class Date
{
	public:
		/*******************************
		 ** CONSTRUCTOR & DESTRUCTORS **
		 *******************************/
		Date();

		//uses private utility methods
		Date(unsigned short dateMonth,
			 unsigned short dateDay,
			 unsigned short dateYear);
		~Date();

		/*****************
		 **  MUTATORS	**
		 *****************/
		//uses private utility methods
		void SetDate(unsigned short dateMonth,
					 unsigned short dateDay,
					 unsigned short dateYear);


		/*****************
		 **  ACCESSORS	**
		 *****************/
		void GetDate(unsigned short &dateMonth,
					 unsigned short &dateDay,
					 unsigned short &dateYear) const;

		unsigned short GetYear() const;
		unsigned short GetMonth() const;
		unsigned short GetDay() const;

		string DisplayDate() const;

	private:
		/*******************************
		 ** 	UTILITIES METHODS     **
		 *******************************/
		unsigned short GetDaysInMonth(unsigned short dateMonth,
									  unsigned short dateYear) const;

		bool IsLeapYear(unsigned short dateYear) const;

		/*******************************
		 ** 	VALIDATE METHODS	  **
		 *******************************/
		bool ValidateMonth(unsigned short dateMonth) const;

		bool ValidateDay(unsigned short dateMonth,
						 unsigned short dateDay,
						 unsigned short dateYear) const;

		bool ValidateYear(unsigned short dateYear) const;

		bool ValidateDate(unsigned short &dateMonth,
						  unsigned short &dateDay,
						  unsigned short &dateYear) const;

		/*******************************
		 **    	   ATTRIBUTES	 	  **
		 *******************************/
		unsigned short month;
		unsigned short day;
		unsigned short year;
};

/***********************************************************************
 * Date Class
 *   This class represents a Date object
 *   It manages 2 attributes: The month, day, and year.
 ***********************************************************************/

/********************************
 ** CONSTRUCTORS & DESTRUCTORS **
 ********************************/

/***********************************************************************
 ** Date();
 **   Default Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** Date();
 **   Constructor; Initializes class attributes to the specified values
 **   Parameter: dateMonth, dateDay, dateYear
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~Date();
 **   Destructor; Does not perform any specific function
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***************
 ** MUTATORS  **
 ***************/

/***********************************************************************
 ** SetDate
 **
 **   Mutator; This function sets the attributes of Date to specific
 **   		   values.
 **---------------------------------------------------------------------
 **   Parameter: dateMonth, dateDay, dateYear
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/****************
 ** ACCESSORS  **
 ****************/

/***********************************************************************
 ** GetDate
 **
 **   Accessor; This gets the attributes of the Date object (month, day,
 **   			& year)
 **---------------------------------------------------------------------
 **   Parameter: dateMonth, dateDay, dateYear
 **---------------------------------------------------------------------
 **   Returns: all three by reference
 ***********************************************************************/

/***********************************************************************
 ** GetYear
 **
 **   Accessor; This returns the year of the Date
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the year of the Date
 ***********************************************************************/

/***********************************************************************
 ** GetMonth
 **
 **   Accessor; This returns the month of the Date
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the Dates month
 ***********************************************************************/

/***********************************************************************
 ** GetDay
 **
 **   Accessor; This returns the day of the Date
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the Dates day
 ***********************************************************************/

/***********************************************************************
 ** DisplayDate
 **
 **   Accessor; This method returns the date as a string
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string containing the date
 ***********************************************************************/

/***********************************************************************
 ** GetDaysInMonths
 **
 **   Accessor; This method returns an unsigned short indicating the
 **   			specific number of days in a given month
 **
 **---------------------------------------------------------------------
 **   Parameter: dateMonth & dateYear
 **---------------------------------------------------------------------
 **   Returns: an unsigned short of the # of days in a given month
 ***********************************************************************/

/***********************************************************************
 ** IsLeapYear
 **
 **   Accessor; This method returns a bool indicating whether or not the
 **   			current year is indeed a leap year or not.
 **---------------------------------------------------------------------
 **   Parameter: dateYear
 **---------------------------------------------------------------------
 **   Returns: a boolean
 ***********************************************************************/

/***********************************************************************
 ** ValidateMonth
 **
 **   Accessor; This method returns a bool indicating whether or not the
 **   			current month is valid or not.
 **---------------------------------------------------------------------
 **   Parameter: dateMonth
 **---------------------------------------------------------------------
 **   Returns: a boolean
 ***********************************************************************/

/***********************************************************************
 ** ValidateDay
 **
 **   Accessor; This method returns a bool indicating whether or not the
 **   			current day is valid or not.
 **---------------------------------------------------------------------
 **   Parameter: dateDay
 **---------------------------------------------------------------------
 **   Returns: a boolean
 ***********************************************************************/

/***********************************************************************
 ** ValidateYear
 **
 **   Accessor; This method returns a bool indicating whether or not the
 **   			current year is valid or not.
 **---------------------------------------------------------------------
 **   Parameter: dateYear
 **---------------------------------------------------------------------
 **   Returns: a boolean
 ***********************************************************************/

/***********************************************************************
 ** ValidateDate
 **
 **   Accessor; This method returns a bool indicating whether or not the
 **   			current date is valid or not
 **---------------------------------------------------------------------
 **   Parameter: dateMonth, dateDay, & dateYear
 **---------------------------------------------------------------------
 **   Returns: a boolean & all three parameters by reference
 ***********************************************************************/


#endif /* ASSIGNMENT_6_DATE_H_ */
