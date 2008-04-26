/*
** cmd_nick.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 13:32:59 2008 julian kirtz
** Last update Thu Apr 24 19:46:06 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"

char	check_nick(char *nick)
{
  int	i;

  if (is_letter(nick[0]) || is_special(nick[0]))
    {
      for (i = 0; i < MAX_NICK_LEN && nick[i]; i++)
	if (!is_letter(nick[i])
	    && !is_special(nick[i])
	    && !is_digit(nick[i])
	    && nick[i] != '-')
	  return (0);
      return (1);
    }
  return (0);
}

char	nick_used(char *nick, t_server *serv)
{
  int	i;

  for (i = 0; i < MAX_FD; i++)
    if (strcmp(nick, serv->client[i].nick) == 0)
      return (0);
  return (1);
}

void	cmd_nick(t_server *serv, int fd, t_message *msg)
{
  if (!msg->param[0])
    reply_response(serv, fd, ERR_NONICKNAMEGIVEN, 0);
  else if (!check_nick(msg->param[0]))
    reply_response(serv, fd, ERR_ERRONEUSNICKNAME, 0);
  else if (!nick_used(msg->param[0], serv))
    reply_response(serv, fd, ERR_NICKNAMEINUSE, 0);
  else
    {
      strncpy(serv->client[fd].nick, msg->param[0], MAX_NICK_LEN);
      serv->client[fd].nick[MAX_NICK_LEN] = '\0';
    }
}
