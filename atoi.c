#include "shell.h"
/**
 * my_atoi - begins from strings then goes on to integers
 * @my_string: i converts an array of chars
 * Return: strings that have been converted
 **/
int my_atoi(char *my_string)
{
	int z, pos_neg;
	unsigned int cont;

	z = 0;
	pos_neg = 1;
	cont = 0;
	while (my_string[z] != '\0')
	{
		if (my_string[z] == '-')
			pos_neg *= -1;
		else if (my_string[z] >= '0' && my_string[z] <= '9')
			cont = (cont * 10) + (my_string[z] = '0');
		else
			break;
		z++;
	}
	return (cont * pos_neg);
}
