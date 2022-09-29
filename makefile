NAME_PROGRAM   = final.exe
MAIN_FILE_NAME = main
SRC            = ./src
INCLUDE        = ./include
OBJ            = ./obj
BIN            = ./bin
SAIDA		   = ./Saida
FLAGS          = -lm -pedantic -Wall 
COMPILER       = gcc   

C_FILES        = $(wildcard $(SRC)/*.c)
OBJ_PATH_FILES = $(patsubst $(SRC)%,$(OBJ)%,$(C_FILES))
OBJ_FILES      = $(patsubst %.c,%.o,$(OBJ_PATH_FILES))

all: create_dir $(OBJ_FILES) create_final_progam
start: clean all run

create_final_progam: $(BIN)/$(NAME_PROGRAM)

# rule for main file
$(OBJ)/$(MAIN_FILE_NAME).o: $(SRC)/$(MAIN_FILE_NAME).c
	@ $(COMPILER) -c $< -I $(INCLUDE) -o $@ $(FLAGS)

# rule for all o files
$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	@ $(COMPILER) -c $< -I $(INCLUDE) -o $@ $(FLAGS)

# rule for create_final_progam
$(BIN)/%: 
	@ $(COMPILER) $< $(OBJ)/*.o -I $(INCLUDE) -o $@ $(FLAGS)

# create all needed directories
create_dir: 
	@ mkdir $(OBJ)
	@ mkdir $(BIN)
	@ mkdir $(SAIDA)

# rule to run the final program
run:
	@ ./$(BIN)/$(NAME_PROGRAM) $(r)

valgrind: 
	@ valgrind ./$(BIN)/$(NAME_PROGRAM) $(r)

clean:
	@ rm -rf $(OBJ) $(NAME_PROGRAM) $(BIN) Saida/