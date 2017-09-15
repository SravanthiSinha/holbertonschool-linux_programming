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
