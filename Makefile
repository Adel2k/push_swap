NAME = push_swap
BONUS_NAME = checker

SRCS = 	butterfly.c \
		check.c \
		ft_split.c \
		main.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sorting.c \
		swap.c \
		utils.c \
		utils2.c \
		utils3.c \

BONUS_SRCS =  	checker.c \
 				push_swap.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				check.c \
				ft_split.c \
				swap.c \
				utils.c \
				utils2.c \
				utils3.c \
				get_next_line.c \
				get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

INCLUDE = -I ./
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror 


all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): 	$(BONUS_OBJS) 
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

%.o:	%.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME) $(BONUS)

re:	fclean all

.PHONY:	all clean fclean re bonus