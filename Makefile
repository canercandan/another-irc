##
## Makefile for make in /home/candan_c/cu/rendu/test/make
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Tue Apr 15 11:19:53 2008 caner candan
## Last update Mon Apr 28 08:14:45 2008 caner candan
##

NAME_SRV	=	server
NAME_CLI	=	client
NAME_X		=	x
NAME_BIN	=	bin
NAME_OBJ	=	obj

PATH_SRV	=	$(NAME_SRV)/
PATH_CLI	=	$(NAME_CLI)/
PATH_X		=	$(NAME_X)/
PATH_BIN	=	$(NAME_BIN)/
PATH_OBJ	=	$(NAME_OBJ)/

BIN_SRV		=	$(PATH_BIN)$(NAME_SRV)
BIN_CLI		=	$(PATH_BIN)$(NAME_CLI)

SRCS_X		=	$(PATH_X)xaccept.c		\
			$(PATH_X)xbind.c		\
			$(PATH_X)xconnect.c		\
			$(PATH_X)xgethostbyname.c	\
			$(PATH_X)xlisten.c		\
			$(PATH_X)xmalloc.c		\
			$(PATH_X)xrealloc.c		\
			$(PATH_X)xopen.c		\
			$(PATH_X)xclose.c		\
			$(PATH_X)xrecv.c		\
			$(PATH_X)xsend.c		\
			$(PATH_X)xsocket.c		\
			$(PATH_X)xfork.c

SRCS_SRV	=	$(PATH_SRV)add_client_to_chan.c \
			$(PATH_SRV)broadcast_command.c \
			$(PATH_SRV)cfg_ip.c \
			$(PATH_SRV)cfg_key.c \
			$(PATH_SRV)cfg_port.c \
			$(PATH_SRV)cfg_timeout.c \
			$(PATH_SRV)client_socket_read.c \
			$(PATH_SRV)client_socket_write.c \
			$(PATH_SRV)cmd_join.c \
			$(PATH_SRV)cmd_nick.c \
			$(PATH_SRV)cmd_part.c \
			$(PATH_SRV)cmd_pass.c \
			$(PATH_SRV)cmd_privmsg.c \
			$(PATH_SRV)cmd_quit.c \
			$(PATH_SRV)cmd_user.c \
			$(PATH_SRV)count_nb_port.c \
			$(PATH_SRV)create_chan.c \
			$(PATH_SRV)create_server.c \
			$(PATH_SRV)delete_chan.c \
			$(PATH_SRV)delete_client.c \
			$(PATH_SRV)delete_client_from_chan.c \
			$(PATH_SRV)do_command.c \
			$(PATH_SRV)extract_msg.c \
			$(PATH_SRV)freelist.c \
			$(PATH_SRV)get_chan.c \
			$(PATH_SRV)get_next_message.c \
			$(PATH_SRV)init_all_fd.c \
			$(PATH_SRV)init_client.c \
			$(PATH_SRV)is_digit.c \
			$(PATH_SRV)is_letter.c \
			$(PATH_SRV)is_special.c \
			$(PATH_SRV)load_values_from_file.c \
			$(PATH_SRV)main.c \
			$(PATH_SRV)nicklist_of_chan.c \
			$(PATH_SRV)offset_to_next_value.c \
			$(PATH_SRV)protocol_interpreter.c \
			$(PATH_SRV)read_all_fd.c \
			$(PATH_SRV)reply_endofnames.c \
			$(PATH_SRV)reply_error.c \
			$(PATH_SRV)reply_namreply.c \
			$(PATH_SRV)reply_notopic.c \
			$(PATH_SRV)reply_response.c \
			$(PATH_SRV)server_socket_read.c \
			$(PATH_SRV)user_in_chan.c

SRCS_CLI	=	$(PATH_CLI)main.c			\
			$(PATH_CLI)init_user_list.c		\
			$(PATH_CLI)init_mesg_list.c		\
			$(PATH_CLI)insert_user_to_list.c	\
			$(PATH_CLI)insert_mesg_to_list.c	\
			$(PATH_CLI)create_column.c		\
			$(PATH_CLI)send_mesg.c			\
			$(PATH_CLI)about.c			\
			$(PATH_CLI)connect_btn_login.c		\
			$(PATH_CLI)connect_btn_dialog.c		\
			$(PATH_CLI)widget_connected.c		\
			$(PATH_CLI)init_dialog.c		\
			$(PATH_CLI)connect_to_server.c		\
			$(PATH_CLI)create_socket.c		\
			$(PATH_CLI)error_login.c		\
			$(PATH_CLI)check_entry.c		\
			$(PATH_CLI)send_to_server.c		\
			$(PATH_CLI)debug.c			\
			$(PATH_CLI)trim.c			\
			$(PATH_CLI)extract_msg.c		\
			$(PATH_CLI)init_server.c		\
			$(PATH_CLI)scrolled_window.c		\
			$(PATH_CLI)mesg_init.c			\
			$(PATH_CLI)send_pong.c			\
			$(PATH_CLI)send_list.c

OBJS_X		=	$(SRCS_X:.c=.o)
OBJS_SRV	=	$(SRCS_SRV:.c=.o) $(OBJS_X)
OBJS_CLI	=	$(SRCS_CLI:.c=.o) $(OBJS_X)

INCLUDES_GTK	=	`pkg-config --cflags gtk+-2.0 libglade-2.0`
LIBRARY_GTK	=	`pkg-config --libs gtk+-2.0 libglade-2.0`

INCLUDES	=	-I./include $(INCLUDES_GTK)
LIBRARY		=	-L. $(LIBRARY_GTK)

DEBUG		=	-g
PANIC		=	-Wall -W -Werror -pedantic -ansi

CFLAGS		=	$(INCLUDES) $(DEBUG) $(PANIC)
LDFLAGS		=	$(LIBRARY)

CC		=	gcc
RM		=	rm -rf
RM_O		=	find . -name '*.o' -exec rm {} \;
RM_CORE		=	find . -name '*.core' -exec rm {} \;
RM_TILD		=	find . -name '*~' -exec rm {} \;
MK		=	make
MKD		=	mkdir -p

.SUFFIXES	:	.c.o

all		:
			@$(MKD) $(PATH_SRV)
			@$(MKD) $(PATH_CLI)
			@$(MKD) $(PATH_BIN)
			@$(MK) $(BIN_SRV)
			@$(MK) $(BIN_CLI)

$(BIN_SRV)	:	$(OBJS_SRV)
			@$(CC) -o $@ $(OBJS_SRV) $(LDFLAGS)

$(BIN_CLI)	:	$(OBJS_CLI)
			@$(CC) -o $@ $(OBJS_CLI) $(LDFLAGS)

clean		:
			@$(RM_O)
			@$(RM_CORE)
			@$(RM_TILD)

fclean		:	clean
			$(RM) $(BIN_SRV)
			$(RM) $(BIN_CLI)

re		:	fclean all

.PHONY		:	all clean fclean re

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@
