/*
** reply_error.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 21:56:59 2008 julian kirtz
** Last update Sun Apr 27 13:50:19 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

void	reply_error(t_server *serv, int fd, t_message *msg)
{
  serv = 0;
  fd = 0;
  msg= 0;
  /*
    int	i;
  int	len;

  i = 0;
  while (i < CLIENT_WRITE_BUF_LINE && serv->client[fd].buffer_write[i][0])
    i++;
  if (i < CLIENT_WRITE_BUF_LINE)
    {
      
      len = strlen(text);
      if (len > CLIENT_WRITE_BUF_SIZE - 2)
	{
	  serv->client[fd].buffer_write[i][CLIENT_WRITE_BUF_SIZE - 2] = '\r';
	  serv->client[fd].buffer_write[i][CLIENT_WRITE_BUF_SIZE - 2] = '\n';
	}
      else
	{
	  serv->client[fd].buffer_write[i][len] = '\r';
	  serv->client[fd].buffer_write[i][len] = '\n';
	}
    }
  */
}
