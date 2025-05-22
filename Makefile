NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_line.c ft_next.c get_next_line_utils.c\
get_next_line.c
OBJS = $(SRCS:.c=.o)


AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all