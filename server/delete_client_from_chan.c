/*
** delete_client_from_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sun Apr 27 20:03:46 2008 julian kirtz
** Last update Mon Apr 28 03:41:58 2008 julian kirtz
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

int		delete_client_from_chan(t_client *client, t_channel *chan)
{
  t_list	*current;
  t_list	*previous;

  printf("%s list before deleting:", chan->name);
  current = chan->client;
  while (current)
    {
      printf(" %s", ((t_client *)current->data)->nick);
      current = current->next;
    }
  printf("\n");
  current = chan->client;
  previous = current;
  while (current)
    {
      if (((t_client *)current->data) == client)
	{
	  if (previous == current)
	    chan->client = current->next;
	  else
	    previous->next = current->next;
	  free(current);
	  break;
	}
      previous = current;
      current = current->next;
    }
  current = client->channel;
  previous = current;
  while (current)
    {
      if (((t_channel *)current->data) == chan)
	{
	  if (previous == current)
	    client->channel = current->next;
	  else
	    previous->next = current->next;
	  free(current);
	  break;
	}
      previous = current;
      current = current->next;
    }
  printf("%s list after deleting:", chan->name);
  current = chan->client;
  while (current)
    {
      printf(" %s", ((t_client *)current->data)->nick);
      current = current->next;
    }
  printf("\n");
  printf("%s is in: ", client->nick);
  current = client->channel;
  while (current)
    {
      printf(" %s", ((t_channel *)current->data)->name);
      current = current->next;
    }
  printf("\n");
  if (chan->client)
    return (1);
  return (0);
}
