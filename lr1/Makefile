OUTPUT = lr1.bin

CC = gcc
CFLAGS = -g -std=c99

OBJS = main.o struct.o app.o

all: $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${OUTPUT}

clean:
	rm -f *.o ${OUTPUT}

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
