# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juljin <juljin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 13:29:07 by juljin            #+#    #+#              #
#    Updated: 2026/01/03 22:17:34 by juljin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ════════════════════════════════════════════════════════════════════════════ #
#                         CONFIGURATION VARIABLES                              #
# ════════════════════════════════════════════════════════════════════════════ #

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3 -I$(INCDIR)
AR			= ar rcs
RM			= rm -f

INCDIR		= includes
SRCDIR		= src
OBJDIR		= objs

# ════════════════════════════════════════════════════════════════════════════ #
#                           SOURCE FILES                                       #
# ════════════════════════════════════════════════════════════════════════════ #

# Conversion functions
CONV_SRC	= $(SRCDIR)/conversion/ft_atoi.c \
			  $(SRCDIR)/conversion/ft_atol.c \
			  $(SRCDIR)/conversion/ft_itoa.c \
			  $(SRCDIR)/conversion/ft_strtoul.c

# Character type functions
CTYPE_SRC	= $(SRCDIR)/ctype/ft_abs.c \
			  $(SRCDIR)/ctype/ft_isalnum.c \
			  $(SRCDIR)/ctype/ft_isalpha.c \
			  $(SRCDIR)/ctype/ft_isascii.c \
			  $(SRCDIR)/ctype/ft_isdigit.c \
			  $(SRCDIR)/ctype/ft_isprint.c \
			  $(SRCDIR)/ctype/ft_isspace.c \
			  $(SRCDIR)/ctype/ft_tolower.c \
			  $(SRCDIR)/ctype/ft_toupper.c

# Input/Output functions
IO_SRC		= $(SRCDIR)/io/ft_putchar_fd.c \
			  $(SRCDIR)/io/ft_putendl_fd.c \
			  $(SRCDIR)/io/ft_putnbr_fd.c \
			  $(SRCDIR)/io/ft_putstr_fd.c \

# List functions
LIST_SRC	= $(SRCDIR)/list/ft_lstadd_back.c \
			  $(SRCDIR)/list/ft_lstadd_front.c \
			  $(SRCDIR)/list/ft_lstclear.c \
			  $(SRCDIR)/list/ft_lstdelone.c \
			  $(SRCDIR)/list/ft_lstiter.c \
			  $(SRCDIR)/list/ft_lstlast.c \
			  $(SRCDIR)/list/ft_lstmap.c \
			  $(SRCDIR)/list/ft_lstnew.c \
			  $(SRCDIR)/list/ft_lstsize.c

# Memory functions
MEM_SRC		= $(SRCDIR)/memory/ft_bzero.c \
			  $(SRCDIR)/memory/ft_calloc.c \
			  $(SRCDIR)/memory/ft_memchr.c \
			  $(SRCDIR)/memory/ft_memcmp.c \
			  $(SRCDIR)/memory/ft_memcpy.c \
			  $(SRCDIR)/memory/ft_memmove.c \
			  $(SRCDIR)/memory/ft_memset.c

# String functions
STR_SRC		= $(SRCDIR)/string/ft_free_split.c \
			  $(SRCDIR)/string/ft_split.c \
			  $(SRCDIR)/string/ft_strchr.c \
			  $(SRCDIR)/string/ft_strdup.c \
			  $(SRCDIR)/string/ft_striteri.c \
			  $(SRCDIR)/string/ft_strjoin.c \
			  $(SRCDIR)/string/ft_strlcat.c \
			  $(SRCDIR)/string/ft_strlcpy.c \
			  $(SRCDIR)/string/ft_strlen.c \
			  $(SRCDIR)/string/ft_strmapi.c \
			  $(SRCDIR)/string/ft_strncmp.c \
			  $(SRCDIR)/string/ft_strnstr.c \
			  $(SRCDIR)/string/ft_strrchr.c \
			  $(SRCDIR)/string/ft_strtrim.c \
			  $(SRCDIR)/string/ft_substr.c

# Printf functions
PRINTF_CORE	= $(SRCDIR)/ft_printf/core/dispatcher.c \
			  $(SRCDIR)/ft_printf/core/ft_printf.c \
			  $(SRCDIR)/ft_printf/core/utils.c

PRINTF_PARSE = $(SRCDIR)/ft_printf/parsing/parse.c \
			   $(SRCDIR)/ft_printf/parsing/parse_utils.c

PRINTF_PRINT = $(SRCDIR)/ft_printf/printers/print_char.c \
			   $(SRCDIR)/ft_printf/printers/print_hex.c \
			   $(SRCDIR)/ft_printf/printers/print_hex_utils.c \
			   $(SRCDIR)/ft_printf/printers/print_nbr.c \
			   $(SRCDIR)/ft_printf/printers/print_nbr_utils.c \
			   $(SRCDIR)/ft_printf/printers/print_nbr_utils2.c \
			   $(SRCDIR)/ft_printf/printers/print_str.c \
			   $(SRCDIR)/ft_printf/printers/print_unsign.c \
			   $(SRCDIR)/ft_printf/printers/print_unsign_utils.c

FT_PRINTF	= $(PRINTF_CORE) $(PRINTF_PARSE) $(PRINTF_PRINT)

# Get Next Line functions
GNL			= $(SRCDIR)/get_next_line/get_next_line.c \
			  $(SRCDIR)/get_next_line/get_next_line_utils.c

# ════════════════════════════════════════════════════════════════════════════ #
#                           OBJECT FILES                                       #
# ════════════════════════════════════════════════════════════════════════════ #

SRC			= $(CONV_SRC) $(CTYPE_SRC) $(IO_SRC) $(LIST_SRC) \
			  $(MEM_SRC) $(STR_SRC) $(FT_PRINTF) $(GNL)

OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

# ════════════════════════════════════════════════════════════════════════════ #
#                           PHONY TARGETS                                      #
# ════════════════════════════════════════════════════════════════════════════ #

.PHONY: all clean fclean re

# ════════════════════════════════════════════════════════════════════════════ #
#                            DEFAULT TARGET                                    #
# ════════════════════════════════════════════════════════════════════════════ #

all: $(NAME)

# ════════════════════════════════════════════════════════════════════════════ #
#                            BUILD RULES                                       #
# ════════════════════════════════════════════════════════════════════════════ #

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compilation rules
$(OBJDIR)/%.o: $(SRCDIR)/conversion/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/ctype/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/io/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/list/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/memory/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/string/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/ft_printf/core/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/ft_printf/parsing/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/ft_printf/printers/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/get_next_line/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Library creation
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "✓ $(NAME) created successfully"

# ════════════════════════════════════════════════════════════════════════════ #
#                            CLEANUP RULES                                     #
# ════════════════════════════════════════════════════════════════════════════ #

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all