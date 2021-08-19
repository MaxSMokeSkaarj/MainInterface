CPP:=g++
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
CFLAGS=-O2 -s -flto -c
CFLAGSDBG=-Og -g -c
LDFLAGS:=
release: MI.o
	$(CPP) $(LDFLAGS) MI.o -o MI
debug: MIdbg.o
	$(CPP) $(LDFLAG) MIdbg.o -o MIdbg
.o: $(SRC)
	$(CPP) $(CFLAGS) $(SRC) -o MI.o
dbg.o: $(SRC)
	$(CPP) $(CFLAGSDBG) $(SRC) -o MIdbg.o
clean:
	rm -rf *.o release debug