CPP=g++
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
OBJ=$(SRC:.cpp=.o)
OBJDBG=$(SRC:.cpp=dbg.o)
CFLAGS=-O2 -s -flto
CFLAGSDBG=-Og -g
LDFLAGS=
release: $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
debug: $(OBJDBG)
	$(CPP) $(LDFLAG) $(OBJDBG) -o $@
releaseObjects: $(SRC)
	$(CPP) $(CFLAGS) $< -o $@
debugObjects: $(SRC)
	$(CPP) $(CFLAGSDBG) $< -o $@
clean:
	rm -rf *.o release debug