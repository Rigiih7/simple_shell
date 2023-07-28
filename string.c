#include "shell.h"

/**
 *_strlen - function to return length of given string
 *@s: string whose length is being checked
 *
 *Return: legnth of string as integer
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 *_strcmp - for performing comparison of two given strings.
 *@s1: irst string
 *@s2: second string
 *
 *Return: positive if s1 > s2, zero if s1 == s2, negative if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 *starts_with - checks needle begins with haystack
 *@haystack: the string being searched
 *@needle: substring to be found
 *
 *Return:the address to next character of haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - for concatenation of two strings
 * @dest: destination buffer
 * @src: source buffer
 *
 *Return: destination buffer pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
