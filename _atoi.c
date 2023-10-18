#include "shell.h"

/**
 * interactive_mode - it would return true if shell is in interactive mode
 * @info: The struct address
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_Delim - it checks if a character is a delimeter
 * @c: the char to be checked
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_Delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isAlpha - it checks for an alphabetic character
 * @c: The character to be printed
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isAlpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _Atoi - it converts a string to an integer
 * @s: the string that is to be converted
 * Return: 0 if no numbers in a string, converted number otherwise
 */

int _Atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
