/*
** cmd_pass.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 11:41:30 2008 julian kirtz
** Last update Thu Apr 24 18:25:03 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"

void	cmd_pass(t_server *serv, int fd, t_message *msg)
{
  if (serv->client[fd].registered)
    reply_response(serv, fd, ERR_ALREADYREGISTRED, 0);
  if (msg->param_count < 1)
    reply_response(serv, fd, ERR_NEEDMOREPARAMS, 0);
  else if (serv->key && strncmp(msg->param[0], serv->key, strlen(serv->key)))
    serv->client[fd].keyed = 0;
  else
    serv->client[fd].keyed = 1;
}
