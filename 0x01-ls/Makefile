CC 	= 	gcc-4.8
CFLAGS 	= 	-Wall -Werror -Wextra -pedantic -std=C90
CFLAGS 	=
_SRC 	= 				main.c list.c list_utils.c utils.c print_files.c	dirwalk.c\
								direntry.c direntry_utils.c print_error.c options.c\
								sort_direntry.c sort_list.c options.c
SRC 	= 	$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ 	= 	$(_SRC:.c=.o)
OBJECTS 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS 	= 	hls.h list.h direntry.h options.h
DEPS 	= 	$(patsubst %,$(IDIR)/%,$(_DEPS))

IDIR 	= 	./inc
SDIR 	= 	./src
ODIR 	= 	./obj
OUTPUT 	= 	hls

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

all : $(OUTPUT)

$(OUTPUT) : $(OBJECTS)
	$(CC) -o $@ $^ $(LINKS)

.PHONY : clean

clean :
	rm -f $(OUTPUT) $(OBJECTS)

re: $(OBJ)
