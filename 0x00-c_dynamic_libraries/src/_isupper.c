/**
 * _isupper - checks whether the passed character is an upper case alphabet
 * @c: This is the character to be checked
 *
 * Return: This function returns a non-zero value(true) if c is a
 * upper case alphabetic letter else, zero (false).
 */
int _isupper(int c)
{
	if (c <= 90 && c >= 65)
		return (1);
	return (0);
}
