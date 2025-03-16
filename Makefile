#-variables------------------------------------------------------------#

MAKEFLAGS += --no-print-directory

QUIET = 	@

NAME = 		pipex

MAIN = 		./src/main.c\

MAIN_BONUS = ./src/bonus/main_bonus.c\

SOURCES =	$(MAIN)\
			./src/toto.c\

SOURCES_BONUS = $(MAIN_BONUS)\
			./src/toto.c\
				
OBJ =		$(SOURCES:.c=.o)\

OBJ_BONUS = $(SOURCES_BONUS:.c=.o)\

INCLUDES =	./includes

LIBFT =		./src/libft/libft.a

CC = $(QUIET) cc

FLAGS = -Wall -Wextra -Werror -g 


#-bonus filter---------------------------------------------------------#

ifneq ($(filter bonus, $(MAKECMDGOALS)),)
SOURCES = $(SOURCES_BONUS)
endif


#----------------------------------------------------------------------#

all : 			$(NAME)

bonus : 		all


#-compil---------------------------------------------------------------#

$(LIBFT) :
				$(QUIET) make -C ./src/libft QUIET=$(QUIET) all

$(NAME) :		$(LIBFT) $(OBJ) 
				$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
				$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@


#-rules----------------------------------------------------------------#

clean :			
				$(QUIET) rm -f $(OBJ)
				$(QUIET) make -C ./src/libft QUIET=$(QUIET) clean
				
fclean : 		clean
				$(QUIET) rm -f $(NAME)
				$(QUIET) make -C ./src/libft QUIET=$(QUIET) fclean
				
clean_bonus : 	clean
				$(QUIET) rm -f $(OBJ_BONUS)
				
fclean_bonus : 	fclean
				$(QUIET) rm -f $(OBJ_BONUS)
				
re : 			fclean all