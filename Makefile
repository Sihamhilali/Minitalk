# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 18:22:08 by selhilal          #+#    #+#              #
#    Updated: 2023/01/16 10:01:24 by selhilal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = client.c server.c
SRCB = client_bonus.c server_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: server client

bonus: server_bonus client_bonus

server: server.o printf
	$(CC) -o $@ $< ft_printf/libftprintf.a

server_bonus: server_bonus.o printf
	$(CC) -o $@ $< ft_printf/libftprintf.a

client: client.o printf
	$(CC) -o $@ $< ft_printf/libftprintf.a

client_bonus: client_bonus.o printf
	$(CC) -o $@ $< ft_printf/libftprintf.a

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< 

printf: 
	make -C ft_printf

clean :
	rm -f $(OBJ)
	rm -f $(OBJB)
	make -C ft_printf clean

fclean : clean
	rm -f server client ft_printf/libftprintf.a
	rm -f server_bonus client_bonus ft_printf/libftprintf.a

re : fclean all

.PHONY: clean fclean re