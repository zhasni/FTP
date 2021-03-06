# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/16 14:59:53 by zhasni            #+#    #+#              #
#    Updated: 2015/04/21 23:20:34 by zhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_S		 =	server.c \
				ftp.c \
				tools.c \
				build.c \
				cd.c \
				setenv.c \
				get_put.c \
				error.c \
				extra.c \
				extra2.c \
				extra3.c \
				extra_s1.c \
				extra_s2.c \
				check.c

SRC_C		 =	ftp.c \
				tools.c \
				build.c \
				cd.c \
				setenv.c \
				get_put.c \
				error.c \
				client.c \
				extra.c \
				extra2.c \
				extra3.c \
				check.c

NAME1		= 	serveur
NAME2		= 	client
CC			= 	clang
CFLAGS		= 	-Werror -Wextra -Wall  
OBJ_S		= 	$(SRC_S:.c=.o)
OBJ_C		= 	$(SRC_C:.c=.o)
RM			= 	rm -rf
LIBFT		=	libft/
HEADERS		=	-I./. -Ilibft/
LIB			=	libft.a

all: $(LIB) $(NAME1) $(NAME2)
	@echo "\033[0mCrew ready to sail Cap'tain!~~";
	@echo "                                    ,shhhhhhhhhhhhhhho.      ,hhhhhhhhhhhhhhhoohhhhhhhhhhhhhhhh, ";
	@echo "                                  ,sNMMMMMMMMMMMMMMm+.       /MMMMMMMMMMMMMd/.sMMMMMMMMMMMMMMMM: ";
	@echo "                                ,smMMMMMMMMMMMMMMm+,         /MMMMMMMMMMMd+,  sMMMMMMMMMMMMMMMM: ";
	@echo "                              ,smMMMMMMMMMMMMMMm+,           /MMMMMMMMMd+,    sMMMMMMMMMMMMMMMM: ";
	@echo "                            ,omMMMMMMMMMMMMMMmo,             /MMMMMMMd+,      sMMMMMMMMMMMMMMMM: ";
	@echo "                          ,omMMMMMMMMMMMMMMmo,               /MMMMMm+,        sMMMMMMMMMMMMMMMM: ";
	@echo "                        ,omMMMMMMMMMMMMMMmo,                 /MMMmo,          sMMMMMMMMMMMMMMMM: ";
	@echo "                      ,omMMMMMMMMMMMMMMmo,                   /Mmo,            sMMMMMMMMMMMMMMMM: ";
	@echo "                    ,omMMMMMMMMMMMMMMNs,                     :o,             ,yMMMMMMMMMMMMMMMN, ";
	@echo "                  ,omMMMMMMMMMMMMMMNs,                                     ,:hMMMMMMMMMMMMMMNh:  ";
	@echo "                ,+mMMMMMMMMMMMMMMNs,                                     ,:hMMMMMMMMMMMMMMNh:    ";
	@echo "              ,+mMMMMMMMMMMMMMMNs,                                      ,hMMMMMMMMMMMMMMNd/      ";
	@echo "            ,+mMMMMMMMMMMMMMMNs,                                      ,yMMMMMMMMMMMMMMMd/,       ";
	@echo "          ,/mMMMMMMMMMMMMMMNs,                                      ,yMMMMMMMMMMMMMMMd/          ";
	@echo "        ,/mMMMMMMMMMMMMMMNy,                                      ,yMMMMMMMMMMMMMMMd/            ";
	@echo "      ,/mMMMMMMMMMMMMMMMy,                                      ,yNMMMMMMMMMMMMMMm/,             ";
	@echo "     /dMMMMMMMMMMMMMMMy,                                      ,sMMMMMMMMMMMMMMMm/                ";
	@echo "    sMMMMMMMMMMMMMMMMmhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhho      :NMMMMMMMMMMMMMMMy,             ,/, ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs            ,/dM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs          ,/dNMM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs        ,/dMMMMM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs      ,/dNMMMMMM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs     /hNMMMMMMMM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs  ,:hNMMMMMMMMMM: ";
	@echo "                                     +MMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs,:hNMMMMMMMMMMMM: ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh      :ddddddddddddddddoohdddddddddddddd, ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,hhhhhhhhhhhhhhhho                                          ";

$(LIB):
	@echo "\033[0;34mTrying to board libft.a...";
	@make -C $(LIBFT)

$(NAME1): $(OBJ_S)
	@echo "\033[0;31mSte\033[0;32mali\033[0;33mng a \033[0;34mnew\033[0;35m Ship \033[0m...";
	@$(CC) $(CFLAGS) -o $(NAME1) $(OBJ_S) libft/libft.a
	@echo "\033[0;32mShip stolen.";

$(NAME2): $(OBJ_C)
	@echo "\033[0;31mSte\033[0;32mali\033[0;33mng a \033[0;34mnew\033[0;35m Ship \033[0m...";
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ_C) libft/libft.a
	@echo "\033[0;32mShip stolen.";

%.o: %.c
	@echo "\033[0;35mLooting $<";
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@ #-L libft/libft.a

clean:
	@echo "\033[0;36mCleaning Rhum from Cargo...";
	@make clean -C $(LIBFT)
	@$(RM) $(OBJ_S)
	@$(RM) $(OBJ_C)
	@echo "\033[0;36mFound some fine bottles!";
fclean: clean
	@echo "\033[1;33mCleaning Gold Pieces from rich spoiled daddy's girl...";
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)
	@echo "Swimming in gold...";
re: fclean all

.PHONY: all clean fclean re
