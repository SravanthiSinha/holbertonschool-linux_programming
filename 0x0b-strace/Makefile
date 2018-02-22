CC 	= 	gcc-4.8
CFLAGS 	= 	-Wall -Werror -Wextra -pedantic -g

_SRC 	= 	strace_0.c

SRC 	= 	$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ 	= 	$(_SRC:.c=.o)
OBJECTS 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC1 	= 	strace_1.c

SRC1 	= 	$(patsubst %,$(SDIR)/%,$(_SRC1))

_OBJ1 	= 	$(_SRC1:.c=.o)
OBJECTS1 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ1))

_SRC2 	= 	strace_2.c \
						utils.c

SRC2 	= 	$(patsubst %,$(SDIR)/%,$(_SRC2))

_OBJ2 	= 	$(_SRC2:.c=.o)
OBJECTS2 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ2))

_SRC3 	= 	strace_3.c	\
						utils.c

SRC3 	= 	$(patsubst %,$(SDIR)/%,$(_SRC3))

_OBJ3 	= 	$(_SRC3:.c=.o)
OBJECTS3 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ3))

_SRC4 	= 	strace_4.c	\
						utils.c

SRC4 	= 	$(patsubst %,$(SDIR)/%,$(_SRC4))

_OBJ4 	= 	$(_SRC4:.c=.o)
OBJECTS4 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ4))

_SRC5 	= 	strace_5.c	\
						utils.c

SRC5 	= 	$(patsubst %,$(SDIR)/%,$(_SRC5))

_OBJ5 	= 	$(_SRC5:.c=.o)
OBJECTS5 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ5))

_SRC6 	= 	strace_6.c	\
						utils.c	\
						handle_syscall_macros.c						

SRC6 	= 	$(patsubst %,$(SDIR)/%,$(_SRC6))

_OBJ6 	= 	$(_SRC6:.c=.o)
OBJECTS6 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ6))

_DEPS 	=	strace.h
DEPS 	= 	$(patsubst %,$(IDIR)/%,$(_DEPS))

IDIR 	= 	./inc
SDIR 	= 	./src
ODIR 	= 	.

OUTPUT 	= 	strace_0
OUTPUT1 	= 	strace_1
OUTPUT2 	= 	strace_2
OUTPUT3 	= 	strace_3
OUTPUT4 	= 	strace_4
OUTPUT5 	= 	strace_5
OUTPUT6 	= 	strace_6

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

all : $(OUTPUT) $(OUTPUT1) $(OUTPUT2) $(OUTPUT3) $(OUTPUT4) $(OUTPUT5) $(OUTPUT6)

$(OUTPUT) : $(OBJECTS)
	$(CC) -o $@ $^ $(LINKS)

$(OUTPUT1) : $(OBJECTS1)
	$(CC) -o $@ $^ $(LINKS)

$(OUTPUT2) : $(OBJECTS2)
	$(CC) -o $@ $^ $(LINKS)

$(OUTPUT3) : $(OBJECTS3)
	$(CC) -o $@ $^ $(LINKS)

$(OUTPUT4) : $(OBJECTS4)
	$(CC) -o $@ $^ $(LINKS)

$(OUTPUT5) : $(OBJECTS5)
	$(CC) -o $@ $^ $(LINKS)

$(OUTPUT6) : $(OBJECTS6)
	$(CC) -o $@ $^ $(LINKS)

.PHONY : clean

clean :
	rm -f $(OUTPUT) $(OBJECTS) $(OUTPUT1) $(OBJECTS1) $(OUTPUT2) $(OBJECTS2) $(OUTPUT3) $(OBJECTS3) $(OUTPUT4) $(OBJECTS4) $(OUTPUT5) $(OBJECTS5) $(OUTPUT6) $(OBJECTS6)

re: $(OBJ) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
