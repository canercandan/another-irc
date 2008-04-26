/*
** init_all_fd.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 21 10:39:21 2008 julian kirtz
** Last update Thu Apr 24 10:24:58 2008 julian kirtz
*/

#include <sys/time.h>
#include <sys/socket.h>
#include "server.h"

void	init_all_fd(t_server *serv)
{
  int	i;

  FD_ZERO(&(serv->fd_read));
  FD_ZERO(&(serv->fd_write));
  serv->fd_max = 0;
  for (i = 0; i < MAX_FD; i++)
    if (serv->fd_type[i] != FD_FREE)
      {
	FD_SET(i, &(serv->fd_read));
	FD_SET(i, &(serv->fd_write));
	serv->fd_max = i;
      }
}
