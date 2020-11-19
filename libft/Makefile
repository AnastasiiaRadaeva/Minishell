# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/15 16:48:11 by anatashi          #+#    #+#              #
#    Updated: 2020/11/18 17:26:17 by anatashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR	= srcs/
LIST =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		get_next_line.c get_next_line_utils.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c	ft_lstmap.c\
		ft_lstdelone_f.c ft_putendl.c ft_putstr.c ft_putchar.c ft_strndup.c \
		ft_strlenchar.c ft_strnjoin.c ft_free_tmp.c ft_str_add_char.c ft_freearrpoint.c \
		ft_isspace.c ft_min.c ft_binary_tree_sorting.c ft_strnstrindex.c ft_strcmp.c ft_free_two_dimensional_arr.c \
		ft_strndup2.c ft_strcdup2.c ft_add_element_to_two_dimensional_array.c ft_strlenarr.c ft_strchr2.c \
		ft_delete_an_array_element.c create_two_dimensional_array_from_lst.c ft_strnrchr.c \
		ft_strrchr2.c ft_strcpy.c

SOURCE = $(addprefix $(DIR), $(LIST))
OBJ	= $(patsubst %.c, %.o, $(SOURCE))
D_FILE = $(patsubst %.c, %.d, $(SOURCE))

CC = gcc -g
OPFLAGS = -O2
FLAGS = -Wall -Wextra -Werror
HEADER = header/

.PHONY: all bonus clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?
	ranlib $(NAME)
%.o: %.c
	$(CC) $(FLAGS) $(OPFLAGS) -I$(HEADER) -c $< -o $@ -MD

include $(wildcard $(D_FILE))

clean:
	rm -rf $(OBJ) $(D_FILE)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
norm:
	norminette $(DIR).
