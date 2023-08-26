#include "monty.h"

/**
 * dn_strlen - program to show string length
 * @s: str
 * Return: length of str
 */
int dn_strlen(char *s)
{
	int elm;

	for (elm = 0; *(s + elm); ++elm)
		;
	return (elm);
}


/**
 * dn_skip - skip whitespaces
 * @s: a str
 *
 * Return: ptr
 */
char *dn_skip(char *s)
{
	if (!s)
		return (NULL);

	while (*s && (*s == ' ' || *s == '\t' || *s == '\v'))
		++s;
	if (*s == '\0' || *s == '\n' || *s == '#')
		return (NULL);
	return (s);
}


/**
 * dn_reach - program that get the first number in a str
 * @s:str
 * Return: a pointer to where the number (and a number is not 4e) is or NULL
 */
char *dn_reach_element(char *s)
{
	char *elm;
	int rea, num, min = 1;

	rea = num = 0;
	if (!s)
		return (NULL);

	while (*s && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			min = -1;
		num++;
		++s;
	}

	if (*s == '\0')
		return (NULL);
	elm = s;
	while (*elm && *elm >= '0' && *elm <= '9')
		elm++;

	if (!(*elm == '\0' || *elm == '\n' || *elm == ' ' || *elm == '\t'))
	return (NULL);

	rea = atoi(s) * min;
	if (rea < 0)
	{
		s[num - 1] = '-';
		return (s - 1);
	}
	return (s);
}

/**
 * dn_strcmp - program that compare 2 strings see strcmp()
 * @s1: str
 * @s2: str
*/
int dn_strcmp(char *s1, char *s2)
{
	int elm;

	elm = 0;
	while (*(s1 + elm) == *(s2 + elm) && *(s1 + elm) != '\0' && *(s2 + elm) != '\0')
		elm++;
	return (*(s1 + elm) - *(s2 + elm));
}



/**
 * dn_strncmp - compare 2 strings see strcmp()
 * @s1: str
 * @s2: opcode
 * @n: length
 * Return: 0 if OK
*/
int dn_strncmp(char *s1, char *s2, int n)
{
	int elm;

	elm = 0;
	while (*(s1 + elm) != '\0' && *(s2 + elm) != '\0' && elm < n)
	{
		if (*(s1 + elm) == *(s2 + elm))
		{
			++elm;
		}
		else
		{
			return (*(s1 + elm) - *(s2 + elm));
		}
	}
	if (elm == n && (*(s1 + elm) == ' ' || *(s1 + elm) == '\t' ||
		       *(s1 + elm) == '\0' || *(s1 + elm) == '\n'))
		return (0);
	return (EXIT_FAILURE);
}
