/*
** user_in_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 28 01:38:52 2008 julian kirtz
** Last update Mon Apr 28 02:19:19 2008 julian kirtz
*/

#include <stdio.h>
#include <sys/time.h>
#include "server.h"

char		user_in_chan(t_server *serv, int fd, t_channel *chan)
{
  t_list	*current;

  current = serv->client[fd].channel;
  while (current)
    if ((t_channel *)current->data == chan)
      {
	printf("%s is in %s\n", serv->client[fd].nick, chan->name);
	return (1);
      }
    else
      current = current->next;
  printf("%s is NOT in %s\n", serv->client[fd].nick, chan->name);
  return (0);
}
