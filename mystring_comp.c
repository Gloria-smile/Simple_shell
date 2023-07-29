#include "shell.h"
/**
 * my_strcmp - makes a comparison between two strings.
 * @string1: first compared string
 * @string2: second compared string
 * Return: 0 when result of comparison is even
 * a - value if @string1 < @string2,
 * or a + value if @string1 > @string2.
 */
int my_strcmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string2 != '\0' && *string1 == *string2)
	{
		string1++;
		string2++;
	}
	return ((int) (*string1) - (*string2));
}
