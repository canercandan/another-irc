/*
** client_socket_read.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 21 11:44:02 2008 julian kirtz
** Last update Thu Apr 24 15:43:24 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

void	client_socket_read(t_server *serv, int fd)
{
  serv->client[fd].buffer_offset = read(fd, serv->client[fd].buffer_read
					+ serv->client[fd].buffer_offset,
					CLIENT_READ_BUF_SIZE
					- serv->client[fd].buffer_offset);
  if (serv->client[fd].buffer_offset > 0)
    protocol_interpreter(serv, fd);
  else
    delete_client(serv, fd);
  //  printf("end\n");
}
