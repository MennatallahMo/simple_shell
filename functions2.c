#include "shell.h"

/**
 *_strchr - finds place of character in string
 *@string: string to find
 *@character: checked character
 *
 *Return: pointer to char
 */

char *_strchr(char *string, char character)
{
	int k;

	for (k = 0; string[k] != character && string[k] != '\0'; k++)
		;
	if (character == string[k])
		return (string + k);
	else
		return (NULL);
}

/**
 *_strcat - joins two strings together by concatenation
 *@dest: string to be joined to
 *@origin: string want to join
 *
 * Return: new formed string
 */
char *_strcat(char *dest, char *origin)
{
	char *formed_str =  NULL;
	int dest_length = _strlen(dest);
	int origin_length = _strlen(origin);

	formed_str = malloc(sizeof(*formed_str) * (dest_length + origin_length + 1));
	_strcpy(dest, formed_str);
	_strcpy(origin, formed_str + dest_length);
	formed_str[dest_length + origin_length] = '\0';
	return (formed_str);
}

/**
 * _strspn - returns the no, of chars in str1 which consists of str2
 * @s1: first string
 * @s2: seconed string
 * Return: the no. of chars
 */
int _strspn(char *s1, char *s2)
{
	int count_matched = 0;

	while (*s1++)
	{
		if (_strchr(s2, *s1) == NULL)
			break;
		count_matched++;
	}
	return (count_matched);
}
/**
 * check_new_lines - checks new lines and remove it
 * @str: the string to be checked
 */
void check_new_lines(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
			break;
	}
	str[i] = '\0';
}

/**
 * _getenv - gathering env names
 * @en: the environment name
 * Return: the string value of var
 */
char *_getenv(char *en)
{
	char **env, *p, *n;

	for (env = environ; *env != NULL; env++)
	{
		for (p = *env, n = en; *p == *n; p++, n++)
		{
			if (*p == '=')
				break;
		}
		if ((*p == '=') && (*n == '\0'))
			return (p + 1);
	}
	return (NULL);
}
