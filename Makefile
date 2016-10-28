CPPFLAGS=-Wall -Wextra -pedantic -o mastermind


all:
	$(CC) $(CPPFLAGS) mastermind.c -lpthread


clean:
	rm -f ./mastermind
