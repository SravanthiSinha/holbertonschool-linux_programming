#include "readelf.h"

/**
 * read_elf_header_32 -  fills the ehdr with suitable(32) architecture data
 * @ehdr: elf header structure
 * @file: input file
 */
void read_elf_header_32(ElfN_Ehdr *ehdr, FILE *file)
{
	ssize_t n;
	Elf32_Ehdr ehdr32;
	uint64_t (*get_byte)(uint64_t, int);

	get_byte = (ehdr->e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian
	    : get_byte_host;
	n = fread(&ehdr32.e_type, sizeof(ehdr32) - EI_NIDENT, 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);

	ehdr->e_type = GET_BYTE(ehdr32.e_type);
	ehdr->e_machine = GET_BYTE(ehdr32.e_machine);
	ehdr->e_version = GET_BYTE(ehdr32.e_version);
	ehdr->e_entry = GET_BYTE(ehdr32.e_entry);
	ehdr->e_phoff = GET_BYTE(ehdr32.e_phoff);
	ehdr->e_shoff = GET_BYTE(ehdr32.e_shoff);
	ehdr->e_flags = GET_BYTE(ehdr32.e_flags);
	ehdr->e_ehsize = GET_BYTE(ehdr32.e_ehsize);
	ehdr->e_phentsize = GET_BYTE(ehdr32.e_phentsize);
	ehdr->e_phnum = GET_BYTE(ehdr32.e_phnum);
	ehdr->e_shentsize = GET_BYTE(ehdr32.e_shentsize);
	ehdr->e_shnum = GET_BYTE(ehdr32.e_shnum);
	ehdr->e_shstrndx = GET_BYTE(ehdr32.e_shstrndx);
}

/**
 * read_elf_header_64 -  fills the ehdr with suitable(64) architecture data
 * @ehdr: elf header structure
 * @file: input file
 */
void read_elf_header_64(ElfN_Ehdr *ehdr, FILE *file)
{
	uint64_t (*get_byte)(uint64_t, int);
	ssize_t n;
	Elf64_Ehdr ehdr64;

	get_byte = (ehdr->e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian
	    : get_byte_host;
	n = fread(&ehdr64.e_type, sizeof(ehdr64) - EI_NIDENT, 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);

	ehdr->e_type = GET_BYTE(ehdr64.e_type);
	ehdr->e_machine = GET_BYTE(ehdr64.e_machine);
	ehdr->e_version = GET_BYTE(ehdr64.e_version);
	ehdr->e_entry = GET_BYTE(ehdr64.e_entry);
	ehdr->e_phoff = GET_BYTE(ehdr64.e_phoff);
	ehdr->e_shoff = GET_BYTE(ehdr64.e_shoff);
	ehdr->e_flags = GET_BYTE(ehdr64.e_flags);
	ehdr->e_ehsize = GET_BYTE(ehdr64.e_ehsize);
	ehdr->e_phentsize = GET_BYTE(ehdr64.e_phentsize);
	ehdr->e_phnum = GET_BYTE(ehdr64.e_phnum);
	ehdr->e_shentsize = GET_BYTE(ehdr64.e_shentsize);
	ehdr->e_shnum = GET_BYTE(ehdr64.e_shnum);
	ehdr->e_shstrndx = GET_BYTE(ehdr64.e_shstrndx);
}
