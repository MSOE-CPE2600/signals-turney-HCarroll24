CFLAGS=-c -g -Wall -Werror
CC=gcc

all: signal_handler signal_alarm signal_segfault

signal_handler: signal_handler.o
	$(CC) -o signal_handler signal_handler.o

signal_alarm: signal_alarm.o
	$(CC) -o signal_alarm signal_alarm.o

signal_segfault: signal_segfault.o
	$(CC) -o signal_segfault signal_segfault.o

clean:
	rm -f *.o signal_handler
	rm -f *.o signal_alarm
	rm -f *.o signal_research

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

