#include "readelf.h"
/**
 * is_from_section - check if the symbol is from @s section
 * @sh_tbl: section header table
 * @symtab: Symbol table
 * @strtab: string table
 * @s: name of the section
 * Return: 1 on succuess else 0
 */
int is_from_section(ElfN_Sym symtab, char *strtab, ElfN_Shdr sh_tbl[],
		    const char *s)
{
	return (!strcmp(strtab + sh_tbl[symtab.st_shndx].sh_name, s));
}
/**
 * determine_st_flag_roftb -  gets the flag based on symbol type
 * @sh_tbl: section header table
 * @symtab: Symbol table
 * @strtab: string table
 * Return: flag
 */
char determine_st_flag_roftb(ElfN_Sym symtab, char *strtab, ElfN_Shdr sh_tbl[])
{
	if (ELF_ST_BIND(symtab.st_info) == STB_WEAK)
	{
		if (!symtab.st_value)
			return (ELF_ST_TYPE(symtab.st_info) ==
				STT_OBJECT ? 'v' : 'w');
		return (ELF_ST_TYPE(symtab.st_info) == STT_OBJECT ? 'V' : 'W');
	} else if (symtab.st_shndx == SHN_COMMON)
		return ('C');
	else if (symtab.st_shndx == SHN_UNDEF)
		return ('U');
	else if (is_from_section(symtab, strtab, sh_tbl, ".debug"))
		return ('N');
	return (0);
}
/**
 * get_st_flag -  gets the flag based on symbol type
 * @sh_tbl: section header table
 * @symtab: Symbol table
 * @strtab: string table
 * Return: flag
 */
char get_st_flag(ElfN_Shdr sh_tbl[], ElfN_Sym symtab, char *strtab)
{
	char t;

	if (symtab.st_shndx == SHN_ABS)
		t = 'a';
	else if (determine_st_flag_roftb(symtab, strtab, sh_tbl))
		return (determine_st_flag_roftb(symtab, strtab, sh_tbl));
	else if (is_from_section(symtab, strtab, sh_tbl, ".bss"))
		t = 'b';
	else if (is_from_section(symtab, strtab, sh_tbl, ".text") ||
		 ELF_ST_TYPE(symtab.st_info) == STT_FUNC ||
		 is_from_section(symtab, strtab, sh_tbl, ".init_array") ||
		 is_from_section(symtab, strtab, sh_tbl, ".fini_array") ||
		 is_from_section(symtab, strtab, sh_tbl, ".plt"))
		t = 't';
	else if (is_from_section(symtab, strtab, sh_tbl, ".rodata") ||
		 is_from_section(symtab, strtab, sh_tbl, ".eh_frame_hdr") ||
		 is_from_section(symtab, strtab, sh_tbl, ".eh_frame"))
		t = 'r';
	else if (ELF_ST_TYPE(symtab.st_info) == STT_OBJECT ||
		 ELF_ST_TYPE(symtab.st_info) == STT_NOTYPE ||
		 is_from_section(symtab, strtab, sh_tbl, ".data") ||
		 is_from_section(symtab, strtab, sh_tbl, ".data1"))
		t = 'd';
	else
		return ('?');
	return (ELF_ST_BIND(symtab.st_info) == STB_LOCAL ? t : t - 32);
}
