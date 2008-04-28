/*
** init_client.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 21 17:53:37 2008 julian kirtz
** Last update Sun Apr 27 21:39:54 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"

void	init_client(t_server *serv, int fd)
{
  int	i;

  memset(serv->client[fd].buffer_read, '\0', CLIENT_READ_BUF_SIZE);
  serv->client[fd].buffer_offset = 0;
  for (i = 0; i < CLIENT_WRITE_BUF_LINE; i++)
    memset(serv->client[fd].buffer_write[i], '\0', CLIENT_WRITE_BUF_LINE);
  memset(serv->client[fd].nick, 0, MAX_NICK_LEN + 1);
  serv->client[fd].mode = 0;
  serv->client[fd].username = 0;
  serv->client[fd].realname = 0;
  serv->client[fd].channel = 0;
  serv->client[fd].registered = 0;
  serv->client[fd].keyed = serv->key ? 0 : 1;
}
