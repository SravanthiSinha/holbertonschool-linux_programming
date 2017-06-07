/**
 * _strlen - calculate the length of a string
 * @s: This is the string whose length has to be calculated.
 *
 * Return: Number of bytes in the string s.
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

