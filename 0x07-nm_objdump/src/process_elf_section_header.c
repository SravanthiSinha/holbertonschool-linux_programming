#include "readelf.h"

/**
 * read_elf_section_header_32- fills the sh with suitable(32)
 * architecture data
 * @sh_tbl: section header table
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 */
void read_elf_section_header_32(ElfN_Ehdr ehdr, ElfN_Shdr *sh_tbl, int fd)
{
	uint64_t (*get_byte)(uint64_t, int), i;

	Elf32_Shdr shdr32_tbl;

	get_byte = (ehdr.e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian
	    : get_byte_host;

	assert(lseek(fd, (off_t) ehdr.e_shoff, SEEK_SET) ==
	       (off_t) ehdr.e_shoff);

	for (i = 0; i < ehdr.e_shnum; i++)
	{
		assert(read(fd, (void *)&shdr32_tbl, ehdr.e_shentsize) ==
		       ehdr.e_shentsize);

		sh_tbl[i].sh_name = GET_BYTE(shdr32_tbl.sh_name);
		sh_tbl[i].sh_type = GET_BYTE(shdr32_tbl.sh_type);
		sh_tbl[i].sh_flags = GET_BYTE(shdr32_tbl.sh_flags);
		sh_tbl[i].sh_addr = GET_BYTE(shdr32_tbl.sh_addr);
		sh_tbl[i].sh_offset = GET_BYTE(shdr32_tbl.sh_offset);
		sh_tbl[i].sh_size = GET_BYTE(shdr32_tbl.sh_size);
		sh_tbl[i].sh_link = GET_BYTE(shdr32_tbl.sh_link);
		sh_tbl[i].sh_info = GET_BYTE(shdr32_tbl.sh_info);
		sh_tbl[i].sh_addralign = GET_BYTE(shdr32_tbl.sh_addralign);
		sh_tbl[i].sh_entsize = GET_BYTE(shdr32_tbl.sh_entsize);
	}
}

/**
 * read_elf_section_header_64- fills the sh with suitable(64)
 * architecture data
 * @sh_tbl: section header table
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 */
void read_elf_section_header_64(ElfN_Ehdr ehdr, ElfN_Shdr *sh_tbl, int fd)
{
	uint64_t (*get_byte)(uint64_t, int), i;
	Elf64_Shdr shdr64_tbl;

	get_byte = (ehdr.e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian
	    : get_byte_host;

	assert(lseek(fd, (off_t) ehdr.e_shoff, SEEK_SET) ==
	       (off_t) ehdr.e_shoff);

	for (i = 0; i < ehdr.e_shnum; i++)
	{
		assert(read(fd, (void *)&shdr64_tbl, ehdr.e_shentsize) ==
		       ehdr.e_shentsize);

		sh_tbl[i].sh_name = GET_BYTE(shdr64_tbl.sh_name);
		sh_tbl[i].sh_type = GET_BYTE(shdr64_tbl.sh_type);
		sh_tbl[i].sh_flags = GET_BYTE(shdr64_tbl.sh_flags);
		sh_tbl[i].sh_addr = GET_BYTE(shdr64_tbl.sh_addr);
		sh_tbl[i].sh_offset = GET_BYTE(shdr64_tbl.sh_offset);
		sh_tbl[i].sh_size = GET_BYTE(shdr64_tbl.sh_size);
		sh_tbl[i].sh_link = GET_BYTE(shdr64_tbl.sh_link);
		sh_tbl[i].sh_info = GET_BYTE(shdr64_tbl.sh_info);
		sh_tbl[i].sh_addralign = GET_BYTE(shdr64_tbl.sh_addralign);
		sh_tbl[i].sh_entsize = GET_BYTE(shdr64_tbl.sh_entsize);
	}
}

/**
 * read_elf_section_header_N -  fills the ehdr with suitable(N) architecture
 * data
 * @ehdr: elf header structure
 * @file: input file
 * @arch: architecture of the elf file
 * @filename : input file name
 */
void read_elf_section_header_N(ElfN_Ehdr *ehdr, FILE *file, int arch,
			       char *filename)
{
	ElfN_Shdr *sh_tbl;
	unsigned int flags;
	int ret;

	ret = 0;
	flags = BFD_NO_FLAGS;
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
	printf("\n%s:     file format elf%d-%s\n", filename, arch,
	       get_file_format_name(*ehdr));
	flags = get_flags(ehdr, sh_tbl, fileno(file));
	printf("architecture: %s, flags 0x%08x:\n",
	       get_arch_mach_name(ehdr->e_machine), flags);
	if (flags == BFD_NO_FLAGS)
		printf("BFD_NO_FLAGS");
	else
	{
		ret |= _F(flags, HAS_RELOC, ret);
		ret |= _F(flags, EXEC_P, ret);
		ret |= _F(flags, HAS_LINENO, ret);
		ret |= _F(flags, HAS_DEBUG, ret);
		ret |= _F(flags, HAS_SYMS, ret);
		ret |= _F(flags, DYNAMIC, ret);
		ret |= _F(flags, WP_TEXT, ret);
		ret |= _F(flags, D_PAGED, ret);
	}
	printf("\n");
	printf("start address 0x%0*lx\n\n", arch == 32 ? 8 : 16, ehdr->e_entry);
	print_elf_section_header(sh_tbl, *ehdr, fileno(file));
}

bool display_section(uint32_t type, ElfN_Ehdr ehdr, ElfN_Shdr shdr,
		     char *str_tbl)
{
	if (type == SHT_NULL || type == SHT_NOBITS || type == SHT_SYMTAB)
		return (false);
	if (type == SHT_STRTAB && !(shdr.sh_flags & SHF_ALLOC))
		return (false);
	if ((ehdr.e_type == ET_EXEC || ehdr.e_type == ET_DYN) &&
	    (type == SHT_REL || type == SHT_RELA))
		return (true);
	if (ehdr.e_type != ET_EXEC && (type == SHT_REL || type == SHT_RELA))
		return (false);
	if (ehdr.e_type == ET_EXEC
	    && (!strcmp(str_tbl + shdr.sh_name, ".text")
		|| !strcmp(str_tbl + shdr.sh_name, ".data")))
		return (true);
	if (ehdr.e_type == ET_DYN
	    && (!strcmp(str_tbl + shdr.sh_name, ".text")
		|| !strcmp(str_tbl + shdr.sh_name, ".data")))
		return (true);
	if (ehdr.e_machine == EM_X86_64 &&
	    (!strcmp(str_tbl + shdr.sh_name, ".text") ||
	     !strcmp(str_tbl + shdr.sh_name, ".data")))
		return (false);
	if (!strcmp(str_tbl + shdr.sh_name, ".tm_clone_table"))
		return (false);
	if (!strcmp(str_tbl + shdr.sh_name, ".note.GNU-stack"))
		return (false);
	if (!strlen(str_tbl + shdr.sh_name))
		return (false);
	return (true);
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
	char *content;
	uint64_t address;
	uint16_t type;

	if (ehdr.e_shnum == 0)
	{
		printf("There are no sections in this file.\n");
		return;
	}
	str_tbl = read_section(fd, sh_tbl[ehdr.e_shstrndx]);
	for (i = 0; i < ehdr.e_shnum; i++)
	{
		type = sh_tbl[i].sh_type;
		if (display_section(type, ehdr, sh_tbl[i], str_tbl))
		{
			printf("Contents of section %s:\n",
			       str_tbl + sh_tbl[i].sh_name);
			fflush(stdout);
			content = read_section(fd, sh_tbl[i]);
			address = sh_tbl[i].sh_addr;
			print_buffer(content, sh_tbl[i].sh_size, address);
		}
	}
}
