CC=clang
CFLAGS=-Wall -g
BINS=main

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -r $(BINS) *.dSYM
