#include "main.h"
/**
 * get_len - Get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */
int get_len(int n)
{
	unsigned int n1;
	int ln = 1;

	if (n < 0)
	{
		++ln;
		n1 = -1 * n;
	}
	else
		n1 = n;
	while (n1 > 9)
		++ln, n1 /= 10;
	return (ln);
}
/**
 * aux_itoa - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *aux_itoa(int n)
{
	unsigned int n1;
	int ln = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (ln + 1));
	if (!buffer)
		return (NULL);

	*(buffer + ln) = '\0';

	if (n < 0)
	{
		n1 = -1 * n;
		buffer[0] = '-';
	}
	else
		n1 = n;
	--ln;
	do {
		*(buffer + ln) = (n1 % 10) + '0';
		n1 /= 10;
		--ln;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			++size;
		}
		++count;
	}

	for (i = count - size; i < count; ++i)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
