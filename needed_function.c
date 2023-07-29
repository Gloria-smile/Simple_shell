#include "shell.h"
/**
 * my_dubler - the integer separates the string in half, like th efork
 * @str:represents the string to be devided in half
 * Return: pointer to my_dubler string
 */
char *my_dubler(char *str)
{
	int mystr_length = 0;
	char *my_dub;

	if (str == NULL)
		return (NULL);
	while (*str++)
		mystr_length++;
	my_dub = malloc(sizeof(char) * (mystr_length + 1));
	if (!my_dub)
		return (NULL);
	for (mystr_length++; mystr_length--;)
		my_dub[mystr_length] = *--str;
	return (my_dub);
}

#include "shell.h"
/**
 * my_strlen - counts the number of charaters in the string
 * @str: represents the string to be checked
 * Return: the length of the string
 */
int my_strlen(char *str)
{
	int my_counter = 0;

	if (!str)
		return (0);
	while (*str++)
		my_counter++;
	return (my_counter);
}
