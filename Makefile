NAME = push_swap

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

INCLUDE = -I ./
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address 

%.o:	%.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:	
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
