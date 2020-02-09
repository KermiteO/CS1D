/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #2: Stacks and Deques
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<sstream>

using namespace std;

//Constant Declarations go here
const int HEADER = 13;
const int TOT_STRINGS = 6;
const int TOT_NUMS = 8;

//data input
const string NAMES[TOT_STRINGS] = {"Tasha","JoAnn","Alan","Mark","Cathy",
								   "Jane"};
const double DOUBLES[TOT_NUMS]  = {48.4,887.55,88.88,123.123,8.455,983.3,
								   1.2, 354.8};


const string EQ_1 = "(2x - 4) (12x + 6)";
const string EQ_2 = "{2x + 5} (6x + 4)}";
const string EQ_3 = "[(5x - 5) - 4x[6x + 2]]";
const string EQ_4 = "{{8x+5) - 5x[9x+3]})";
const string EQ_5 = "{(8x+5) - 5x[9x+3]})";
const string EQ_6 = "(2x - 4) (12x + 6}";
const string EQ_7 = "(((6x+6) - x[9x+3])))";

string PrintHeader(char   prType,
				   string programmer,
				   int	  prNum,
				   string prName,
				   string prompt);

//will initialize the two STL stacks
void InitializeStackStl(stack<string> &stack1,
						stack<double> &stack2);

//will match the parentheses
bool MatchParentheses(const char EQUATION[],
					  const int  SIZE);

void IsValid(const string EQ,
			 bool  isMatch);


#endif /* HEADER_H_ */
