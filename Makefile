# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cosmos <cosmos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 20:41:57 by cosmos            #+#    #+#              #
#    Updated: 2025/01/12 16:20:08 by cosmos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = pipex
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror
RM              = rm -rf
SRCS            = src/pipex.c \
				  src/path_utils.c \
				  src/free_it.c \
				  src/commande_utils.c \
				  src/execute.c \

OBJS            = $(SRCS:.c=.o)

LIBFT_PATH      = ./libft
LIBFT           = $(LIBFT_PATH)/libft.a

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

all:            $(NAME)

$(NAME):        $(LIBFT) $(OBJS)
				cp $(LIBFT) $(NAME)
				@${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}


$(LIBFT):
				make -C $(LIBFT_PATH)

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJS)

fclean:         clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:             fclean all