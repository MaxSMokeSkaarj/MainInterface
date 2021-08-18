CPP:=g++
gcc: main-gcc calc-gcc keygen-gcc conv-gcc modules-gcc
	$(GPP) -o mai
clang: $(SRC)
	$(CLANGPP) $(FLG) $(SRC)
