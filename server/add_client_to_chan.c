/*
** add_client_to_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 16:18:35 2008 julian kirtz
** Last update Sun Apr 27 18:33:09 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"
#include "x.h"

void		add_client_to_chan(t_server *serv, int fd, t_channel *chan)
{
  t_list	*client;
  t_list	*channel;

  client = xmalloc(sizeof(*client));
  client->data = &(serv->client[fd]);
  client->next = chan->client;
  chan->client = client;
  channel = xmalloc(sizeof(*channel));
  channel->data = chan;
  channel->next = serv->client[fd].channel;
  serv->client[fd].channel = channel;
}
