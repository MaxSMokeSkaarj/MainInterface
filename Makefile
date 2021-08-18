CPP=g++
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
OBJ=$(SRC:.cpp=.o)
CFLAGSRLS=-O2 -s -flto
CFLAGSDBG=-Og -g
LDFLAGS=
release: $(releaseObjects)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
debug: $(debugObjects)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
releaseObjects: $(OBJ)
	$(CPP) $(CFLAGSRLS) $< -o $@
debugObjects:$(OBJ)
	$(CPP) $(CFLAGSDBG) $< -o $@
clean:
	rm -rf *.o release debug