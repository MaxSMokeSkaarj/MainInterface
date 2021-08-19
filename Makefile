CPP=g++
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
OBJ=$(SRC:.cpp=.o)
OBJDBG=$(SRC:.cpp=dbg.o)
CFLAGS=-O2 -s -flto -c
CFLAGSDBG=-Og -g -c
LDFLAGS=
release: $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
debug: $(OBJDBG)
	$(CPP) $(LDFLAG) $(OBJDBG) -o $@
.o: $(SRC)
	$(CPP) $(CFLAGS) $< -o $<$@
dbg.o: $(SRC)
	$(CPP) $(CFLAGSDBG) $< -o $<$@
clean:
	rm -rf *.o release debug