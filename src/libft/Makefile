# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:29:48 by tcoeffet          #+#    #+#              #
#    Updated: 2025/02/08 18:15:29 by tcoeffet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

QUIET = @

SOURCES =	ft_atoi.c\
			ft_abs.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_max.c\
			ft_min.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_printf/any_to_a.c\
			ft_printf/any_to_a_utils.c\
			ft_printf/for_arg_1.c\
			ft_printf/for_arg_2.c\
			ft_printf/ft_printf.c\
			ft_printf/utils.c\
			get_next_line.c\
			get_next_line_utils.c\
			
BONUS =		ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c\

OBJ = 		$(SOURCES:.c=.o)

OBJBONUS =	$(BONUS:.c=.o)

HEADERS =	libft.h

FLAGS = -Wall -Werror -Wextra

CC = cc

all : $(NAME)

$(NAME) : $(OBJ)
	$(QUIET)ar -rcs $(NAME) $(OBJ)

%.o : %.c
	$(QUIET)$(CC) $(FLAGS) -c -I$(HEADERS) -g $< -o $@

bonus : $(OBJBONUS)
	ar -rcs $(NAME) $(OBJBONUS)
%.o : %.c
	$(QUIET)$(CC) $(FLAGS) -c -I$(HEADERS) -g $< -o $@

clean :
		$(QUIET)rm -f $(OBJ) $(OBJBONUS)
fclean : clean
		$(QUIET)rm -f $(NAME)
re : fclean all
