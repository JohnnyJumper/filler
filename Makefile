# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 17:27:11 by jtahirov          #+#    #+#              #
#    Updated: 2018/06/18 08:53:19 by jtahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -g
NAME = filler
IDIR = ./include

_DEPS = filler.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

SRC = filler.c parse.c utills.c


SRC_OBJ =$(SRC:.c=.o)

OBJ = $(SRC_OBJ)
LIBS = ./libft/libft.a

all: $(NAME)

$(LIBS):
	@+$(MAKE) -C ./libft

%.o: %.c $(DEPS)
	@echo "\033[0;32m\c"
	$(CC) -c -o $@ $< $(CFLAGS)
	@echo "\033[0m\c"

$(NAME): $(OBJ) $(LIBS)
	@echo "\033[0;35m\c"
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

rsa: $(BASE64_OBJ) $(RSA_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

base64: $(BASE64_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

des: $(DES_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

md5: $(MD5_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

clean:
	@/bin/rm -f $(OBJ)
	@+$(MAKE) clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@+$(MAKE) fclean -C ./libft


re: fclean all

.PHONY: clean fclean re
