MPTOP = ../../micropython
ITOP = ../../interpreter-manager
LIBP = ../../lib
CC = g++
CPPFLAGS = -std=c++14 -I. -I$(MPTOP) -I$(ITOP) -DNO_QSTR -lstdc++
LDFLAGS = -L.

hello-embed: hello-embed.o $(ITOP)/interpreterManager.o -lmicropython

-lmicropython:
	$(MAKE) -f ./Makefile.upylib MPTOP=$(MPTOP)

clean:
	rm -rf *.o *.a build ../lib hello-embed examples $(ITOP)/*.o $(LIBP)/*.o
