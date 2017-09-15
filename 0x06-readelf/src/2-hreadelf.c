#include "readelf.h"

/**
 * main - A program that takes the name of a elf file as a parameter and
 * displays the information contained in the program header of an ELF file.
 * @argc: no of inputs.
 * @argv: inputs.
 *
 * Return: on success:  0 , on Failure: 1.
 */
int main(int argc, char *argv[])
{
	ElfN_Ehdr ehdr;
	int exit_status = 0, arch = 0;
	FILE *file;

	/* validate user input */
	if (argc < 2)
	{
		printf("Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}
	/* open the elf file */
	file = fopen(argv[1], "rb");
	if (file)
	{
		if (fread(ehdr.e_ident, EI_NIDENT, 1, file) &&
		    elf_check_file(ehdr.e_ident))
		{
			get_architecture(ehdr.e_ident[EI_CLASS], &arch);
			read_elf_program_header_N(&ehdr, file, arch);
		} else
			printf("%s: %s\n", E, argv[0]);
		exit_status = 1;
		/*
		 * finally close the file
		 */
		fclose(file);
	} else
	{
		printf("%s: Error: '%s': No such file\n", argv[0], argv[1]);
		exit_status = 1;
	}
	return (exit_status);
}
