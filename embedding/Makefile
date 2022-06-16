MPTOP = ../micropython
ITOP = ../interpreter-manager
LIBP = ../lib
UTOP = ../
CPPFLAGS = -std=c++14 -I. -I$(MPTOP) -I$(ITOP) -DNO_QSTR -lstdc++ -I../wrapper -I../build -I../build/genhdr -I../build/local_lite/libtorch -DNMICROPY_NLR_SETJMP=1 -DMODULE_TORCH_ENABLED=1 -g
LDFLAGS_EXTRA=-L /home/rohanahluwalia/upytorch/build/local_lite/libtorch/../lib -Wl,--gc-sections -Wl,--whole-archive -lc10 -ltorch -ltorch_cpu -Wl,--no-whole-archive -lpthreadpool -lcpuinfo -lclog -lpthread -ldl -lstdc++
CXX = g++

main: main.o interpreterManager.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS_EXTRA) main.o interpreterManager.o ../wrapper/libwrapper.a ../upytorch.a -o main

main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp

interpreterManager.o: $(ITOP)/interpreterManager.cpp $(ITOP)/interpreterManager.h
	$(CXX) $(CPPFLAGS) -c $(ITOP)/interpreterManager.cpp

clean:
	rm -rf *.o *.a build lib main examples $(ITOP)/*.o $(LIBP)/*.o
