TARGET = train
CC = cc
CFLAGS = -g
SRC = main.c menu.c hex.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

.c.o:
	$(CC) -c $(CFLAGS) $<

main.o: menu.h

menu.o: menu.h quiz.h

hex.o: quiz.h

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o
