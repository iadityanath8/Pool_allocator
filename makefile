CC = cc
CFlags = -Wall -Wextra -Wnonnull -pedantic 


run:
	$(CC) $(CFlags) -o mem mem.c && ./mem

comp:
	$(CC) $(CFlags) -o mem mem.c

clean:
	rm -rf ./mem
