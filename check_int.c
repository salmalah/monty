#include "monty.h"
/**
 * is_integer - Check if a string is a valid integer
 * @s: input string
 * Return: 1 if valid integer, 0 otherwise
 */
int is_integer(const char *s)
{
	if (s == NULL || *s == '\0')
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
