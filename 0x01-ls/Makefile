CC 	= 	gcc-4.8
CFLAGS 	= 	-Wall -Werror -Wextra -pedantic

_SRC 	= 				main.c execute.c hashtable_io.c filelist_io.c
SRC 	= 	$(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ 	= 	$(_SRC:.c=.o)
OBJECTS 	= 	$(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS 	= 	hls.h hashtable.h filelist.h
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
