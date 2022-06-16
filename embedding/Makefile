MPTOP = ../micropython
ITOP = ../interpreter-manager
LIBP = ../lib
UTOP = ../
CPPFLAGS = -std=c++14 -I. -I$(MPTOP) -I$(ITOP) -DNO_QSTR -lstdc++ -I../wrapper -I../build
LDFLAGS = -L.
CXX = g++

main: main.o interpreterManager.o
	$(CXX) $(CPPFLAGS) main.o interpreterManager.o ../wrapper/libwrapper.a upytorch.a -o main

main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp

interpreterManager.o: $(ITOP)/interpreterManager.cpp $(ITOP)/interpreterManager.h
	$(CXX) $(CPPFLAGS) -c $(ITOP)/interpreterManager.cpp

-lmicropython:
	$(MAKE) -f ./Makefile.upylib MPTOP=$(MPTOP)

clean:
	rm -rf *.o *.a build lib main examples $(ITOP)/*.o $(LIBP)/*.o
