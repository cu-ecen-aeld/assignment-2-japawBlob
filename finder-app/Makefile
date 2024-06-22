CC:=gcc
VERBOSE:=1
AT:=@
CROSS_COMPILE:=

ifeq ($(VERBOSE), 0)
	AT=
endif


all:
	$(AT) $(CROSS_COMPILE)$(CC) writer.c -o writer

clean:
	$(AT) rm writer *.o -f

