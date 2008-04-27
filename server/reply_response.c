/*
** reply_response.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 16:49:41 2008 julian kirtz
** Last update Sun Apr 27 13:54:19 2008 julian kirtz
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
  int	len;
  int	ret;

  i = 0;
  while (i < CLIENT_WRITE_BUF_LINE && serv->client[fd].buffer_write[i][0])
    i++;
  if (i < CLIENT_WRITE_BUF_LINE)
    {
      snprintf(serv->client[fd].buffer_write[i], CLIENT_READ_BUF_SIZE,
	       ":%s %s %s ", serv->hostname, numeric, serv->client[fd].nick);
      if (info)
	{
	  for (i = 0; t_rpl[i].rpl != 0; i++)
	    if (strcmp(numeric, t_rpl[i].rpl) == 0)
	      ret = t_rpl[i].func(serv, fd, i, info);
	  if (strcmp(numeric, RPL_NAMREPLY) == 0 && ret)
	    reply_response(serv, fd, numeric, info);
	  /*
	  strcat(serv->client[fd].buffer_write[i], " ");
	  strncat(serv->client[fd].buffer_write[i], text, CLIENT_WRITE_BUF_SIZE
		  - strlen(serv->client[fd].buffer_write[i]));
	  */
	}
      len = strlen(serv->client[fd].buffer_write[i]);
      if (len > CLIENT_WRITE_BUF_SIZE - 2)
	{
	  serv->client[fd].buffer_write[i][CLIENT_WRITE_BUF_SIZE - 2] = '\r';
	  serv->client[fd].buffer_write[i][CLIENT_WRITE_BUF_SIZE - 1] = '\n';
	}
      else
	{
	  serv->client[fd].buffer_write[i][len] = '\r';
	  serv->client[fd].buffer_write[i][len + 1] = '\n';
	}
    }
  return (0);
}
