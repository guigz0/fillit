NAME := fillit

SRCS := srcs/fillit.c \
	   srcs/gd_read_blocks.c \
	   srcs/gd_valid_tetriminos.c \
	   srcs/get_next_line.c \
	   srcs/set_tetriminos.c \
	   srcs/treat_tetriminos.c

OBJDIR := objs

OBJS := $(subst srcs/, $(OBJDIR)/, $(SRCS:.c=.o))

CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I includes/ -Ilibft/includes/
CC := gcc

LIB := libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L libft -lft

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: srcs/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

$(LIB):
	make -C libft

clean:
	rm -rf $(OBJDIR)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

debug: CFLAGS := -g
debug: re

test: CFLAGS := -Wall
test: all

.PHONY: all clean re fclean