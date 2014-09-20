INC := inc
OBJ := obj
BIN := bin
SRC := src
EXE := $(BIN)/exe
GCC := g++
SRC_FILES := $(wildcard $(SRC)/*.cpp) 
OBJ_FILES := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRC_FILES))
TEMPLATE_CLASSES := $(INC)/gvector.h
TREE := $(OBJ) $(BIN)

all: $(TREE) $(EXE)

$(TREE):
	mkdir $@

$(EXE): $(OBJ_FILES) $(TEMPLATE_CLASSES)
	$(GCC) $(GCC_ARGS) -I $(INC) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(GCC) $(GCC_ARGS) -I $(INC) -c $< -o $@

clean:
	rm -rf $(TREE)
