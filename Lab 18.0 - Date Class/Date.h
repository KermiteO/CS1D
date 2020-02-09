/**********************************************************************
 * AUTHOR(S)	: Kermite & Miss Lame
 * Lab #18		: Date Class
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 4/28/15
 *********************************************************************/
#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
using namespace std;

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

		/*******************************
		 ** 		MUTATORS		  **
		 *******************************/
		//uses private utility methods
		void SetDate(unsigned short dateMonth,
					 unsigned short dateDay,
					 unsigned short dateYear);


		/*******************************
		 ** 		ACCESSORS		  **
		 *******************************/
		bool CheckDate(unsigned short dateMonth,
					   unsigned short dateDay,
					   unsigned short dateYear) const;

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

#endif /* DATE_H_ */
