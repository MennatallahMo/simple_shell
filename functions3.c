#include "shell.h"

/**
 * env - prints the environment
 * @command: the command
 */
void env(char **command)
{
	int k = 0;
	(void)command;

	for (; environ[k] != NULL; k++)
	{
		_puts(environ[k]);
		_puts("\n");
	}
}

/**
 * exit_shell - exit out of shell
 * @data: the data to be used
 */
void exit_shell(data_t *data)
{
	int j = 0;
	int argument;

	while (data->command[j] != NULL)
		j++;

	if (j == 1)
	{
		free(data->command);
		free(data->lineptr);
		exit(data->status);
	}
	else if (j == 2)
	{
		argument = _atoi(data->command[1]);
		if (argument == -1)
		{
			_puts_e(data->program_name);
			_puts_e(": 1: exit: Illegal number: ");
			_puts_e(data->command[1]);
			_puts_e("\n");
			data->status = 2;
		}
		else
		{
			free(data->lineptr);
			free(data->command);
			exit(argument);
		}
	}
}


/**
 * _strlen - returns the length of string
 * @s: the string
 * Return: the length
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
/**
 * _strcpy - copies the str from source to dest
 * @src: the source
 * @dest: the destination
 */
void _strcpy(char *src, char *dest)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}
