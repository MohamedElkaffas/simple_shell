#include "main.h"

/**
 * read_line - reads the input string.
 *
 * @i_f: return value of getline function
 * Return: input
 */
char *read_line(int *i_f)
{
	char *i = NULL;
	size_t bufsize = 0;

	*i_f = getline(&i, &bufsize, stdin);

	return (i);
}
