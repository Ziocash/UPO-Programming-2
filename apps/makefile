LDFLAGS+=-L../bin
LDLIBS=-lcompiled -lm
apps_targets=

export LDFLAGS
export LDLIBS
export apps_targets

include mk/*.mk

.PHONY: all clean

all: $(apps_targets)

clean:
	$(RM) $(apps_targets) *.o