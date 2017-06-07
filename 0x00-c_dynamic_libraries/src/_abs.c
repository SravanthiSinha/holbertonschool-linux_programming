/**
 * _abs - function computes the absolute value of the integer argument c
 * @c: This is the character to be checked
 *
 * Return: Absolute  value  of  the integer argument, of the appropriate
 * integer type for the function.
 */
int _abs(int c)
{
	if (c >= 0)
		return (c);
	return (-1 * c);
}
