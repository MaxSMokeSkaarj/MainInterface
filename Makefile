CPP=g++
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
OBJ=$(SRC:.cpp=.cpp.o)
OBJDBG=$(SRC:.cpp=.cppdbg.o)
CFLAGS=-O2 -s -flto -c
CFLAGSDBG=-Og -g -c
LDFLAGS=
release: $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
debug: $(OBJDBG)
	$(CPP) $(LDFLAG) $(OBJDBG) -o $@
.o: $(SRC)
	$(CPP) $(CFLAGS) $< -o $<.o
dbg.o: $(SRC)
	$(CPP) $(CFLAGSDBG) $< -o $<dbg.o
clean:
	rm -rf *.o release debug