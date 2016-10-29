CPPFLAGS=-Wall -Wextra -pedantic -std=c99 -o mastermind
CFLAGS=-Wstack-usage=1024 
LDFLAGS=-lpthread

all:
	$(CC) $(CPPFLAGS) mastermind.c $(LDFLAGS)


clean:
	rm -f ./mastermind
