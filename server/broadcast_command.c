/*
** broadcast_command.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sun Apr 27 16:59:41 2008 julian kirtz
** Last update Mon Apr 28 00:50:34 2008 julian kirtz
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include "server.h"
#include "x.h"

void	broadcast_command(t_server *serv, int fd, t_channel *chan, t_message *msg)
{
  int		i;
  int		len;
  char		bmsg[CLIENT_WRITE_BUF_SIZE];
  char		*params;
  t_list	*current;

  params = 0;
  len = 0;
  for (i = 0; i < msg->param_count; i++)
    {
      if (params)
	len = strlen(params);
      params = xrealloc(params, sizeof(char) * (len + strlen(msg->param[i]) + 1));
      sprintf(params + len, " %s", msg->param[i]);
    }
  if (params)
    sprintf(bmsg, "%s!%s %s%s\r\n", serv->client[fd].nick, serv->hostname, msg->command, params);
  else
    sprintf(bmsg, "%s!%s %s noreason\r\n", serv->client[fd].nick, serv->hostname, msg->command);
  current = chan->client;
  while (current)
    {
      i = 0;
      while (i < CLIENT_WRITE_BUF_LINE &&
	     ((t_client *)current->data)->buffer_write[i][0])
	i++;
      if (i < CLIENT_WRITE_BUF_LINE)
	sprintf(((t_client *)current->data)->buffer_write[i], "%s", bmsg);
      current = current->next;
    }
  free(params);
}
