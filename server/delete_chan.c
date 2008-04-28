/*
** delete_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sun Apr 27 19:53:40 2008 julian kirtz
** Last update Mon Apr 28 02:15:36 2008 julian kirtz
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

void		delete_chan(t_server *serv, t_channel *chan)
{
  t_list	*current;
  t_list	*previous;

  current = serv->channel;
  previous = current;
  while (current)
    {
      printf("Compare chan %s and %s\n", ((t_channel *)current->data)->name, chan->name);
      if (((t_channel *)current->data) == chan)
	{
	  if (previous == current)
	    serv->channel = current->next;
	  else
	    previous->next = current->next;
	  printf("%s chan deleted\n", ((t_channel *)current->data)->name);
	  freelist(((t_channel *)current->data)->client);
	  free(((t_channel *)current->data)->banmask);
	  free(((t_channel *)current->data)->key);
	  free(((t_channel *)current->data)->topic);
	  free(current);
	  break;
	}
      previous = current;
      current = current->next;
    }
}
