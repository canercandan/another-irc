/*
** create_chan.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 16:28:32 2008 julian kirtz
** Last update Sat Apr 26 17:08:39 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"
#include "../x/x.h"

t_channel	*create_chan(t_server *serv, char *name)
{
  t_channel	*chan;

  chan = xmalloc(sizeof(t_channel));
  strncpy(chan->name, name, MAX_CHAN_LEN);
  chan->mode = 0;
  chan->limit = 0;
  chan->banmask = 0;
  chan->key = 0;
  chan->topic = 0;
  chan->client = 0;
  return (chan);
}
