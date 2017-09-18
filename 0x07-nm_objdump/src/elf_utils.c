#include "readelf.h"

/**
 * get_byte_big_endian -  fetches the bytes in big endian formatted data
 * @data: data to be fetched
 * @size: size of the data
 *
 * Return: the bytes in big endian format data.
 */
uint64_t get_byte_big_endian(uint64_t data, int size)
{
	switch (size)
	{
	case 2:
		return (be16toh(data));
	case 4:
		return (be32toh(data));
	case 8:
		return (be64toh(data));
	default:
		return (0);
	}
}

/**
 * get_byte_host -  fetches the bytes
 * @data: data to be fetched
 * @size: size of the data
 *
 * Return: the data.
 */
uint64_t get_byte_host(uint64_t data, int __attribute__ ((unused)) size)
{
	return (data);
}


/**
 * get_vma - gets the value with appropriate format and end string
 * @no: input no be formated.
 * @format: d - decimal, hex- hexadecimal
 * @end: end string f- file bytes , b -bytes
 * Return: formatted value
 */
char *get_vma(unsigned int no, char format, char end)
{
	char buff[32];

	if (format == 'd' && end == 'b')
		sprintf(buff, "%d (bytes)", no);
	else if (format == 'd' && end == 'f')
		sprintf(buff, "%d (bytes into file)", no);
	else if (format == 'd')
		sprintf(buff, "%d", no);
	else if (format == 'x')
		sprintf(buff, "0x%x", no);
	return (strdup(buff));
}


/**
 * read_section- fetches the section
 * @sh: section header
 * @fd: file descriptor of input elf file
 * Return: string representation of the file
 */
char *read_section(int fd, ElfN_Shdr sh)
{
	char *buff = malloc(sh.sh_size + 1);

	if (!buff)
	{
		printf("Failed to allocate\n");
	}

	assert(buff != NULL);
	assert(lseek(fd, (off_t) sh.sh_offset, SEEK_SET) ==
	       (off_t) sh.sh_offset);
	assert(read(fd, (void *)buff, sh.sh_size) == (ssize_t) sh.sh_size);
	buff[sh.sh_size] = '\0';
	return (buff);
}

/**
 * get_file_type - gets the file type of elf
 * @e_type: file type of elf
 * Return: file type of elf
 */
char *get_file_type(unsigned int e_type)
{
	char buff[32];

	switch (e_type)
	{
	case ET_NONE:
		return (strdup("NONE (None)"));
	case ET_REL:
		return (strdup("REL (Relocatable file)"));
	case ET_EXEC:
		return (strdup("EXEC (Executable file)"));
	case ET_DYN:
		return (strdup("DYN (Shared object file)"));
	case ET_CORE:
		return (strdup("CORE (Core file)"));
	default:
		if ((e_type >= ET_LOPROC) && (e_type <= ET_HIPROC))
			snprintf(buff, sizeof(buff),
				 ("Processor Specific: (%x)"), e_type);
		else if ((e_type >= ET_LOOS) && (e_type <= ET_HIOS))
			snprintf(buff, sizeof(buff), ("OS Specific: (%x)"),
				 e_type);
		else
			snprintf(buff, sizeof(buff), ("<unknown>: %x"), e_type);
		return (strdup(buff));
	}
}
