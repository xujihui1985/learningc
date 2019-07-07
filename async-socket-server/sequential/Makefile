CC = gcc
CFLAGS = -g -std=gnu99 -Wall -O3
LDFLAGS = -lpthread -pthread

#LDLIBUV = -luv -Wl,-rpath=/usr/local/lib

EXECUTABLES = \
			  sequential-server

all: $(EXECUTABLES)

# $^ means all dependencies (utils.c sequential-server.c)
# $@ means name of target of the rule (sequential-server)
sequential-server: utils.c sequential-server.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

