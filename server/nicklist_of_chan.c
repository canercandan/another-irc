/*
** nicklist_of_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 21:44:34 2008 julian kirtz
** Last update Mon Apr 28 08:05:09 2008 julian kirtz
*/

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"
#include "x.h"

char		*nicklist_of_chan(t_channel *chan)
{
  t_list	*current;
  char		*nick;
  char		*nicklist;
  int		len;

  nicklist = 0;
  current = chan->client;
  len = 0;
  while (current)
    {
      nick = ((t_client *)current->data)->nick;
      if (nicklist)
	len = strlen(nicklist);
      nicklist = xrealloc(nicklist, sizeof(char) * (len + strlen(nick) + 1));
      sprintf(nicklist + len, "%s ", nick);
      current = current->next;
    }
  return (nicklist);
}
