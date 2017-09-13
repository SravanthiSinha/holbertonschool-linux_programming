#include "readelf.h"

/**
 * get_machine_name - gets the machine type of elf
 * @e_machine: machine type of elf
 * Return: machine type of elf
 */
char *get_machine_name(unsigned int e_machine)
{
	char buff[64];

	switch (e_machine)
	{
	case EM_NONE:		return (strdup("None"));
	case EM_M32:		return (strdup("WE32100"));
	case EM_SPARC:		return (strdup("Sparc"));
	case EM_386:		return (strdup("Intel 80386"));
	case EM_68K:		return (strdup("MC68000"));
	case EM_88K:		return (strdup("MC88000"));
	case EM_860:		return (strdup("Intel 80860"));
	case EM_MIPS:		return (strdup("MIPS R3000"));
	case EM_PARISC:		return (strdup("HPPA"));
	case EM_SPARC32PLUS:		return (strdup("Sparc v8+"));
	case EM_PPC:		return (strdup("PowerPC"));
	case EM_PPC64:		return (strdup("PowerPC64"));
	case EM_S390:		return (strdup("IBM S/390"));
	case EM_ARM:		return (strdup("ARM"));
	case EM_SH:		return (strdup("Renesas / SuperH SH"));
	case EM_SPARCV9:		return (strdup("SPARC v9"));
	case EM_IA_64:		return (strdup("Intel IA-64"));
	case EM_X86_64:		return (strdup("Advanced Micro Devices X86-64"));
	case EM_VAX:		return (strdup("Digital VAX"));
	default:
		snprintf(buff, sizeof(buff), ("<unknown>: 0x%x"), e_machine);
		return (strdup(buff));
	}
}

/**
 * get_section_type_name - gets the section name
 * @sh_type: section type of elf section
 * Return: the section name
 */
char *get_section_type_name(unsigned int sh_type)
{
	static char buff[32];

	switch (sh_type)
	{
	case SHT_NULL:
		return ("NULL");
	case SHT_PROGBITS:
		return ("PROGBITS");
	case SHT_SYMTAB:
		return ("SYMTAB");
	case SHT_STRTAB:
		return ("STRTAB");
	case SHT_RELA:
		return ("RELA");
	case SHT_HASH:
		return ("HASH");
	case SHT_DYNAMIC:
		return ("DYNAMIC");
	case SHT_NOTE:
		return ("NOTE");
	case SHT_NOBITS:
		return ("NOBITS");
	case SHT_REL:
		return ("REL");
	case SHT_SHLIB:
		return ("SHLIB");
	case SHT_DYNSYM:
		return ("DYNSYM");

	default:
		snprintf(buff, sizeof(buff), ("<unknown>: %x"), sh_type);
		return (buff);
	}
}

/**
 * check - part of get_elf_section_flags
 * @eh: Elf header
 * @sh_flags: sh_flags of elf section
 * @flag: flag
 * @p: flag
 */
void check(ElfN_Ehdr eh, unsigned int flag, unsigned long *sh_flags, char *p)
{
	if (eh.e_machine == EM_X86_64 && flag)
		*p = 'l';
	else if (flag & SHF_MASKOS)
	{
		*p = 'o';
		*sh_flags &= ~SHF_MASKOS;
	} else if (flag & SHF_MASKPROC)
	{
		*p = 'p';
		*sh_flags &= ~SHF_MASKPROC;
	} else
		*p = 'x';
}

/**
 * get_elf_section_flags - gets the section flag of elf
 * @elf_header: Elf header
 * @sh_flags: sh_flags of elf section
 * Return: description of flag of section of elf
 */
char *get_elf_section_flags(ElfN_Ehdr elf_header, unsigned long sh_flags)
{
	static char buff[1024];
	char *p = buff;
	unsigned int flag;

	while (sh_flags)
	{
		flag = sh_flags & -sh_flags;
		sh_flags &= ~flag;
		if (flag == SHF_WRITE)
			*p = 'W';
		else if (flag == SHF_ALLOC)
			*p = 'A';
		else if (flag == SHF_EXECINSTR)
			*p = 'X';
		else if (flag == SHF_MERGE)
			*p = 'M';
		else if (flag == SHF_STRINGS)
			*p = 'S';
		else if (flag == SHF_INFO_LINK)
			*p = 'I';
		else if (flag == SHF_LINK_ORDER)
			*p = 'L';
		else if (flag == SHF_OS_NONCONFORMING)
			*p = 'O';
		else if (flag == SHF_GROUP)
			*p = 'G';
		else if (flag == SHF_TLS)
			*p = 'T';
		else
			check(elf_header, flag, &sh_flags, p);
		p++;
	}
	*p = '\0';
	return (buff);
}
