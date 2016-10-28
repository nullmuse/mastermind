CPPFLAGS=-Wall -Wextra -Wstack-usage=1024 -pedantic -o mastermind
LDFLAGS=-lpthread

all:
	$(CC) $(CPPFLAGS) mastermind.c $(LDFLAGS)


clean:
	rm -f ./mastermind
