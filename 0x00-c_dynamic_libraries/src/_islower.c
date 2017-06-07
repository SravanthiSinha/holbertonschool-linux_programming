/**
 * _islower - checks whether the passed character is a lowercase letter.
 * @c: This is the character to be checked
 *
 * Return: This function returns a non-zero value(true) if c is a
 * lowercase alphabetic letter else, zero (false).
 */
int _islower(int c)
{
	if (c <= 122 && c >= 97)
		return (1);
	return (0);
}
