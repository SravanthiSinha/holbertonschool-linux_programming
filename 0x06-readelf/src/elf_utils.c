#include "readelf.h"

/**
 * get_elf_class - gets the class of elf
 * @elf_class: class of elf
 * Return: class of elf
 */
char *get_elf_class(unsigned int elf_class)
{
	char buff[32];

	switch (elf_class)
	{
	case ELFCLASSNONE:
		return (strdup("none"));
	case ELFCLASS32:
		return (strdup("ELF32"));
	case ELFCLASS64:
		return (strdup("ELF64"));
	default:
		snprintf(buff, sizeof(buff), ("<unknown: %x>"), elf_class);
		return (strdup(buff));
	}
}

/**
 * get_data_encoding - gets the encoding of elf
 * @encoding: encoding of elf
 * Return: encoding of elf
 */
char *get_data_encoding(unsigned int encoding)
{
	char buff[32];

	switch (encoding)
	{
	case ELFDATANONE:
		return (strdup("none"));
	case ELFDATA2LSB:
		return (strdup("2's complement, little endian"));
	case ELFDATA2MSB:
		return (strdup("2's complement, big endian"));
	default:
		snprintf(buff, sizeof(buff), ("<unknown: %x>"), encoding);
		return (strdup(buff));
	}
}

/**
 * get_elf_version - gets the version of elf
 * @version: version of elf
 * Return: version of elf
 */
char *get_elf_version(unsigned int version)
{
	char buff[32];

	switch (version)
	{
	case EV_CURRENT:
		return (strdup("1 (current)"));
	default:
		snprintf(buff, sizeof(buff), ("<unknown: %x>"), version);
		return (strdup(buff));
	}
}

/**
 * get_osabi_name - gets the osabi of elf
 * @osabi: osabi of elf
 * Return: osabi of elf
 */
char *get_osabi_name(unsigned int osabi)
{
	char buff[32];

	switch (osabi)
	{
	case ELFOSABI_NONE:
		return (strdup("UNIX - System V"));
	case ELFOSABI_HPUX:
		return (strdup("UNIX - HP-UX"));
	case ELFOSABI_NETBSD:
		return (strdup("UNIX - NetBSD"));
	case ELFOSABI_LINUX:
		return (strdup("UNIX - Linux"));
	case ELFOSABI_SOLARIS:
		return (strdup("UNIX - Solaris"));
	case ELFOSABI_IRIX:
		return (strdup("UNIX - IRIX"));
	case ELFOSABI_FREEBSD:
		return (strdup("UNIX - FreeBSD"));
	case ELFOSABI_TRU64:
		return (strdup("UNIX - TRU64"));
	case ELFOSABI_ARM:
		return (strdup("ARM"));
	case ELFOSABI_STANDALONE:
		return (strdup("Standalone App"));
	default:
		snprintf(buff, sizeof(buff), ("<unknown: %x>"), osabi);
		return (strdup(buff));
	}
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
