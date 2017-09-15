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
	case SHT_NULL:	return ("NULL");
	case SHT_PROGBITS:		return ("PROGBITS");
	case SHT_SYMTAB:		return ("SYMTAB");
	case SHT_STRTAB:		return ("STRTAB");
	case SHT_RELA:		return ("RELA");
	case SHT_HASH:		return ("HASH");
	case SHT_DYNAMIC:		return ("DYNAMIC");
	case SHT_NOTE:		return ("NOTE");
	case SHT_NOBITS:		return ("NOBITS");
	case SHT_REL:		return ("REL");
	case SHT_SHLIB:		return ("SHLIB");
	case SHT_DYNSYM:	return ("DYNSYM");
	case SHT_INIT_ARRAY:	return ("INIT_ARRAY");
	case SHT_FINI_ARRAY:		return ("FINI_ARRAY");
	case SHT_PREINIT_ARRAY:		return ("PREINIT_ARRAY");
	case SHT_GNU_HASH:		return ("GNU_HASH");
	case SHT_GROUP:		return ("GROUP");
	case SHT_SYMTAB_SHNDX:		return ("SYMTAB SECTION INDICIES");
	case SHT_GNU_verdef:		return ("VERDEF");
	case SHT_GNU_verneed:		return ("VERNEED");
	case SHT_GNU_versym:		return ("VERSYM");
	case 0x6ffffff0:		return ("VERSYM");
	case 0x6ffffffc:		return ("VERDEF");
	case 0x7ffffffd:		return ("AUXILIARY");
	case 0x7fffffff:		return ("FILTER");
	case SHT_GNU_LIBLIST:		return ("GNU_LIBLIST");
	default:
		if ((sh_type >= SHT_LOOS) && (sh_type <= SHT_HIOS))
			sprintf(buff, "LOOS+%x", sh_type - SHT_LOOS);
		else if ((sh_type >= SHT_LOUSER) && (sh_type <= SHT_HIUSER))
			sprintf(buff, "LOUSER+%x", sh_type - SHT_LOUSER);
		else
			snprintf(buff, sizeof(buff), ("<unknown>: %x"),
				 sh_type);
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
	if (eh.e_machine == EM_X86_64 && flag == SHF_X86_64_LARGE)
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
	long flag;

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
		else if (sh_flags == 0)
			*p = 'E';
		else
			check(elf_header, flag, &sh_flags, p);
		p++;
	}
	*p = '\0';
	return (buff);
}
/**
 * get_segment_type - gets the segment type  of elf
 * @p_type: p_type of elf program header
 * Return: description of segment type of elf program header
 */
char *get_segment_type(unsigned long p_type)
{
	static char buff[32];

	switch (p_type)
	{
	case PT_NULL:
		return ("NULL");
	case PT_LOAD:
		return ("LOAD");
	case PT_DYNAMIC:
		return ("DYNAMIC");
	case PT_INTERP:
		return ("INTERP");
	case PT_NOTE:
		return ("NOTE");
	case PT_SHLIB:
		return ("SHLIB");
	case PT_PHDR:
		return ("PHDR");
	case PT_TLS:
		return ("TLS");
	case PT_GNU_EH_FRAME:
		return ("GNU_EH_FRAME");
	case PT_GNU_STACK:
		return ("GNU_STACK");
	case PT_GNU_RELRO:
		return ("GNU_RELRO");

	default:
		if ((p_type >= PT_LOPROC) && (p_type <= PT_HIPROC))
		{
			sprintf(buff, "LOPROC+%lx", p_type - PT_LOPROC);
		} else if ((p_type >= PT_LOOS) && (p_type <= PT_HIOS))
		{
			sprintf(buff, "LOOS+%lx", p_type - PT_LOOS);
		} else
			snprintf(buff, sizeof(buff), ("<unknown>: %lx"),
				 p_type);
		return (buff);
	}
}
