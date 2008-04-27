/*
** reply_notopic.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 19:39:05 2008 julian kirtz
** Last update Sun Apr 27 13:53:52 2008 julian kirtz
*/

#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include "server.h"

int	reply_notopic(t_server *serv, int fd, int index, void *chan)
{
  int	len;

  len = strlen(serv->client[fd].buffer_write[index]);
  snprintf(serv->client[fd].buffer_write[index], CLIENT_READ_BUF_SIZE - len,
	   RPL_NOTOPIC_FORMAT, ((t_channel *)chan)->name);
  return (0);
}
