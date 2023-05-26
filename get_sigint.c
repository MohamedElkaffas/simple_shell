#include "main.h"

/**
 * get_sigint - Handle the crtl + c call
 * @s: Signal han
 */
void get_sigint(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
