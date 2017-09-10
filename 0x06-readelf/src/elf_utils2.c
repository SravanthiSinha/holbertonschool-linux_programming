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
