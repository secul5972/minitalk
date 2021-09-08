# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 19:17:25 by seungcoh          #+#    #+#              #
#    Updated: 2021/09/08 20:00:59 by seungcoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk
SERVER = server
CLIENT = client

SRCS = server.c client.c minitalk_utils.c
SRCS_SERVER = server.c minitalk_utils.c
SRCS_CLIENT = client.c minitalk_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all:		$(NAME) 

$(NAME): 	$(OBJS) $(SERVER) $(CLIENT)

$(SERVER):
			$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) 
			
$(CLIENT):
			$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) 

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re