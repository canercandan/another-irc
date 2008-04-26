/*
** read_all_fd.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 21 11:25:24 2008 julian kirtz
** Last update Thu Apr 24 10:31:01 2008 julian kirtz
*/

#include <sys/time.h>
#include <sys/socket.h>
#include "server.h"

void	read_all_fd(t_server *serv)
{
  int	i;

  for (i = 0; i < MAX_FD; i++)
    {
      if (FD_ISSET(i, &(serv->fd_read)))
	serv->fct_read[i](serv, i);
      if (serv->fd_type[i] == FD_CLIENT && FD_ISSET(i, &(serv->fd_write)))
	serv->fct_write[i](serv, i);
    }
}
