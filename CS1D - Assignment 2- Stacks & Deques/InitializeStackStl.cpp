#include "Header.h"

void InitializeStackStl(stack<string> &stack1,
						stack<double> &stack2)
{
	for(int i = 0; i < TOT_STRINGS; i++)
	{
		stack1.push(NAMES[i]);
	}
	for(int j = 0; j < TOT_NUMS; j++)
	{
		stack2.push(DOUBLES[j]);
	}
}
