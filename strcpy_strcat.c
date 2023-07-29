#include "shell.h"
/**
 * my_strcpy - copy of string
 * @to_dest: the destination it goes
 * @from_scr: it's source
 *
 * Return: a pointer to destination
 */
char *my_strcpy(char *to_dest, char *from_scr)
{
	int my_counter = 0;

	if (to_dest == from_scr || from_scr == 0)
		return (to_dest);
	while (from_scr[my_counter])
	{
		to_dest[my_counter] = from_scr[my_counter];
		my_counter++;
	}
	to_dest[my_counter] = 0;
	return (to_dest);
}
#include "shell.h"
/**
 * my_strcat - the function that joins two strings
 * @str1: first string used 
 * @str2: second string used
 * Return: a pointer to variable
 */
char *my_strcat(const char *str1, const char *str2)
{
	size_t strlength1 = strlen(str1);
	size_t strlength2 = strlen(str2);
	char *container = malloc(strlength1 + strlength2 + 1);

	if (container == NULL)
	{
		return (NULL);
	}
	strcpy(container, str1);
	strcpy(container + strlength1, str2);
		return (container);
}
