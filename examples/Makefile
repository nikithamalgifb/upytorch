MPTOP = ../micropython
# ITOP = .
CFLAGS = -std=c99 -I. -I$(MPTOP) -DNO_QSTR
CPPFLAGS = -std=c++14 -I$(MPTOP) -I. -I./build -DNO_QSTR
LDFLAGS = -L.

hello-embed: hello-embed.o -lmicropython

-lmicropython:
	$(MAKE) -f ./Makefile.upylib MPTOP=$(MPTOP)

# interpreterManager.o:
# 	g++ -Wall -g -I../micropython -I. -I./build -c $(ITOP)/interpreterManager.cpp


clean:
	rm -rf *.o *.a build
