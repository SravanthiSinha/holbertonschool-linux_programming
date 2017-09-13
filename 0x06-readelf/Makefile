CC 	= 	gcc-4.8
CFLAGS 	= 	-Wall -Werror -Wextra -pedantic -g

_SRC 	= 	0-hreadelf.c \
		validate_elf.c \
		elf_utils.c \
		elf_utils2.c \
		read_elf_header.c \
		read_elf_section_header.c \
		print.c

_SRC1 	= 	1-hreadelf.c \
			validate_elf.c \
			elf_utils.c \
			elf_utils2.c \
			read_elf_header.c \
			read_elf_section_header.c \
			print.c

SRC 	= 	$(patsubst %,$(SDIR)/%,$(_SRC))

SRC1 	= 	$(patsubst %,$(SDIR)/%,$(_SRC1))

_OBJ 	= 	$(_SRC:.c=.o)
OBJECTS 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ1 	= 	$(_SRC1:.c=.o)
OBJECTS1 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ1))

_DEPS 	=	readelf.h
DEPS 	= 	$(patsubst %,$(IDIR)/%,$(_DEPS))

IDIR 	= 	./inc
SDIR 	= 	./src
ODIR 	= 	.
OUTPUT 	= 	0-hreadelf
OUTPUT1 	= 	1-hreadelf

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

all : $(OUTPUT1) $(OUTPUT)

$(OUTPUT) : $(OBJECTS)
	$(CC) -o $@ $^ $(LINKS)

$(OUTPUT1) : $(OBJECTS1)
	$(CC) -o $@ $^ $(LINKS)

.PHONY : clean

clean :
	rm -f $(OUTPUT) $(OUTPUT1) $(OBJECTS) $(OBJECTS1)

re: $(OBJ) $(OBJ1)
