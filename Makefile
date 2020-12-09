# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 13:03:41 by anatashi          #+#    #+#              #
#    Updated: 2020/12/09 13:40:51 by kbatwoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc -g
OPFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR			=	libft/
HEADER_DIR			=	header/

TEMP_DIR			=	srcs/temp/
TEMP_LIST			=	minishell.c\
						promt_string.c\
						signal.c\
						read_cmd.c\
						creat_env.c\
						init_struct_data.c\
						error_output.c\
						program_exit.c\
						check_syntax.c

LEXER_DIR			=	srcs/lexer/
LEXER_LIST			=	lexer.c\
						lexer_2.c\
						lexer_3.c\
						lexer_4.c\
						freeing_memory_from_lexer.c
		
PARSER_DIR			=	srcs/parser/
PARSER_LIST			=	parse.c\
						add_lst_to_node.c\
						init.c\
						init_cmd.c\
						init_struct_commands.c

EXECUTOR_DIR		=	srcs/executor/
EXECUTOR_LIST		=	executor.c\
						executor_selection_cmd.c\
						check_syntax_error.c

BUILTIN_CMD_DIR		= 	srcs/builtin_commands/
BUILTIN_CMD_LIST	= 	pwd.c\
						env.c\
						cd.c\
						echo.c\
						export.c\
						export_2.c\
						export_3.c\
						unset.c\
						unset_2.c\
						unset_3.c\
						exit.c\
						ft_check_cmd_in_path.c \
						error_case.c

SOURCE_TEMP			= $(addprefix $(TEMP_DIR), $(TEMP_LIST))
SOURCE_PARSER		= $(addprefix $(PARSER_DIR), $(PARSER_LIST))
SOURCE_EXECUTOR		= $(addprefix $(EXECUTOR_DIR), $(EXECUTOR_LIST))
SOURCE_LEXER		= $(addprefix $(LEXER_DIR), $(LEXER_LIST))
SOURCE_BUILTIN		= $(addprefix $(BUILTIN_CMD_DIR), $(BUILTIN_CMD_LIST))


OBJ	= $(patsubst %.c, %.o,	$(SOURCE_TEMP)\
							$(SOURCE_PARSER)\
							$(SOURCE_EXECUTOR)\
							$(SOURCE_LEXER)\
							$(SOURCE_BUILTIN))
							
D_FILES = $(patsubst %.c, %.d,	$(SOURCE_TEMP)\
								$(SOURCE_PARSER)\
								$(SOURCE_EXECUTOR)\
								$(SOURCE_LEXER)\
								$(SOURCE_BUILTIN))

.PHONY: all clean fclean re test norm

all: lib  $(NAME)

lib:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OPFLAGS) -L$(LIBFT_DIR) -lft $(OBJ)
	# $(CC) $(FLAGS) $(OBJ) -L. $(LIBFT_DIR)libft.a -o $(NAME)
	
%.o: %.c 
	$(CC) $(FLAGS) $(OPFLAGS) -I$(HEADER_DIR) -c $< -o $@ -MD
	# $(CC) $(FLAGS) -I$(HEADER_DIR) -c $< -o $@ -MD

include $(wildcard $(D_FILE))

clean:
	rm -rf $(OBJ) $(D_FILES)
	$(MAKE) clean -C $(LIBFT_DIR)


fclean : clean
	rm -rf $(LIBFT_DIR)/libft.a

	rm -rf $(NAME)


re : fclean all

norm:
	norminette $(HEADER_DIR). $(TEMP_DIR). $(LEXER_DIR). $(PARSER_DIR). $(EXECUTOR_DIR). $(BUILTIN_CMD_DIR). $(MAKE) norm -C $(LIBFT_DIR)

test: