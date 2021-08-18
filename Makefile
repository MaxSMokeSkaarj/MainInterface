GPP=g++
CLANGPP=clang++
FLG=-o main
SRC=main.cpp calc.cpp keygen.cpp conv.cpp modules.cpp
gcc: $(SRC)
	$(GPP) $(FLG) $(SRC)
clang: $(SRC)
	$(CLANGPP) $(FLG) $(SRC)
