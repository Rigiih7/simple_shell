#include "shell.h"

/**
 *interactive - true if the shell is in interactive mode
 *@info: address for the struct
 *
 *Return: if the shell is in interactive mode 1, false 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *is_delim - to check if a char is a delimeter
 *@c: character to be checked
 *@delim: delimeter string
 *Return: 0 if false, 1 true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checking if alphabetic character is present
 *@c: input char
 *Return: if c is an alphabetic char 1, 0 false
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - for string to integer conversion
 *@s: string to convert to integer
 *Return: if there is no numbers in string 0, converted number if true
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
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
