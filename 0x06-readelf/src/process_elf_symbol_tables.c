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
		assert(read(fd, (void *)&sym32_tbl, shdr.sh_entsize) ==
		       shdr.sh_entsize);

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
		assert(read(fd, (void *)&sym64_tbl, shdr.sh_entsize) ==
		       shdr.sh_entsize);

		sym_tbl[i].st_name = GET_BYTE(sym64_tbl.st_name);
		sym_tbl[i].st_info = GET_BYTE(sym64_tbl.st_info);
		sym_tbl[i].st_other = GET_BYTE(sym64_tbl.st_other);
		sym_tbl[i].st_shndx = GET_BYTE(sym64_tbl.st_shndx);
		sym_tbl[i].st_value = GET_BYTE(sym64_tbl.st_value);
		sym_tbl[i].st_size = GET_BYTE(sym64_tbl.st_size);
	}
}

/**
 * read_elf_symbol_table_N -  fills the ehdr with suitable(N) architecture
 * data
 * @ehdr: elf header structure
 * @file: input file
 * @arch: architecture of the elf file
 */
void read_elf_symbol_table_N(ElfN_Ehdr *ehdr, FILE *file, int arch)
{
	ElfN_Shdr *sh_tbl;
	ElfN_Sym *sym_tbl;
	char *section_name;
	int i;
	uint64_t count;

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
		if ((sh_tbl[i].sh_type == SHT_SYMTAB) ||
		    (sh_tbl[i].sh_type == SHT_DYNSYM))
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
			print_elf_symbol_table(sh_tbl, sym_tbl, *ehdr, i, count,
					       fileno(file));
		}
	}
}

/**
 * print_elf_symbol_table -  displays the elf header section as
 * "read elf -W -s"
 * @sh_tbl: section header table
 * @ehdr: Elf header
 * @sym_tbl: Symbol table
 * @sym_tbl_indx: symbol table index in section header table
 * @count: no of symbols
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 */
void print_elf_symbol_table(ElfN_Shdr sh_tbl[], ElfN_Sym sym_tbl[],
			    ElfN_Ehdr ehdr, int sym_tbl_indx, uint64_t count,
			    int fd)
{
	uint64_t i = 0;
	char *str_tbl;
	char *symbol_str_tbl;
	char *dynamic_str_tbl;
	bool arch32 = ehdr.e_ident[EI_CLASS] == ELFCLASS32;

	str_tbl = read_section(fd, sh_tbl[ehdr.e_shstrndx]);
	for (i = 0; i < ehdr.e_shnum; i++)
		if (strcmp(str_tbl + sh_tbl[i].sh_name, ".strtab") == 0)
			symbol_str_tbl = read_section(fd, sh_tbl[i]);
	for (i = 0; i < ehdr.e_shnum; i++)
		if (strcmp(str_tbl + sh_tbl[i].sh_name, ".dynstr") == 0)
			dynamic_str_tbl = read_section(fd, sh_tbl[i]);
	printf("\nSymbol table '%s' contains %lu entries:\n",
	       str_tbl + sh_tbl[sym_tbl_indx].sh_name, count);
	if (arch32)
		printf("   Num:    Value  Size Type    Bind   Vis      Ndx Name\n");
	else
			printf
		    ("   Num:    Value          Size Type    Bind   Vis      Ndx Name\n");
	for (i = 0; i < count; i++)
	{
		printf("%6lu: ", i);
		printf("%0*x", arch32 ? 8 : 16,
		       (unsigned int)sym_tbl[i].st_value);
		printf("%6d", (unsigned int)sym_tbl[i].st_size);
		printf(" %-7s",
		       get_symbol_type(ELF_ST_TYPE(sym_tbl[i].st_info)));
		printf(" %-6s",
		       get_symbol_binding(ELF_ST_BIND(sym_tbl[i].st_info)));
		printf(" %-7s", get_symbol_visibility(sym_tbl[i].st_other));
		printf(" %4s ", get_symbol_index_type(sym_tbl[i].st_shndx));
		if (strcmp(str_tbl + sh_tbl[sym_tbl_indx].sh_name, ".dynsym") == 0)
			printf("%s", dynamic_str_tbl + sym_tbl[i].st_name);
		else
			printf("%s", symbol_str_tbl + sym_tbl[i].st_name);
		printf("\n");
	}
}
