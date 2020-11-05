# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 13:03:41 by anatashi          #+#    #+#              #
#    Updated: 2020/11/05 13:33:31 by anatashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc -g
OPFLAGS = -O2
FLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR			=	libft/
HEADER_DIR			=	header/
# _DIR	=	tools/

TEMP_DIR			=	srcs/temp/
TEMP_LIST			=	minishell.c\
						promt_string.c\
						signal.c\
						read_cmd.c\
						init_struct_commands.c \
						print_result.c

ERROR_OUTPUT_DIR 	=	srcs/error_output/
ERROR_OUTPUT_LIST 	=	error_output.c\
						program_exit.c
		
PARSER_DIR			=	srcs/parser/
PARSER_LIST			=	create_list.c \
# _LIST	=	

# _LIST	=




SOURCE_TEMP			= $(addprefix $(TEMP_DIR), $(TEMP_LIST))
SOURCE_ERROR		= $(addprefix $(ERROR_OUTPUT_DIR), $(ERROR_OUTPUT_LIST))
SOURCE_PARSER		= $(addprefix $(PARSER_DIR), $(PARSER_LIST))

OBJ	= $(patsubst %.c, %.o, $(SOURCE_TEMP) $(SOURCE_ERROR) $(SOURCE_PARSER))
D_FILES = $(patsubst %.c, %.d, $(SOURCE_TEMP) $(SOURCE_ERROR) $(SOURCE_PARSER)) 

.PHONY: all clean fclean re test norm

all: lib  $(NAME)

lib:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OPFLAGS) -L$(LIBFT_DIR) -lft $(OBJ)
	
%.o: %.c 
	$(CC) $(FLAGS) $(OPFLAGS) -I$(HEADER_DIR) -c $< -o $@ -MD

include $(wildcard $(D_FILE))

clean:
	rm -rf $(OBJ) $(D_FILES)
	$(MAKE) clean -C $(LIBFT_DIR)


fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)

	rm -rf $(NAME)


re : fclean all

norm:
	norminette $(TEMP_DIR). $(ERROR_OUTPUT_DIR). $(HEADER_DIR). $(MAKE) norm -C $(LIBFT_DIR)

test:
