// 
// 
// 

#include "InputParses.h"

boolean match(int value, int* comparators, int size)
{
	for (int i = 0; i < size ; i++)
	{
		if (value == comparators[i])
			return 1;
	}
	return 0;
}

