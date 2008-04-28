/*
** cmd_quit.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 20:53:51 2008 julian kirtz
** Last update Mon Apr 28 00:40:07 2008 julian kirtz
*/

#include <stdio.h>
#include <sys/time.h>
#include "server.h"

void		cmd_quit(t_server *serv, int fd, t_message *msg)
{
  t_list	*current;

  current = serv->client[fd].channel;
  while (current)
  {
    if (delete_client_from_chan(&(serv->client[fd]), ((t_channel *)current->data)))
      broadcast_command(serv, fd, ((t_channel *)current->data), msg);
    else
      delete_chan(serv, ((t_channel *)current->data));
    current = current->next;
  }
  delete_client(serv, fd);
}
