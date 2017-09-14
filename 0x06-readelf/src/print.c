#include "readelf.h"

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
 * read_elf_header -  fills the elf header info
 * @ehdr: elf header structure
 * @entries: elf header info filled in key and values
 */
void read_elf_header(ElfN_Ehdr ehdr, Entry entries[])
{
	entries[0].key = strdup("Class");
	entries[0].value = get_elf_class(ehdr.e_ident[EI_CLASS]);
	entries[1].key = strdup("Data");
	entries[1].value = get_data_encoding(ehdr.e_ident[EI_DATA]);
	entries[2].key = strdup("Version");
	entries[2].value = get_elf_version(ehdr.e_ident[EI_VERSION]);
	entries[3].key = strdup("OS/ABI");
	entries[3].value = get_osabi_name(ehdr.e_ident[EI_OSABI]);
	entries[4].key = strdup("ABI Version");
	entries[4].value = get_vma(ehdr.e_ident[EI_ABIVERSION], 'd', '0');
	entries[5].key = strdup("Type");
	entries[5].value = get_file_type(ehdr.e_type);
	entries[6].key = strdup("Machine");
	entries[6].value = get_machine_name(ehdr.e_machine);
	entries[7].key = strdup("Version");
	entries[7].value = get_vma(ehdr.e_version, 'x', '0');
	entries[8].key = strdup("Entry point address");
	entries[8].value = get_vma(ehdr.e_entry, 'x', '0');
	entries[9].key = strdup("Start of program headers");
	entries[9].value = get_vma(ehdr.e_phoff, 'd', 'f');
	entries[10].key = strdup("Start of section headers");
	entries[10].value = get_vma(ehdr.e_shoff, 'd', 'f');
	entries[11].key = strdup("Flags");
	entries[11].value = get_vma(ehdr.e_flags, 'x', '0');
	entries[12].key = strdup("Size of this header");
	entries[12].value = get_vma(ehdr.e_ehsize, 'd', 'b');
	entries[13].key = strdup("Size of program headers");
	entries[13].value = get_vma(ehdr.e_phentsize, 'd', 'b');
	entries[14].key = strdup("Number of program headers");
	entries[14].value = get_vma(ehdr.e_phnum, 'd', '0');
	entries[15].key = strdup("Size of section headers");
	entries[15].value = get_vma(ehdr.e_shentsize, 'd', 'b');
	entries[16].key = strdup("Number of section headers");
	entries[16].value = get_vma(ehdr.e_shnum, 'd', '0');
	entries[17].key = strdup("Section header string table index");
	entries[17].value = get_vma(ehdr.e_shstrndx, 'd', '0');
}

/**
 * print_elf_header -  displays the elf header section as "read elf -W -h"
 * @ehdr: elf header structure
 */
void print_elf_header(ElfN_Ehdr ehdr)
{
	int i = 0;
	Entry entries[18];

	read_elf_header(ehdr, entries);
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x ", ehdr.e_ident[i]);
		if (i == 15)
			printf("\n");
	}
	for (i = 0; i < 18; i++)
	{
		printf("  %s:%*s%s\n", entries[i].key,
		       34 - (int)strlen(entries[i].key), "", entries[i].value);
	}
}
/**
 * print_flag_detials - display the flag details when section headers are
 * printed
 * @arch32 : if architecture is 32 then true else false
 */
void print_flag_detials(bool arch32)
{
	printf("%s\n", "Key to Flags:");
	if (arch32)
		printf("  %s\n",
		       "W (write), A (alloc), X (execute), M (merge), S (strings)");
	else
	{
		printf("  %s\n",
		       "W (write), A (alloc), X (execute), M (merge), S (strings), l (large)");
	}
	printf("  %s\n",
	       "I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)");
	printf("  %s\n",
	       "O (extra OS processing required) o (OS specific), p (processor specific)");
}

/**
 * print_elf_section_header -  displays the elf header section as
 * "read elf -W -S"
 * @sh_tbl: section header table
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 */
void print_elf_section_header(ElfN_Shdr sh_tbl[], ElfN_Ehdr ehdr, int fd)
{
	int i = 0;
	char *str_tbl;
	bool arch32 = ehdr.e_ident[EI_CLASS] == ELFCLASS32;

	if (ehdr.e_shnum == 0)
	{
		printf("There are no sections in this file.\n");
		return;
	}
	str_tbl = read_section(fd, sh_tbl[ehdr.e_shstrndx]);
	printf("There are %d section headers, starting at offset 0x%x:\n\n",
	       ehdr.e_shnum, (unsigned int)ehdr.e_shoff);
	printf("Section Headers:\n");
	if (arch32)
	{
		printf("  [Nr] Name              Type            Addr     Off    ");
		printf("Size   ES Flg Lk Inf Al\n");
	} else
	{
		printf("  [Nr] Name              Type            Address          Off ");
		printf("   Size   ES Flg Lk Inf Al\n");
	}
	for (i = 0; i < ehdr.e_shnum; i++)
	{
		printf("  [%2u] %-17s %-15.15s ", i,
		       str_tbl + sh_tbl[i].sh_name,
		       get_section_type_name(sh_tbl[i].sh_type));
		printf("%0*x %6.6lx %6.6lx %2.2lx", arch32 ? 8 : 16,
		       (unsigned int)sh_tbl[i].sh_addr,
		       (unsigned long)sh_tbl[i].sh_offset,
		       (unsigned long)sh_tbl[i].sh_size,
		       (unsigned long)sh_tbl[i].sh_entsize);
		printf(" %3s ",
		       get_elf_section_flags(ehdr, sh_tbl[i].sh_flags));
		printf("%2ld %3lu %2ld\n", (unsigned long)sh_tbl[i].sh_link,
		       (unsigned long)sh_tbl[i].sh_info,
		       (unsigned long)sh_tbl[i].sh_addralign);
	}
	print_flag_detials(arch32);
}
