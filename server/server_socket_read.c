/*
** server_socket_read.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 17:10:02 2008 julian kirtz
** Last update Sun Apr 27 13:57:23 2008 julian kirtz
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"

void			server_socket_read(t_server *serv, int fd)
{
  int			cs;
  struct sockaddr_in	client_sin;
  unsigned int		client_sin_len;

  printf("New Client !\n");
  client_sin_len = sizeof(client_sin);
  cs = accept(fd, (struct sockaddr *)&client_sin, &client_sin_len);
  serv->fd_type[cs] = FD_CLIENT;
  serv->fct_read[cs] = client_socket_read;
  serv->fct_write[cs] = client_socket_write;
  init_client(serv, cs);
}
