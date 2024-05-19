NAME = push_swap
BONUS_NAME = checker

SRCS_DIR = 	source
BONUS_DIR = bonus
INC_DIR = include

SRCS = $(wildcard $(SRCS_DIR)/*.c)
BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.c)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
INCLUDE = -I$(INC_DIR) 
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) 

%.o:	%.c $(INCLUDE) 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): 	$(BONUS_OBJS) 
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)


clean:	
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME) $(BONUS)

re:	fclean all

.PHONY:	all clean fclean re bonus