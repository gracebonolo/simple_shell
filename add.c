#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "shell.h"

/**
 * is_positive_number - check if a string is a positive number
 * @str: string to check
 *
 * Return: 1 if positive number, 0 otherwise
 */
int is_positive_number(const char *str)
{
	if (*str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

