/*
** create_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 16:28:32 2008 julian kirtz
** Last update Mon Apr 28 00:07:16 2008 julian kirtz
*/

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"
#include "x.h"

t_channel	*create_chan(t_server *serv, char *name)
{
  t_channel	*chan;
  t_list	*channel;

  chan = xmalloc(sizeof(*chan));
  strncpy(chan->name, name, MAX_CHAN_LEN);
  chan->mode = 0;
  chan->limit = 0;
  chan->banmask = 0;
  chan->key = 0;
  chan->topic = 0;
  chan->client = 0;
  channel = xmalloc(sizeof(*channel));
  channel->data = chan;
  printf("New AddressOf chan: 0x%x\n", (unsigned int)chan);
  channel->next = serv->channel;
  serv->channel = channel;
  printf("New AddressOf servchanlist: 0x%x\n", (unsigned int)serv->channel);
  return (chan);
}
