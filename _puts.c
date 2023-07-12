#include "shell.h"


/**
 * _puts - prints a string to stdout
 * @str: printed string
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);
}



/**
 * _puts_e - prints a string
 * @str: printed string to stdout
 */

void _puts_e(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(2, &str[i], 1);
}
