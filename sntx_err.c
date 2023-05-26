#include "main.h"
/* program for checking syntax errors */
/**
 * repeated_char - counts the repetitions of given char
 * @input: input string
 * @i: index
 * Return: repetitions
 */
int repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, i + 1));
	return (i);
}

/**
 * error_sep_op - finds syntax errors
 * @input: input string
 * @i: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_sep_op(char *input, int i, char last)
{
	int cnt;

	cnt = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);
		if (last == '|')
		{
			cnt = repeated_char(input, 0);
			if (!cnt || cnt > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			cnt = repeated_char(input, 0);
			if (!cnt || cnt > 1)
				return (i);
		}
	}

	return (error_sep_op(input + 1, i + 1, *input));
}

/**
 * first_char - finds index of the first char
 * @input: input string
 * @i: index
 * Return: 1 if there is an error. 0 otherwise.
 */
int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;
		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);
		break;
	}
	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found
 * @datash: data structure
 * @input: input string
 * @i: index of the error
 * @booll: to control msg error
 * Return: no return (nothing)
 */
void print_syntax_error(data_shell *datash, char *input, int i, int booll)
{
	char *msg, *msg2, *msg3, *error, *cnt;
	int ln;

	if (input[i] == ';')
	{
		if (!booll)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	cnt = aux_itoa(datash->counter);
	ln = _strlen(datash->av[0]) + _strlen(cnt);
	ln += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (ln + 1));
	if (!error)
	{
		free(cnt);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, cnt);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3), _strcat(error, "\0");
	write(STDERR_FILENO, error, ln);
	free(error), free(cnt);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax error
 * @datash: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(data_shell *datash, char *input)
{
	int begin = 0;
	int f_char = 0, i = 0;

	f_char = first_char(input, &begin);
	if (f_char == -1)
	{
		print_syntax_error(datash, input, begin, 0);
		return (1);
	}

	i = error_sep_op(input + begin, 0, *(input + begin));
	if (i)
	{
		print_syntax_error(datash, input, begin + i, 1);
		return (1);
	}
	return (0);
}
