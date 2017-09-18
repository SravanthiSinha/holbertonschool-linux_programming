#include "readelf.h"
/**
 * lenHelper - determines the no of digits in the hex of a number
 * @x: decimal number
 * Return: no of digits
 */
int lenHelper(uint64_t x)
{
	if (x > 4026531840)
		return (9);
	if (x > 251658240)
		return (8);
	if (x > 15728640)
		return (7);
	if (x > 170335)
		return (6);
	if (x > 61476)
		return (5);
	if (x > 4096)
		return (4);
	return (1);
}
