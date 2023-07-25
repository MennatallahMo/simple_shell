#include "shell.h"

/**
 * _strcmp - compares btw two strings
 * @s1: the first string
 * @s2: the second string
 * Return: differnce betwn 2 strings
 */
int _strcmp(char *s1, char *s2)
{
	int k = 0;

	while (s1[k] != '\0')
	{
		if (s1[k] != s2[k])
			break;
		k++;
	}
	return (s1[k] - s2[k]);
}

/**
 * _strcspn - measures the length of substring
 * @s1: first string
 * @s2: seconed string
 * Return: length of substring used
 */
int _strcspn(char *s1, char *s2)
{
	int len_sub = 0, j = 0;

	for (; s1[j] != '\0'; j++)
	{
		if (_strchr(s2, s1[j]) != NULL)
			break;
		len_sub++;
	}
	return (len_sub);
}

/**
 * _atoi -  converts string to an integer
 * @string: string
 * Return: returns the integer value of the string
 */
int _atoi(char *string)
{
	unsigned int result = 0;

	while (*string)
	{
		if (*string == '-' || ((*string > '9' || *string < '0') && *string != '\0'))
			return (-1);
		else if (*string <= '9'  && *string >= '0')
		{
			result *= 10;
			result += (*string - '0');
		}
		else if (result > 0)
			break;
		string++;
	}
	return (result);
}

/**
 * path_checker - checks for path
 * @cmd: command
 * Return: the path
 */
char *path_checker(char *cmd)
{
	char **array = NULL;
	char *tmpa, *tmpb, *copy;
	char *path_env = _getenv("PATH");
	int j = 0;

	if (path_env == NULL || _strlen(path_env) == 0)
		return (NULL);
	copy = malloc(sizeof(*copy) * (_strlen(path_env) + 1));
	_strcpy(path_env, copy);
	array = splitter(copy, ":");
	for (; array[j] != NULL; j++)
	{
		tmpb = _strcat(array[j], "/");
		tmpa = _strcat(tmpb, cmd);
		if (access(tmpa, F_OK) == 0)
		{
			free(tmpb);
			free(array);
			free(copy);
			return (tmpa);
		}
		free(tmpa);
		free(tmpb);
	}
	free(copy);
	free(array);
	return (NULL);
}
