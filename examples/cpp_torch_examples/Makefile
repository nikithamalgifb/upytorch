MPTOP = ../../micropython
ITOP = ../../interpreter-manager
LIBP = ../../lib
CC = gcc
CXX = g++
CPPFLAGS = -I. -I$(MPTOP) -I$(ITOP) -I$(MPTOP)/ports/unix -I./build/ -I./build/genhdr -lstdc++ -fpermissive -g -DNO_QSTR
LDFLAGS = -L. -fpermissive

hello-embed: -lmicropython hello-embed.o $(ITOP)/interpreterManager.o

hello-embed.o: -lmicropython __main.o

__main.o: -lmicropython


-lmicropython:
	$(MAKE) -f ./Makefile.upylib MPTOP=$(MPTOP)

clean:
	rm -rf *.o *.a build ./lib hello-embed examples $(ITOP)/*.o $(LIBP)/*.o
