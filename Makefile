CPP=g++
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
OBJ=$(SRC:.cpp=.o)
CFLAGSRLS=-O2 -s -flto
CFLAGSDBG=-Og -g
LDFLAGS=
release: $(releaseObjects) $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
debug: $(debugObjects) $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
releaseObjects:
	$(CPP) $(CFLAGSRLS) $< -o $@
debugObjects:
	$(CPP) $(CFLAGSDBG) $< -o $@
clean:
	rm -rf *.o release debug