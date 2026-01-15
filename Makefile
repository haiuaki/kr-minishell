# ════════════════════════════════════════════════════════════════════════════ #
#                           CONFIGURATION VARIABLES                            #
# ════════════════════════════════════════════════════════════════════════════ #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror  -I$(INC_DIR) -I$(LIBFT_DIR)
LIBS = -lreadline -lncurses -ltinfo $(LIBFT_DIR)/libft.a 

INC_DIR 	= includes
SRC_DIR 	= srcs
OBJ_DIR     = objs

LIBFT_DIR 	= $(INC_DIR)/ft_libft

# ════════════════════════════════════════════════════════════════════════════ #
#                                SOURCE FILES                                  #
# ════════════════════════════════════════════════════════════════════════════ #

SRCS = $(SRC_DIR)/test_main.c \
		$(SRC_DIR)/test_fonction.c \
		$(SRC_DIR)/ft_init.c \
		$(SRC_DIR)/bi_cd.c \
		$(SRC_DIR)/bi_echo.c \
		$(SRC_DIR)/bi_env.c \
		$(SRC_DIR)/bi_exit.c \
		$(SRC_DIR)/bi_exit_ft.c \
		$(SRC_DIR)/bi_export.c \
		$(SRC_DIR)/bi_pwd.c \
		$(SRC_DIR)/bi_unset.c \
		$(SRC_DIR)/bi_free.c \

# ════════════════════════════════════════════════════════════════════════════ #
#                                OBJECT FILES                                  #
# ════════════════════════════════════════════════════════════════════════════ #

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# ════════════════════════════════════════════════════════════════════════════ #
#                                PHONY TARGETS                                 #
# ════════════════════════════════════════════════════════════════════════════ #

.PHONY: all clean fclean re

# ════════════════════════════════════════════════════════════════════════════ #
#                                DEFAULT TARGET                                #
# ════════════════════════════════════════════════════════════════════════════ #

all: $(NAME)

# ════════════════════════════════════════════════════════════════════════════ #
#                                 BUILD RULES                                  #
# ════════════════════════════════════════════════════════════════════════════ #

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# ════════════════════════════════════════════════════════════════════════════ #
#                                CLEANUP RULES                                 #
# ════════════════════════════════════════════════════════════════════════════ #

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) 

re	: fclean all
