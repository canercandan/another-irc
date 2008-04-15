##
## Makefile for my_irc in /home/candan_c/cu/rendu/project/my_irc
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Tue Apr 15 00:09:44 2008 caner candan
## Last update Tue Apr 15 11:18:44 2008 caner candan
##

OBJ_PATH	=	obj

X_PATH		=	x
X_SRC		=	$(X_PATH)/xaccept.c	\
			$(X_PATH)/xbind.c	\
			$(X_PATH)/xconnect.c	\
			$(X_PATH)/xlisten.c	\
			$(X_PATH)/xrecv.c	\
			$(X_PATH)/xsend.c	\
			$(X_PATH)/xsocket.c

X_OBJ		=	$(X_SRC:.c=.o)

SRV		=	server
SRV_SRC		=	$(SRV)/main.c

SRV_OBJ		=	$(SRV_SRC:.c=.o) $(X_OBJ)

CLI		=	client
CLI_SRC		=	$(CLI)/main.c

CLI_OBJ		=	$(CLI_SRC:.c=.o) $(X_OBJ)

CC		=	gcc
RM		=	rm -rf
MK		=	make

INCLUDES	=	-I./include
CFLAGS		=	$(INCLUDES) -g -Wall -W

.c.o		:
			@$(CC) -c $< -o $@

all		:
			@$(MK) $(SRV)
			@$(MK) $(CLI)

$(SRV)		:	$(SRV_OBJ)
			@$(CC) -o $(SRV)/$(SRV) $(SRV_OBJ)

$(CLI)		:	$(CLI_OBJ)
			@$(CC) -o $(SRV)/$(SRV) $(CLI_OBJ)

clean		:
			$(RM) *~
			$(RM) *.o
			$(RM) *.core

fclean		:	clean
			$(RM) $(SRV)/$(SRV)
			$(RM) $(CLI)/$(SRV)

re		:	fclean all

.PHONY		:	all clean fclean re
