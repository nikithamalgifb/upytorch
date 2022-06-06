MPTOP = ../micropython
CC = g++
CPPFLAGS = -std=c++14 -I. -I$(MPTOP) -DNO_QSTR -lstdc++
LDFLAGS = -L.

hello-embed: hello-embed.o interpreterManager.o -lmicropython

-lmicropython:
	$(MAKE) -f ./Makefile.upylib MPTOP=$(MPTOP)

clean:
	rm -rf *.o *.a build hello-embed
