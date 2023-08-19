LDFLAGS+=-L../bin
LDLIBS=-lcompiled -lm
test_targets=

export LDFLAGS
export LDLIBS
export test_targets

include mk/*.mk


.PHONY: all clean

all: $(test_targets)

clean:
	$(RM) $(test_targets) *.o