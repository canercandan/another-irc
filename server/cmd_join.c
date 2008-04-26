/*
** cmd_join.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 12:04:03 2008 julian kirtz
** Last update Sat Apr 26 20:03:33 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

char	*get_next_chan(char *chan_name, char *chan_list, int chan_index)
{
  int	j;
  int	i;

  chan_name[0] = '\0';
  j = 0;
  i = 0;
  while (chan_list[i] && j != chan_index)
    if (chan_list[i++] == ',')
      j++;
  j = 0;
  while (chan_list[i] && j < MAX_CHAN_LEN && chan_list[i] != ',')
    chan_name[j++] = chan_list[i++];
  chan_name[j] = '\0';
}

char	check_chan(char *chan_name)
{
  int	i;

  if (chan_name[0] == '#' || chan_name[0] == '+'
      || chan_name[0] == '!' || chan_name[0] == '&')
    {
      for (i = 0; i < MAX_CHAN_LEN && chan_name[i]; i++)
	if (!((chan_name[i] >= '!' && chan_name[i] <= '+')
	      || (chan_name[i] >= '-' && chan_name[i] <= '9')
	      || (chan_name[i] >= ';' && chan_name[i] <= '~')))
	  return (0);
      return (1);
    }
  return (0);
}

char	check_key(t_channel *chan, int chan_index, char *key_list)
{
  int	j;
  int	i;

  if (!(chan->key))
    return (1);
  j = 0;
  i = 0;
  while (key_list[i] && j != chan_index)
    if (key_list[i++] == ',')
      j++;
  j = 0;
  while (key_list[i] && chan->key[j] && key_list[i] != ',')
    if (key_list[i++] != chan->key[j++])
      return (0);
  if (chan->key[j] == '\0' && (key_list[i] == '\0' || key_list[i] == ','))
    return (1);
  return (0);
}

char		user_in_chan(t_server *serv, int fd, char *chan_name)
{
  t_list	*current;

  current = serv->client[fd].channel;
  while (current)
    if (strcmp(((t_channel *)current->data)->name,
	       chan_name, MAX_CHAN_LEN) == 0)
      return (1);
    else
      current = current->next;
  return (0);
}

void	cmd_join(t_server *serv, int fd, t_message *msg)
{
  char		chan_name[MAX_CHAN_LEN + 1];
  int		chan_index;
  t_channel	*chan;

  if (msg->param_count < 1)
    reply_response(serv, fd, ERR_NEEDMOREPARAMS, 0);
  else
    {
      chan_index = 0;
      get_next_chan(chan_name, msg->param[0], chan_index);
      while (chan_name[0])
	{
	  if (!check_chan(chan_name))
	    reply_response(serv, fd, ERR_NOSUCHCHANNEL, 0);
	  else if (chan = get_chan(serv->channel, chan_name))
	    {
	      if (!check_key(chan, chan_index, msg->param[1]))
		reply_response(serv, fd, ERR_BADCHANNELKEY, 0);
	      else if (!user_in_chan(serv, fd, chan))
		add_client_to_chan(serv, fd, chan);
	    }
	  else
	    {
	      chan = create_chan(serv, chan_name);
	      add_client_to_chan(serv, fd, chan);
	      reply_reponse(serv, fd, RPL_NOTOPIC, chan);
	      reply_response(serv, fd, RPL_NAMREPLY, chan);
	      reply_response(serv, fd, RPL_ENDOFNAMES, chan);
	    }
	  chan_index++;
	  get_next_chan(chan_name, msg->param[0], chan_index);
	}
    }
}
