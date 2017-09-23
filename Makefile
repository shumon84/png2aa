PROGRAM = png2aa
EXTENSION = c
CC   = gcc
LDFLAGS = -lpng -ljpeg
CFLAGS = -Wall -O3
COPTS  = -D_DEBUG_ 

RM   = rm -rf
MAKE = make

SRCS = $(wildcard *.$(EXTENSION))
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.$(EXTENSION)=%.o))
DEPEND_FILE = $(PROGRAM).dpd

$(PROGRAM): $(OBJ_DIR) $(OBJS) TAGS
	$(CC) -o $(PROGRAM) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(OBJS): Makefile

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.$(EXTENSION)
	$(CC) $(CFLAGS) -c $< -o $@

TAGS: $(SRC)
	find . -name "*.$(EXTENSION)" | etags -

.PHONY: all clean depend tags

all: $(PROGRAM)

clean:
	$(RM) $(PROGRAM)
	$(RM) $(DEPEND_FILE)
	$(RM) $(OBJ_DIR)
	$(RM) TAGS

depend: $(DEPEND_FILE)
$(DEPEND_FILE):
	$(CC) -MM $(SRCS) | sed -e 's/^/$(OBJ_DIR)\//g' > $(DEPEND_FILE)

-include $(DEPEND_FILE)
