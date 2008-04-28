/*
** cmd_part.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 28 01:14:53 2008 julian kirtz
** Last update Mon Apr 28 02:33:00 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"

void		cmd_part(t_server *serv, int fd, t_message *msg)
{
  t_list	*current;
  t_channel	*chan;

  if (msg->param_count < 1)
    reply_response(serv, fd, ERR_NEEDMOREPARAMS, 0);
  else if (!(chan = get_chan(serv->channel, msg->param[0])))
    reply_response(serv, fd, ERR_NOSUCHCHANNEL, 0);
  else if (user_in_chan(serv, fd, chan))
    {
      current = serv->client[fd].channel;
      while (current)
	{
	  if (strncmp(((t_channel *)current->data)->name, msg->param[0], MAX_CHAN_LEN) == 0)
	    {
	      if (delete_client_from_chan(&(serv->client[fd]), ((t_channel *)current->data)))
		broadcast_command(serv, fd, ((t_channel *)current->data), msg);
	      else
		delete_chan(serv, ((t_channel *)current->data));
	    }
	  current = current->next;
	}
    }
}
