/*
** get_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 16:44:32 2008 julian kirtz
** Last update Mon Apr 28 01:53:53 2008 julian kirtz
*/

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"

t_channel	*get_chan(t_list *chanlist, char *chan_name)
{
  t_list	*current;

  current = chanlist;
  while (current)
    if (strncmp(((t_channel *)current->data)->name,
		chan_name, MAX_CHAN_LEN) == 0)
      break;
    else
      current = current->next;
  printf("search: %s, Chan found: 0x%x\n", chan_name, (unsigned int)current);
  if (current)
    return (((t_channel *)current->data));
  return (0);
}
