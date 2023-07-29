#include "shell.h"
/**
 * my_substr  looks for a word in a sentence
 * @sentence: one of the searched parameter
 * @word: the word being looked for in the parameter
 * Return: pointer to the address the word is found
**/
char *my_substr(char *sentence, char *word)
{
	int my_s;

	for (my_s = 0; sentence[my_s] != '\0'; my_s++)
	{
		if (sentence[my_s] == word[0])
		{
		int my_w;

		for (my_w = 0; word[my_w] != '\0'; my_w++)
		{
			if (sentence[my_s + my_w] != word[my_w])
			{
				break;
			}
		}

			if (word[my_w] == '\0')
			{
				return (&sentence[my_s]);
			}
		}
	}
	return (NULL);
}
