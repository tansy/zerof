# zerof Makefile
# $ make -f makefile

CC      = gcc
CFLAGS  = -O2 $(WARNINGS)

SRCS    = zerof.c
OBJS    = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

TARGET  = zerof

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $+ $(LIBS)

clean:
	rm -rf *.o $(TARGET)

