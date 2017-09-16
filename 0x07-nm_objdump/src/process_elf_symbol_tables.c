#include "readelf.h"

/**
 * read_elf_symbol_table_32- fills the sym with suitable(32)
 * architecture data
 * @sym_tbl: section header table
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 * @shdr: SECTION header containing symbol table section
 */
void read_elf_symbol_table_32(ElfN_Ehdr ehdr, ElfN_Shdr shdr,
			      ElfN_Sym *sym_tbl, int fd)
{
	uint64_t (*get_byte)(uint64_t, int), i;

	Elf32_Sym sym32_tbl;

	get_byte = (ehdr.e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian
	    : get_byte_host;

	assert(lseek(fd, (off_t) shdr.sh_offset, SEEK_SET) ==
	       (off_t) shdr.sh_offset);

	for (i = 0; i < shdr.sh_size / sizeof(Elf32_Sym); i++)
	{
		read(fd, (void *)&sym32_tbl, shdr.sh_entsize);

		sym_tbl[i].st_name = GET_BYTE(sym32_tbl.st_name);
		sym_tbl[i].st_info = GET_BYTE(sym32_tbl.st_info);
		sym_tbl[i].st_other = GET_BYTE(sym32_tbl.st_other);
		sym_tbl[i].st_shndx = GET_BYTE(sym32_tbl.st_shndx);
		sym_tbl[i].st_value = GET_BYTE(sym32_tbl.st_value);
		sym_tbl[i].st_size = GET_BYTE(sym32_tbl.st_size);
	}
}

/**
 * read_elf_symbol_table_64- fills the sym with suitable(64)
 * architecture data
 * @sym_tbl: section header table
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 * @shdr: SECTION header containing symbol table section
 */
void read_elf_symbol_table_64(ElfN_Ehdr ehdr, ElfN_Shdr shdr,
			      ElfN_Sym *sym_tbl, int fd)
{
	uint64_t (*get_byte)(uint64_t, int), i;
	Elf64_Sym sym64_tbl;

	get_byte = (ehdr.e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian
	    : get_byte_host;

	assert(lseek(fd, (off_t) shdr.sh_offset, SEEK_SET) ==
	       (off_t) shdr.sh_offset);

	for (i = 0; i < shdr.sh_size / sizeof(Elf64_Sym); i++)
	{
		read(fd, (void *)&sym64_tbl, shdr.sh_entsize);

		sym_tbl[i].st_name = GET_BYTE(sym64_tbl.st_name);
		sym_tbl[i].st_info = GET_BYTE(sym64_tbl.st_info);
		sym_tbl[i].st_other = GET_BYTE(sym64_tbl.st_other);
		sym_tbl[i].st_shndx = GET_BYTE(sym64_tbl.st_shndx);
		sym_tbl[i].st_value = GET_BYTE(sym64_tbl.st_value);
		sym_tbl[i].st_size = GET_BYTE(sym64_tbl.st_size);
	}
}

/**
 * read_elf_symbol_table_N-  fills the ehdr with suitable(N) architecture
 * data
 * @ehdr: elf header structure
 * @file: input file
 * @arch: architecture of the elf file
 * Return: 1- if no symbols else 0
 */
int read_elf_symbol_table_N(ElfN_Ehdr *ehdr, FILE *file, int arch)
{
	ElfN_Shdr *sh_tbl;
	ElfN_Sym *sym_tbl;
	int i;
	uint64_t count = 0;

	if (arch == 64)
		read_elf_header_64(ehdr, file);
	else if (arch == 32)
		read_elf_header_32(ehdr, file);
	sh_tbl = malloc(sizeof(ElfN_Shdr) * ehdr->e_shnum);

	if (!sh_tbl)
		printf("Failed to allocate section header table\n");
	if (arch == 64)
		read_elf_section_header_64(*ehdr, sh_tbl, fileno(file));
	else if (arch == 32)
		read_elf_section_header_32(*ehdr, sh_tbl, fileno(file));
	for (i = 0; i < ehdr->e_shnum; i++)
	{
		if (sh_tbl[i].sh_type == SHT_SYMTAB)
		{
			if (arch == 64)
			{
				count = sh_tbl[i].sh_size / sizeof(Elf64_Sym);
				sym_tbl = malloc(sizeof(ElfN_Sym) * count);
				read_elf_symbol_table_64(*ehdr, sh_tbl[i],
							 sym_tbl, fileno(file));
			} else if (arch == 32)
			{
				count = sh_tbl[i].sh_size / sizeof(Elf32_Sym);
				sym_tbl = malloc(sizeof(ElfN_Sym) * count);
				read_elf_symbol_table_32(*ehdr, sh_tbl[i],
							 sym_tbl, fileno(file));
			}
			print_elf_symbol_table(sh_tbl, sym_tbl, *ehdr, count,
					       fileno(file));
		}
	}
	return (count ? 1 : 0);
}

/**
 * isprintable -  checks if the symbol is printable
 * @strtab: string table
 * @st: Symbol table
 * Return: On success -1 , On Failure 0
 */
int isprintable(char *strtab, ElfN_Sym st)
{
	return (strtab[st.st_name] && ELF_ST_TYPE(st.st_info) != STT_FILE);
}

/**
 * print_elf_symbol_table -  displays the elf header section as
 * "read elf -W -s"
 * @sh_tbl: section header table
 * @ehdr: Elf header
 * @sym_tbl: Symbol table
 * @count: no of symbols
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 */
void print_elf_symbol_table(ElfN_Shdr sh_tbl[], ElfN_Sym sym_tbl[],
			    ElfN_Ehdr ehdr, uint64_t count,
			    int fd)
{
	uint64_t i = 0;
	char *str_tbl;
	char *symbol_str_tbl;
	bool arch32 = ehdr.e_ident[EI_CLASS] == ELFCLASS32;

	str_tbl = read_section(fd, sh_tbl[ehdr.e_shstrndx]);
	for (i = 0; i < ehdr.e_shnum; i++)
		if (strcmp(str_tbl + sh_tbl[i].sh_name, ".strtab") == 0)
			symbol_str_tbl = read_section(fd, sh_tbl[i]);
	for (i = 0; i < count; i++)
	{
		if (isprintable(symbol_str_tbl, sym_tbl[i]))
		{
			if (get_st_flag(sh_tbl, sym_tbl[i], str_tbl) != 'U' &&
			    get_st_flag(sh_tbl, sym_tbl[i], str_tbl) != 'w')
				printf("%0*x", arch32 ? 8 : 16,
				       (unsigned int)sym_tbl[i].st_value);
			else
				printf("%*s", arch32 ? 8 : 16, "");
			printf(" %c ", get_st_flag(sh_tbl, sym_tbl[i], str_tbl));
			printf("%s", symbol_str_tbl + sym_tbl[i].st_name);
			printf("\n");
		}
	}
}
