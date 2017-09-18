CC 	= 	gcc-4.8
CFLAGS 	= 	-Wall -Werror -Wextra -pedantic -g

_SRC 	= 	nm.c \
		validate_elf.c \
		elf_utils.c \
		elf_utils1.c \
		elf_utils2.c \
		helper.c \
		process_elf_header.c \
		print_buffer.c \
		process_elf_section_header.c \
		process_elf_symbol_tables.c

_SRC1 	= 	objdump.c \
		validate_elf.c \
		elf_utils.c \
		elf_utils1.c \
		elf_utils2.c \
		helper.c \
		process_elf_header.c \
		print_buffer.c \
		process_elf_section_header.c


SRC 	= 	$(patsubst %,$(SDIR)/%,$(_SRC))

SRC1 	= 	$(patsubst %,$(SDIR)/%,$(_SRC1))

_OBJ 	= 	$(_SRC:.c=.o)
OBJECTS 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ1 	= 	$(_SRC1:.c=.o)
OBJECTS1 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ1))

IDIR 	= 	./inc
SDIR 	= 	./src
ODIR 	= 	.

OUTPUT 	= 	hnm
OUTPUT1 	= 	hobjdump

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

all : $(OUTPUT) $(OUTPUT1)

$(OUTPUT) : $(OBJECTS)
	$(CC) -o $@ $^ $(LINKS)

$(OUTPUT1) : $(OBJECTS1)
	$(CC) -o $@ $^ $(LINKS)

.PHONY : clean

clean :
	rm -f $(OUTPUT) $(OBJECTS) $(OUTPUT1) $(OBJECTS1)

re: $(OBJ) $(OBJ1)
