/*
** reply_notopic.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 19:39:05 2008 julian kirtz
** Last update Sat Apr 26 19:57:38 2008 julian kirtz
*/

#include <stdio.h>
#include <sys/time.h>
#include "server.h"

void	reply_notopic(t_server *serv, int fd, int index, void *chan)
{
  int	len;

  len = strlen(serv->client[fd].buffer_write[index]);
  snprintf(serv->client[fd].buffer_write[index], CLIENT_READ_BUF_SIZE - len,
	   RPL_NOTOPIC_FORMAT, ((t_channel)info)->name));
}
