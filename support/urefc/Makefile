include ../../config.mk

CC := riscv64-unknown-elf-gcc

TARGET = libidris2_urefc

LIBTARGET = $(TARGET).a

SRCS := $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

CFLAGS += -O2

ifeq ($(OLD_WIN), 1)
	CPPFLAGS += -D_OLD_WIN
endif


.PHONY: all
all: build

.PHONY: build
build: $(LIBTARGET)

$(LIBTARGET): $(OBJS)
	$(AR) rc $@ $^
	$(RANLIB) $@

-include $(DEPS)

%.d: %.c
	@$(CPP) $(CPPFLAGS) $< -MM -MT $(@:.d=.o) >$@


.PHONY: clean
clean:
	$(RM) $(OBJS) $(LIBTARGET)

.PHONY: cleandep
cleandep: clean
	$(RM) $(DEPS)


.PHONY: install
install: build
	mkdir -p ${DESTDIR}${PREFIX}/idris2-${IDRIS2_VERSION}/support/urefc
	install -m 644 $(LIBTARGET) *.h ${DESTDIR}${PREFIX}/idris2-${IDRIS2_VERSION}/support/urefc
