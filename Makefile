CPP=g++
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
OBJ=$(SRC:.cpp=.o)
CFLAGSRLS=-O2 -s -flto
CFLAGSDBG=-Og -g
LDFLAGS=
RELEASE: $(OBJ) $(RLSOBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
DEBUG: $(OBJ) $(DBGOBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
RLSOBJ:
	$(CPP) $(CFLAGSRLS) $< -o $@
DBGOBJ:
	$(CPP) $(CFLAGSDBG) $< -o $@