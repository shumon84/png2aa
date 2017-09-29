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

.PHONY: all
all: tags $(PROGRAM)

$(PROGRAM): $(OBJ_DIR) $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(OBJS): Makefile

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.$(EXTENSION)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(PROGRAM)
	$(RM) $(DEPEND_FILE)
	$(RM) $(OBJ_DIR)
	$(RM) TAGS

.PHONY: depend
depend: $(DEPEND_FILE)
$(DEPEND_FILE):
	$(CC) -MM $(SRCS) | sed -e 's/^/$(OBJ_DIR)\//g' > $(DEPEND_FILE)

-include $(DEPEND_FILE)

.PHONY: tags
tags: $(SRC)
	find . -name "*.$(EXTENSION)" | etags -
