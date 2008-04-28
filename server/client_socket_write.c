/*
** client_socket_write.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 10:33:50 2008 julian kirtz
** Last update Sun Apr 27 23:04:45 2008 julian kirtz
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"
#include "x.h"

int	strnlen(char *str, int size)
{
  int	i;

  i = 0;
  while (i < size && str[i] != '\0')
    i++;
  return (i);
}

void		client_socket_write(t_server *serv, int fd)
{
  int		i;
  int		len;
  t_message	msg;
  char		*error_msg;

  i = 0;
  while (i < CLIENT_WRITE_BUF_LINE && serv->client[fd].buffer_write[i][0])
    {
      len = strnlen(serv->client[fd].buffer_write[i], CLIENT_WRITE_BUF_SIZE);
      if (write(fd, serv->client[fd].buffer_write[i], len))
	memset(serv->client[fd].buffer_write[i], '\0', CLIENT_WRITE_BUF_SIZE);
      else
	{
	  error_msg = xmalloc(sizeof(*error_msg) * (strlen(ERR_QUIT_WRITE) + 1));
	  strcpy(error_msg, ERR_QUIT_WRITE);
	  extract_msg(error_msg, &msg);
	  cmd_quit(serv, fd, &msg);
	  free(error_msg);
	}
      i++;
    }
}
