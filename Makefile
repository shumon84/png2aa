CC   = gcc
RM   = rm -rf
MAKE = make

CFLAGS = -Wall -O3
COPTS  = -D_DEBUG_ 
LDFLAGS = -lpng -ljpeg

PROGRAM = png2aa
OBJ_DIR = obj
DEPEND_FILE = $(PROGRAM).dpd
SRCS = $(wildcard *.c)
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

.PHONY: all clean
all: $(PROGRAM)

$(PROGRAM): $(OBJ_DIR) $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(PROGRAM)
	$(RM) $(DEPEND_FILE)
	$(RM) $(OBJ_DIR)

$(OBJS): Makefile 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: depend
depend: $(DEPEND_FILE)
$(DEPEND_FILE):
	$(CC) -MM $(SRCS) | sed -e 's/^/$(OBJ_DIR)\//g' > $(DEPEND_FILE)

-include $(DEPEND_FILE)
