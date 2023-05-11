NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 
SRCS_BONUS = 
INC = 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f

ifdef BONUS
$(NAME): $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)
else
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
endif

all: $(NAME)

bonus :
	make BONUS=1

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

fclean: 
	make clean
	$(RM) $(RMFLAGS) $(NAME)

re: 
	make fclean
	make all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

.PHONY: all clean fclean re