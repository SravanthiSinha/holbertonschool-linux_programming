/**
 * _strcmp - Compare characters of two strings
 * @s1: C string to be compared.
 * @s2: C string to be compared.
 *
 * Return: An integral value indicating the relationship
 * between the strings
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
