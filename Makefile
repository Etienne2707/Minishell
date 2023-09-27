NAME = minishell

SRC_DIR = ./src

BIN_DIR = ./bin/

SRC =	$(SRC_DIR)/main.c			\
		$(SRC_DIR)/utils.c			\
		$(SRC_DIR)/token.c			\
		$(SRC_DIR)/split.c		\

OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)%.o)

INCLUDES = ./includes

CFLAGS = -I$(INCLUDES) -g3 -lreadline

all :	$(NAME)


$(BIN_DIR)%.o : $(SRC_DIR)/%.c
		 @  $(CC) $(CFLAGS) -I$(INCLUDES)  -c $< -o $@

$(NAME) :	$(BIN_DIR) $(OBJ)
			@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

$(BIN_DIR) :
		@ mkdir -p $(BIN_DIR)

clean :
		@ rm -f $(OBJ)
		@ rm -rf $(BIN_DIR)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ rm -f $(NAME)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean all

.PHONY: all clean fclean re