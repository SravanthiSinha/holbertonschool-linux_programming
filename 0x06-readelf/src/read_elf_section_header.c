#include "readelf.h"

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
 * read_elf_section_header_32- fills the sh with suitable(32)
 * architecture data
 * @sh_tbl: section header table
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 */
void read_elf_section_header_32(ElfN_Ehdr ehdr, ElfN_Shdr *sh_tbl, int fd)
{
	uint64_t (*get_byte)(uint64_t, int), i;

	Elf32_Shdr *shdr32_tbl;

	get_byte = (ehdr.e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian
	    : get_byte_host;

	shdr32_tbl = malloc(ehdr.e_shentsize * ehdr.e_shnum);
	if (!shdr32_tbl)
		printf("Failed to allocate section header table\n");
	assert(lseek(fd, (off_t) ehdr.e_shoff, SEEK_SET) == (off_t) ehdr.e_shoff);

	for (i = 0; i < ehdr.e_shnum; i++)
	{
		assert(read(fd, (void *)&shdr32_tbl[i], ehdr.e_shentsize) ==
		       ehdr.e_shentsize);

		sh_tbl[i].sh_name = GET_BYTE(shdr32_tbl[i].sh_name);
		sh_tbl[i].sh_type = GET_BYTE(shdr32_tbl[i].sh_type);
		sh_tbl[i].sh_flags = GET_BYTE(shdr32_tbl[i].sh_flags);
		sh_tbl[i].sh_addr = GET_BYTE(shdr32_tbl[i].sh_addr);
		sh_tbl[i].sh_offset = GET_BYTE(shdr32_tbl[i].sh_offset);
		sh_tbl[i].sh_size = GET_BYTE(shdr32_tbl[i].sh_size);
		sh_tbl[i].sh_link = GET_BYTE(shdr32_tbl[i].sh_link);
		sh_tbl[i].sh_info = GET_BYTE(shdr32_tbl[i].sh_info);
		sh_tbl[i].sh_addralign = GET_BYTE(shdr32_tbl[i].sh_addralign);
		sh_tbl[i].sh_entsize = GET_BYTE(shdr32_tbl[i].sh_entsize);
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
	Elf64_Shdr *shdr64_tbl;

	get_byte = (ehdr.e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian
	    : get_byte_host;

	shdr64_tbl = malloc(ehdr.e_shentsize * ehdr.e_shnum);
	if (!shdr64_tbl)
		printf("Failed to allocate section header table\n");
	assert(lseek(fd, (off_t) ehdr.e_shoff, SEEK_SET) == (off_t) ehdr.e_shoff);

	for (i = 0; i < ehdr.e_shnum; i++)
	{
		assert(read(fd, (void *)&shdr64_tbl[i], ehdr.e_shentsize) ==
		       ehdr.e_shentsize);

		sh_tbl[i].sh_name = GET_BYTE(shdr64_tbl[i].sh_name);
		sh_tbl[i].sh_type = GET_BYTE(shdr64_tbl[i].sh_type);
		sh_tbl[i].sh_flags = GET_BYTE(shdr64_tbl[i].sh_flags);
		sh_tbl[i].sh_addr = GET_BYTE(shdr64_tbl[i].sh_addr);
		sh_tbl[i].sh_offset = GET_BYTE(shdr64_tbl[i].sh_offset);
		sh_tbl[i].sh_size = GET_BYTE(shdr64_tbl[i].sh_size);
		sh_tbl[i].sh_link = GET_BYTE(shdr64_tbl[i].sh_link);
		sh_tbl[i].sh_info = GET_BYTE(shdr64_tbl[i].sh_info);
		sh_tbl[i].sh_addralign = GET_BYTE(shdr64_tbl[i].sh_addralign);
		sh_tbl[i].sh_entsize = GET_BYTE(shdr64_tbl[i].sh_entsize);
	}
}

/**
 * read_elf_section_header_N -  fills the ehdr with suitable(N) architecture
 * data
 * @ehdr: elf header structure
 * @file: input file
 * @arch: architecture of the elf file
 */
void read_elf_section_header_N(ElfN_Ehdr *ehdr, FILE *file, int arch)
{
	ElfN_Shdr *sh_tbl;

	if (arch == 64)
		read_elf_header_64(ehdr, file);
	else if (arch == 32)
		read_elf_header_32(ehdr, file);
	sh_tbl = malloc(ehdr->e_shentsize * ehdr->e_shnum);
	if (!sh_tbl)
		printf("Failed to allocate section header table\n");
	if (arch == 64)
		read_elf_section_header_64(*ehdr, sh_tbl, fileno(file));
	else if (arch == 32)
		read_elf_section_header_32(*ehdr, sh_tbl, fileno(file));
	print_elf_section_header(sh_tbl, *ehdr, fileno(file));
}
