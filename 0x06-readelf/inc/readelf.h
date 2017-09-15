#ifndef _READELF_H
#define _READELF_H

#include <assert.h>
#include <elf.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <linux/limits.h>

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

/**
 * struct shdr - Struct to represent section headers from both 32 and 64bits
 * @sh_name : offset to a string in the .shstrtab section that represents the
 * name of this section
 * @sh_type : Identifies the type of this header.
 * @sh_flags : Identifies the attributes of the section.
 * @sh_addr: Virtual address of the section in memory, for sections that are
 * loaded.
 * @sh_offset: Offset of the section in the file image.
 * @sh_size: Size in bytes of the section in the file image. May be 0.
 * @sh_link: Contains the section index of an associated section.
 * @sh_info:  Contains extra information about the section.
 * @sh_addralign:  Contains the required alignment of the section.
 * @sh_entsize:  Contains the size, in bytes, of each entry, for sections that
 * contain fixed-size entries
 */
typedef struct shdr
{
	uint32_t sh_name;
	uint32_t sh_type;
	uint64_t sh_flags;
	uint64_t sh_addr;
	uint64_t sh_offset;
	uint64_t sh_size;
	uint32_t sh_link;
	uint32_t sh_info;
	uint64_t sh_addralign;
	uint64_t sh_entsize;
} ElfN_Shdr;

/**
 * struct phdr - Struct to represent program headers from both 32 and 64bits
 * @p_type :  Identifies program segment type
 * @p_offset : Segment file offset
 * @p_vaddr : Segment virtual address
 * @p_paddr : Segment physical address
 * @p_filesz : Segment size in file
 * @p_memsz : Segment size in memory
 * @p_flags : Segment flags
 * @p_align : Segment alignment, file & memory
 */
typedef struct phdr
{
	uint32_t p_type;
	uint32_t p_offset;
	uint64_t p_vaddr;
	uint64_t p_paddr;
	uint64_t p_filesz;
	uint64_t p_memsz;
	uint64_t p_flags;
	uint64_t p_align;
} ElfN_Phdr;

/**
 * struct symtab-  Symbol table entry
 * @st_name : Symbol name, index in string tbl
 * @st_info : Type and binding attributes
 * @st_other :  No defined meaning, 0
 * @st_shndx : Associated section index
 * @st_value : Value of the symbol
 * @st_size : Associated symbol size
 */
typedef struct symtab
{
	uint64_t st_name;
	unsigned char st_info;
	unsigned char st_other;
	uint16_t st_shndx;
	uint64_t st_value;
	uint64_t st_size;
} ElfN_Sym;

#define SHF_X86_64_LARGE 0x10000000
#define GET_BYTE(field) get_byte(field, sizeof(field))
#define E "Error: Not an ELF file - it has the wrong magic bytes at the start"
#define ELF_ST_BIND(x)		((x) >> 4)
#define ELF_ST_TYPE(x)		(((unsigned int) x) & 0xf)
#define ELF_SECTION_SIZE(sec_hdr, segment)			\
	(((sec_hdr.sh_flags & SHF_TLS) == 0			\
	  || sec_hdr.sh_type != SHT_NOBITS			\
	  || segment.p_type == PT_TLS) ? sec_hdr.sh_size : 0)

#define ELF_IS_SECTION_IN_SEGMENT(sec_hdr, segment)			\
	(((((sec_hdr.sh_flags & SHF_TLS) != 0)				\
	   && (segment.p_type == PT_TLS					\
	       || segment.p_type == PT_LOAD))				\
	  || ((sec_hdr.sh_flags & SHF_TLS) == 0				\
	      && segment.p_type != PT_TLS))				\
	 && (sec_hdr.sh_type == SHT_NOBITS				\
	     || ((uint64_t) sec_hdr.sh_offset >= segment.p_offset	\
		 && (sec_hdr.sh_offset + ELF_SECTION_SIZE(sec_hdr, segment) \
		     <= segment.p_offset + segment.p_filesz)))		\
	 && ((sec_hdr.sh_flags & SHF_ALLOC) == 0			\
	     || (sec_hdr.sh_addr >= segment.p_vaddr			\
		 && (sec_hdr.sh_addr + ELF_SECTION_SIZE(sec_hdr, segment) \
		     <= segment.p_vaddr + segment.p_memsz))))

bool elf_check_file(unsigned char *magic);
bool get_architecture(char c, int *arch);

char *get_machine_name(unsigned int e_machine);
char *get_file_type(unsigned int e_type);
char *get_osabi_name(unsigned int osabi);
char *get_elf_version(unsigned int version);
char *get_data_encoding(unsigned int encoding);
char *get_elf_class(unsigned int elf_class);
char *get_section_type_name(unsigned int sh_type);
char *get_elf_section_flags(ElfN_Ehdr elf_header, unsigned long sh_flags);
char *get_segment_type(unsigned long p_type);
char *get_symbol_binding(unsigned int binding);
char *get_symbol_type(unsigned int type);
char *get_symbol_visibility(unsigned int visibility);
char *get_symbol_index_type(unsigned int type);

char *get_vma(unsigned int no, char format, char end);
uint64_t get_byte_big_endian(uint64_t data, int size);
uint64_t get_byte_host(uint64_t data, int __attribute__ ((unused)) size);

void read_elf_header_32(ElfN_Ehdr *ehdr, FILE *file);
void read_elf_header_64(ElfN_Ehdr *ehdr, FILE *file);
void read_elf_header(ElfN_Ehdr ehdr, Entry entries[]);

void read_elf_section_header_N(ElfN_Ehdr *ehdr, FILE *file, int arch);
void read_elf_section_header_32(ElfN_Ehdr eh, ElfN_Shdr *shdr_tbl, int fd);
void read_elf_section_header_64(ElfN_Ehdr eh, ElfN_Shdr *shdr_tbl, int fd);
char *read_section(int fd, ElfN_Shdr sh);

void read_elf_program_header_N(ElfN_Ehdr *ehdr, FILE *file, int arch);
void read_elf_program_header_32(ElfN_Ehdr eh, ElfN_Phdr *phdr_tbl, int fd);
void read_elf_program_header_64(ElfN_Ehdr eh, ElfN_Phdr *phdr_tbl, int fd);

void read_elf_symbol_table_N(ElfN_Ehdr *ehdr, FILE *file, int arch);

void print_elf_header(ElfN_Ehdr ehdr);
void print_elf_section_header(ElfN_Shdr *shdr_tbl, ElfN_Ehdr eh, int fd);
void print_elf_program_header(ElfN_Phdr ph_tbl[], ElfN_Shdr sh_tbl[],
			      ElfN_Ehdr ehdr, FILE *file);
void print_elf_symbol_table(ElfN_Shdr sh_tbl[], ElfN_Sym sym_tbl[],
			    ElfN_Ehdr ehdr, int sym_tbl_indx, uint64_t count,
			    int fd);
#endif
