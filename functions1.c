#include "shell.h"

/**
 * ctrlc - prints the prompt after ctrl_C
 * @sig: the signal no
 * Return: void
 */
void ctrlc(int sig)
{
	if (sig == SIGINT)
		_puts("\nshell$");
}

/**
 * splitter - split the input and put it to array
 * @str: the input string
 * @d: the delimeter
 * Return: an array of tokens
 */
char **splitter(char *str, char *d)
{
	char **argv = NULL, *p = NULL, *token = NULL;
	int count = 0;

	token = _strtok(str, d, &p);

	while (token != NULL)
	{
		argv = _realloc(argv, sizeof(*argv) * count, sizeof(*argv) * (count + 1));
		argv[count] = token;
		token = _strtok(NULL, d, &p);
		count++;
	}
	argv = _realloc(argv, sizeof(*argv) * count, sizeof(*argv) * (count + 1));
	argv[count] = NULL;

	return (argv);
}
/**
 * _strtok - toknize a string
 * @s: the string
 * @d: the delimeter
 * @p: a pointer
 * Return: the next available token
 */
char *_strtok(char *s, char *d, char **p)
{
	char *ptr_f;

	if (s == NULL)
		s = *p;

	if (*s == '\0')
	{
		*p = s;
		return (NULL);
	}
	s += _strspn(s, d);
	if (*s == '\0')
	{
		*p = s;
		return (NULL);
	}
	ptr_f = s + _strcspn(s, d);
	if (*ptr_f == '\0')
	{
		*p = ptr_f;
		return (s);
	}
	*ptr_f = '\0';
	*p = ptr_f + 1;
	return (s);
}
/**
 * cmd_parser - checks type of the command
 *
 * @data: the structure of data
 * @cmd: the command I want to be parsed
 */

void cmd_parser(char *cmd, data_t *data)
{
	int j = 0;
	char *path_env = NULL;
	char *builtin_cmd[] = {"exit", "env", NULL};

	for (; builtin_cmd[j] != NULL ; j++)
	{
		if (_strcmp(cmd, builtin_cmd[j]) == 0)
			execute_builtin_cmd(data);
	}

	for (; cmd[j] != '\0'; j++)
	{
		if (cmd[j] == '/')
		{
			execute_ex_cmd(data);
			return;
		}
	}

	path_env = path_checker(cmd);
	if (path_env != NULL)

	{
		free(path_env);
		execute_path_cmd(data);
		return;
	}
	invalid_cmd(data);
}

/**
 * _realloc - resize a memory block that has already been allocated
 * @p: points to the memory block that is being reallocated
 * @prev: stores previous size of pointer
 * @current: stores current size of pointer
 *
 * Return: address of current memory block
 */
void *_realloc(void *p, unsigned int prev, unsigned int current)
{
	void *temp;
	unsigned int j = 0;

	if (p == NULL)
	{
		temp = malloc(current);
		return (temp);
	}
	else if (current == prev)
		return (p);
	else if (p != NULL && current == 0)
	{
		free(p);
		return (NULL);
	}
	else
	{
		temp = malloc(current);
		if (temp != NULL)
		{
			for (; j < min(prev, current); j++)
				*((char *)temp + j) = *((char *)p + j);
			free(p);
			return (temp);
		}
		else
			return (NULL);

	}
}
