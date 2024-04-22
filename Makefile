CC = cc
CFLAGS = -Wall -Wextra -Werror
LD = ar
LDFLAGS = -rcs
INC = -Iinclude
NAME = libgnl.a
SRCS = src/get_next_line.c \
	   src/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^
