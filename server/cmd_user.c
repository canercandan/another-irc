/*
** cmd_user.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 13:51:49 2008 julian kirtz
** Last update Sun Apr 27 16:15:55 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"

void	cmd_user(t_server *serv, int fd, t_message *msg)
{
  if (serv->client[fd].registered)
    reply_response(serv, fd, ERR_ALREADYREGISTRED, 0);
  else if (!(serv->client[fd].keyed) || !(serv->client[fd].nick[0]))
    delete_client(serv, fd);
  else if (msg->param_count < 4)
    reply_response(serv, fd, ERR_NEEDMOREPARAMS, 0);
  else
    {
      serv->client[fd].username = strdup(msg->param[0]);
      serv->client[fd].realname = strdup(msg->param[3]);
      serv->client[fd].registered = 1;
      reply_response(serv, fd, RPL_WELCOME, 0);
      reply_response(serv, fd, RPL_YOURHOST, 0);
      reply_response(serv, fd, RPL_CREATED, 0);
      reply_response(serv, fd, RPL_MYINFO, 0);
      reply_response(serv, fd, RPL_LUSERCLIENT, 0);
      reply_response(serv, fd, RPL_LUSEROP, 0);
      reply_response(serv, fd, RPL_LUSERUNKNOWN, 0);
      reply_response(serv, fd, RPL_LUSERCHANNELS, 0);
      reply_response(serv, fd, RPL_LUSERME, 0);
    }
}
