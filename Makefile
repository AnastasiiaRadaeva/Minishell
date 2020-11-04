# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 13:03:41 by anatashi          #+#    #+#              #
#    Updated: 2020/11/03 20:59:28 by anatashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
OPFLAGS = -O2
FLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADER		=	header/

TEMP_DIR	=	srcs/temp/
# _DIR	=	parser/
# _DIR	=	tools/

TEMP_LIST	=	minishell.c\
				promt_string.c\
				signal.c\
				read_cmd.c\
				init_struct_commands.c

		
# _LIST	=	

# _LIST	=

LIBFT_DIR	 =	libft/



SOURCE_TEMP	=	$(addprefix $(TEMP_DIR), $(TEMP_LIST))

OBJ	= $(patsubst %.c, %.o, $(SOURCE_TEMP))
D_FILES = $(patsubst %.c, %.d, $(SOURCE_TEMP))

.PHONY: all clean fclean re test norm

all: lib  $(NAME)

lib:
	make -C $(LIBFT_DIR)

	
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OPFLAGS) -L$(LIBFT_DIR) -lft $(OBJ)
	
%.o: %.c 
	$(CC) $(FLAGS) $(OPFLAGS) -I$(HEADER) -c $< -o $@ -MD

include $(wildcard $(D_FILE))

clean :
	rm -rf $(OBJ) $(D_FILES)
	$(MAKE) clean -C $(LIBFT_DIR)


fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)

	rm -rf $(NAME)


re : fclean all

norm:
	norminette srcs/temp/*.c srcs/error_output/*.c header/*.h libft/srcs/*.c libft/header/*.c 

test:
