/*
** cmd_privmsg.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 28 04:20:01 2008 julian kirtz
** Last update Mon Apr 28 06:14:19 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

void		cmd_privmsg(t_server *serv, int fd, t_message *msg)
{
  t_client	*user;
  t_channel	*chan;

  if (msg->param_count < 1)
    reply_response(serv, fd, ERR_NORECIPIENT, 0);
  else if (msg->param_count < 2 && msg->param[0][0] == ':')
    reply_response(serv, fd, ERR_NORECIPIENT, 0);
  else if (msg->param_count < 2 && msg->param[0][0] != ':')
    reply_response(serv, fd, ERR_NOTEXTTOSEND, 0);
  else if (msg->param[0][0] == '#')
    {
      if (!(chan = get_chan(serv->channel, msg->param[0])))
	reply_response(serv, fd, ERR_NORECIPIENT, 0);
      else
	broadcast_command(serv, fd, chan, msg);
    }
  else if (!(user = get_user(serv, msg->param[0])))
    reply_response(serv, fd, ERR_NOSUCHNICK, 0);
  else
    relay_message(serv, fd, msg, user);
}
