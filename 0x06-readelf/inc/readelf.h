#ifndef _READELF_H
#define _READELF_H

#include <elf.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct Entry - Key and values pair
 * @key : key
 * @value : value
 */
typedef struct Entry
{
	char *key;
	char *value;
} Entry;

/**
 * struct ehdr - Struct to represent headers from both 32 and 64bits files
 * @e_ident : magic number
 * @e_entry : Entry point virtual address
 * @e_phoff : Program header table file offset
 * @e_shoff: Section header table file offset
 * @e_version: Identifies object file version
 * @e_flags: Processor-specific flags
 * @e_type: Identifies object file type
 * @e_machine:  Specifies required architecture
 * @e_ehsize:  ELF header size in bytes
 * @e_phentsize:  Program header table entry size
 * @e_phnum:  Program header table entry count
 * @e_shentsize:  Section header table entry size
 * @e_shnum:  Section header table entry count
 * @e_shstrndx: Section header string table index
 */
typedef struct ehdr
{
	unsigned char e_ident[EI_NIDENT];
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_version;
	uint32_t e_flags;
	uint16_t e_type;
	uint16_t e_machine;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} ElfN_Ehdr;

#define GET_BYTE(field) get_byte(field, sizeof(field))
#define E "Error: Not an ELF file - it has the wrong magic bytes at the start"

bool elf_check_file(unsigned char *magic);
bool get_architecture(char c, int *arch);

char *get_machine_name(unsigned int e_machine);
char *get_file_type(unsigned int e_type);
char *get_osabi_name(unsigned int osabi);
char *get_elf_version(unsigned int version);
char *get_data_encoding(unsigned int encoding);
char *get_elf_class(unsigned int elf_class);

void read_elf_header_32(ElfN_Ehdr *ehdr, FILE *file);
void read_elf_header_64(ElfN_Ehdr *ehdr, FILE *file);

void print_elf_header(ElfN_Ehdr ehdr);
#endif
