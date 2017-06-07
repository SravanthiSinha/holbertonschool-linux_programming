/**
 * _isalpha - checks whether the passed character is a alphabet
 * @c: This is the character to be checked
 *
 * Return: This function returns a non-zero value(true) if c is a
 * alphabetic letter else, zero (false).
 */
int _isalpha(int c)
{
	if (c <= 122 && c >= 65)
		return (1);
	return (0);
}
