##
## Makefile for Makefile in /home/theis_p/AutoMake/Makefile
##
## Made by Paul THEIS
## Login   <theis_p@epitech.net>
##
## Started on  Thu Jan  7 18:13:17 2016 Paul THEIS
## Last update Sun Jan 10 16:56:29 2016 Paul THEIS
##

NAME		= 	my_tar

SRCS		= 	main.c						\
			my_set_nbr.c					\
			my_set.c					\
			my_create.c					\
			my_directory.c					\
			my_file.c					\
			my_function.c					\
			my_options.c					\
			my_tar.c					\
			my_untar.c					\

OBJS		= 	$(addprefix src/, $(SRCS:.c=.o))

CFLAGS		=	-W -Wall -Wextra -Werror 
CFLAGS		+=	-ansi -pedantic
CFLAGS		+=	-I./include
CFLAGS  	+=	-D_DEFAULT_SOURCE

CC		=	cc -Ofast

RM		=	rm -f

$(NAME)	:		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

all	:		$(NAME)

clean	:
			$(RM) -f $(OBJS)

fclean	:		clean
			$(RM) -f $(NAME)

re	:		fclean all

go	:
			clear
			./$(NAME)

gov	:
			clear
			valgrind -v -q ./$(NAME)

govplus	:
			clear
			valgrind -v -q --leak-check=full ./$(NAME)

exe	:		abs
			@echo -e '\033[0;32m execution de :\n=== \033[0;36m'\
			$(NAME)'\033[0;32m === \033[0m'
			./$(NAME)

val	:		abs
			@echo -e '\033[0;32m execution de :\n=== \033[0;36m'\
			$(NAME)'\033[0;32m === \033[0m'
			valgrind -v -q ./$(NAME)

abs	:		abs_0 $(NAME)
			@echo -e '\033[0;32m (3/4) >> suppression des objets \033[0m'
			$(RM) $(OBJS)
			@echo -e '\033[0;32m (4/4) >> la compilation a réussie\033[0m'
			@echo -e ''
			ls -a --color
			@echo -e ''

abs_0	:
			clear
			@echo -e '\033[0;32m (1/4) >> suppression des fichiers temporaires'\
			'\033[0m'
			$(RM) $(OBJS)
			$(RM) $(NAME)
			@echo -e '\033[0;32m (2/4) >> compilation de \033[0;35m"'\
			$(NAME)' "\033[0m'
