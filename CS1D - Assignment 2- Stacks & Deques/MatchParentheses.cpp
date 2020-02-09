#include "Header.h"
#include "StackList.h"

bool MatchParentheses(const char EQ[],
					  const int  SIZE)
{
	StackList<char> symbolStack;

	for(int i = 0; i <SIZE; i++)
	{
		if(EQ[i] == '(' || EQ[i] == '[' || EQ[i] == '{')
		{
			symbolStack.PushData(EQ[i]);
		}
		else if(EQ[i] == ')' || EQ[i] == ']' || EQ[i] == '}')
		{
			if(symbolStack.IsEmpty())
			{
				return false;
			}

			if((symbolStack.Top() == '(' && EQ[i] != ')')
			|| (symbolStack.Top() == '[' && EQ[i] != ']')
			|| (symbolStack.Top() == '{' && EQ[i] != '}'))
			{
				return false;
			}

			symbolStack.PopData();
		}
	}

	return (symbolStack.IsEmpty()? true: false);
}
