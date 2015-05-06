TARGET = run
CC = gcc
CFLAGS = -g
OBJDIR = obj

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

$(OBJECTS) : | $(OBJDIR)

$(OBJDIR):
		  mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(HEADERS)
		  $(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
		  $(CC) $(OBJECTS) -Wall -w -o $@

clean:
		  -rm -f $(OBJDIR)/*.o
		  -rm -f $(TARGET)
		  -rmdir $(OBJDIR)