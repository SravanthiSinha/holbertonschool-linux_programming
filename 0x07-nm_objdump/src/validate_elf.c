#include "readelf.h"

/**
 * elf_check_file -  checks if the elf file is valid
 * @magic: magic string
 *
 * Return: on success:  true , on Failure: false.
 */
bool elf_check_file(unsigned char *magic)
{

	if (magic[0] != ELFMAG0)
	{
		/* printf("ELF Header EI_MAG0 incorrect.\n"); */
		return (false);
	}
	if (magic[1] != ELFMAG1)
	{
		/* printf("ELF Header EI_MAG1 incorrect.\n"); */
		return (false);
	}
	if (magic[2] != ELFMAG2)
	{
		/* printf("ELF Header EI_MAG2 incorrect.\n"); */
		return (false);
	}
	if (magic[3] != ELFMAG3)
	{
		/* printf("ELF Header EI_MAG3 incorrect.\n"); */
		return (false);
	}
	return (true);
}

/**
 * get_architecture -  fetches the architecture of the elf file
 * @c: char
 * @arch: architecture - 32 /64
 *
 * Return: on success:  true , on Failure: false.
 */
bool get_architecture(char c, int *arch)
{
	if (c == ELFCLASS32)
	{
		*arch = 32;
	} else if (c == ELFCLASS64)
	{
		*arch = 64;
	} else
		return (false);
	return (true);
}
