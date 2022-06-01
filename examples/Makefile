MPTOP = ../micropython
CFLAGS = -std=c99 -I. -I$(MPTOP) -DNO_QSTR
LDFLAGS = -L.

hello-embed: hello-embed.o -lmicropython

-lmicropython:
	$(MAKE) -f ./Makefile.upylib MPTOP=$(MPTOP)

clean:
	rm -rf *.o *.a build
