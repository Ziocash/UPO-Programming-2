CFLAGS+=-Wall -Wextra -std=c11 -pedantic -g -I"$(PWD)/include"

export CFLAGS

.PHONY: all apps bin clean doc test

all: bin test apps

bin:
	cd bin && $(MAKE) all

apps: bin
	cd apps && $(MAKE) all

test: bin
	cd test && $(MAKE) all

clean:
	cd bin && $(MAKE) clean
	cd apps && $(MAKE) clean
	cd test && $(MAKE) clean