# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmouyeme <cmouyeme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 19:01:01 by gdalard           #+#    #+#              #
#    Updated: 2019/05/15 17:27:55 by cmouyeme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

SRCS := srcs/fillit.c \
	   srcs/main.c \
	   srcs/read_file.c \
	   srcs/check_file.c \
	   srcs/treat_file.c \
	   srcs/get_next_line.c

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

.PHONY: all clean fclean re
