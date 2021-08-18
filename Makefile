CPP=g++
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
OBJ=$(SRC:.cpp=.o)
CFLAGSRLS=-O2 -s -flto
CFLAGSDBG=-Og -g
LDFLAGS=
EXEC=MI
all: $(SRC) $(EXEC)
$(EXEC): $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $@
RLSOBJ:
	$(CPP) $(CFLAGSRLS) $< -o $@
DBGOBJ:
	$(CPP) $(CFLAGSDBG) $< -o $@