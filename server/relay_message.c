/*
** relay_message.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 28 06:14:45 2008 julian kirtz
** Last update Mon Apr 28 06:45:39 2008 julian kirtz
*/

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"

void	relay_message(t_server *serv, int fd, t_message *msg, t_client *client)
{
  int	i;
  int	len;

  i = 0;
  while (i < CLIENT_WRITE_BUF_LINE && client->buffer_write[i][0])
    i++;
  if (i < CLIENT_WRITE_BUF_LINE)
    {
      snprintf(client->buffer_write[i], CLIENT_WRITE_BUF_LINE - 2,
	       "%s!%s %s %s %s", serv->client[fd].nick,
	       serv->hostname, msg->command, client->nick, msg->param[0]);
      len = strlen(client->buffer_write[i]);
      client->buffer_write[i][len] = '\r';
      client->buffer_write[i][len + 1] = '\n';
    }
}
