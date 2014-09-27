INC := inc
OBJ := obj
BIN := bin
SRC := src
EXE := $(BIN)/exe
GCC := g++
GCC_ARGS := -Wall -Wextra
SRC_FILES := $(wildcard $(SRC)/*.cpp) 
OBJ_FILES := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRC_FILES))
LIBS := -lglut
TREE := $(OBJ) $(BIN)

all: $(TREE) $(EXE)

$(TREE):
	mkdir $@

$(EXE): $(OBJ_FILES) $(TEMPLATE_CLASSES)
	$(GCC) $(GCC_ARGS) -I $(INC) $^ -o $@ $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp $(DEP)
	$(GCC) -MMD $(GCC_ARGS) -I $(INC) -c $< -o $@

-include $(OBJ)/*.d

clean:
	rm -rf $(TREE)
