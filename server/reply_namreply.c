/*
** reply_namreply.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 20:12:46 2008 julian kirtz
** Last update Sat Apr 26 22:37:02 2008 julian kirtz
*/

#include <stdio.h>
#include <sys/time.h>
#include "server.h"

reply_namreply(t_server *serv, int fd, int index, void *chan)
{
  int		len;
  static int	count = -1;

  if (count == -1)
    count = 0;
  len = strlen(serv->client[fd].buffer_write[index]);
  snprintf(serv->client[fd].buffer_write[index], CLIENT_READ_BUF_SIZE - len,
	   RPL_NAMREPLY_FORMAT, ((t_channel)info)->name), nicklist_of_chan(chan, &count));
}
