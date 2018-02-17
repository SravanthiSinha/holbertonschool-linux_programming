# CC 	= 	gcc-4.8
# CFLAGS 	= 	-Wall -Werror -Wextra -pedantic -g

_SRC 	= 	strace_0.c

SRC 	= 	$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ 	= 	$(_SRC:.c=.o)
OBJECTS 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC1 	= 	strace_1.c

SRC1 	= 	$(patsubst %,$(SDIR)/%,$(_SRC1))

_OBJ1 	= 	$(_SRC1:.c=.o)
OBJECTS1 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ1))

_DEPS 	=	strace.h
DEPS 	= 	$(patsubst %,$(IDIR)/%,$(_DEPS))

IDIR 	= 	./inc
SDIR 	= 	./src
ODIR 	= 	.

OUTPUT 	= 	strace_0
OUTPUT1 	= 	strace_1

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
