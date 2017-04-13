#include <string.h>
#include "syntax_check.h"

long syntax_check(const char* str)
{
	long i = 0;

	// Check single-opening brackets
	while (i < strlen(str))
	{
		if (str[i] == '[')
			if (matching_closing_key(i, str) == -1)
				return (-1 * (i + 1));      // Return non-zero based position, negative for single opening brackets

		i++;
	}

	// Check single-closeing brackets
	i = 0;
	while (i < strlen(str))
	{
		if (str[i] == ']')
			if (matching_opening_key(i, str) == -1)
				return (i + 1);             // Return non-zero based position, positive for single closing brackets

		i++;
	}

	return 0;                               // Return zero for no errors found.
}
