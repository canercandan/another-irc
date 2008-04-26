/*
** get_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 16:44:32 2008 julian kirtz
** Last update Sat Apr 26 17:28:08 2008 julian kirtz
*/

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
  if (current)
    return (current->data);
  return (0);
}
