#include "main.h"
/**
 * cd_shell - changes current directory
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *dr;
	int ishome, ishome2, isddash;

	dr = datash->args[1];
	if (dr != NULL)
	{
		ishome = _strcmp("$HOME", dr);
		ishome2 = _strcmp("~", dr);
		isddash = _strcmp("--", dr);
	}

	if (dr == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (!_strcmp("-", dr))
	{
		cd_previous(datash);
		return (1);
	}

	if (!_strcmp(".", dr) || !_strcmp("..", dr))
	{
		cd_dot(datash);
		return (1);
	}
	cd_to(datash);
	return (1);
}
