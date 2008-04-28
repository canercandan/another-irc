/*
** reply_response.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 16:49:41 2008 julian kirtz
** Last update Sun Apr 27 22:30:48 2008 julian kirtz
*/

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"

t_reply	t_rpl[] =
  {
    {RPL_NOTOPIC, reply_notopic},
    {RPL_NAMREPLY, reply_namreply},
    {RPL_ENDOFNAMES, reply_endofnames},
    {0, 0}
  };

int	reply_response(t_server *serv, int fd, char *numeric, void *info)
{
  int	i;
  int	j;
  int	len;
  int	ret;

  i = 0;
  while (i < CLIENT_WRITE_BUF_LINE && serv->client[fd].buffer_write[i][0])
    i++;
  if (i < CLIENT_WRITE_BUF_LINE)
    {
      sprintf(serv->client[fd].buffer_write[i], ":%s %s %s ", serv->hostname,
	      numeric, serv->client[fd].nick);
      if (info)
	{
	  for (j = 0; t_rpl[j].rpl != 0; j++)
	    if (strcmp(numeric, t_rpl[j].rpl) == 0)
	      ret = t_rpl[j].func(serv, fd, i, info);
	  if (strcmp(numeric, RPL_NAMREPLY) == 0 && ret)
	    reply_response(serv, fd, numeric, info);
	}
      len = strlen(serv->client[fd].buffer_write[i]);
      serv->client[fd].buffer_write[i][len] = '\r';
      serv->client[fd].buffer_write[i][len + 1] = '\n';
    }
  return (0);
}
