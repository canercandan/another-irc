/*
** client_socket_write.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 10:33:50 2008 julian kirtz
** Last update Thu Apr 24 17:37:39 2008 julian kirtz
*/

#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"

void	client_socket_write(t_server *serv, int fd)
{
  int	i;

  i = 0;
  while (i < CLIENT_WRITE_BUF_LINE && serv->client[fd].buffer_write[i][0])
    {
      if (write(fd, serv->client[fd].buffer_write[i],
		strlen(serv->client[fd].buffer_write[i])))
	serv->client[fd].buffer_write[i][0] = '\0';
      else
	delete_client(serv, fd);
      i++;
    }
}
