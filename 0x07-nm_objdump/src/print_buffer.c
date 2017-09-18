#include "readelf.h"

/**
 * print_char - Prints the char
 * @c:  character to be printed
 * Return: no of bytes printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}
/**
 * char_print_hex - Prints the char in hex
 * @n:  number to be printed
 */
void char_print_hex(char n)
{
	int first = (int)((n & 0xf0) >> 4);
	int second = (int)(n & 0x0f);

	if (first > 9)
	{
		print_char('a' + (first - 10));
	} else
	{
		print_char('0' + first);
	}
	if (second > 9)
	{
		print_char('a' + (second - 10));
	} else
	{
		print_char('0' + second);
	}
}
/**
 * print_int_hex - Prints the number in hex
 * @n:  number to be printed
 */
void print_int_hex(int n)
{
	int mask;
	int n_copy = n, count = 0, i = 0;
	int prints[4] = { 0, 0, 0, 0 };

	while (n_copy > 0)
	{
		n_copy /= 256;
		count++;
	}

	for (; count >= 0; count--)
	{
		mask = 0xff;
		for (i = 0; i < count; i++)
			mask *= 0x100;
		prints[3 - count] = (n & mask);
		for (i = 0; i < count; i++)
			prints[3 - count] = (prints[3 - count] >> 8);
	}
	for (i = 0; i < 4; i++)
	{
		char_print_hex((char)prints[i]);
	}
}
/**
 * print_buffer - Prints the buffer dump
 * @b:  contents to be dumped
 * @size: size of the contents
 * @address: offset of the content
 */
void print_buffer(char *b, int size, uint64_t address)
{
	uint64_t end = address + size;
	int currpos = 0, currrow = 0, c = 0, padding = lenHelper(address);

	if (padding < 4)
		padding = 4;
	while (currpos < size)
	{
		printf(" %0*lx", padding, address);
		fflush(stdout);
		do {
			if (currpos % 4 == 0)
				print_char(' ');
			if (currpos > size)
			{
				SPACE;
			}
			else
			{
				if (address < end)
					char_print_hex(*(b + currpos));
				else
				 SPACE;
			}
			currpos++;
			address++;
		} while (currpos % 16 != 0);
		SPACE;
		currpos = currrow * 16;
		do {
			(isprint(*(b + currpos))) ?	print_char(*(b + currpos)) :	print_char('.');
			currpos++;
			c++;
		} while (currpos % 16 != 0 && currpos < size);
		while (c++ < 16)
			print_char(' ');
		c = 0;
		currrow++;
		print_char('\n');
	}
}
