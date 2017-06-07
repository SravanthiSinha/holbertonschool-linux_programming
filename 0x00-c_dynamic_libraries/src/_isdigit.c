/**
 * _isdigit - checks whether the passed character is  a digit (0 through 9)
 * @c: This is the character to be checked
 *
 * Return: This function returns a non-zero value(true) if c is a digit else,
 * zero (false).
 */
int _isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}
