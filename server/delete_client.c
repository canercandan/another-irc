/*
** delete_client.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 15:42:19 2008 julian kirtz
** Last update Sun Apr 27 19:36:25 2008 julian kirtz
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include "server.h"

void	delete_client(t_server *serv, int fd)
{
  close(fd);
  free(serv->client[fd].realname);
  free(serv->client[fd].username);
  freelist(serv->client[fd].channel);
  init_client(serv, fd);
  serv->fd_type[fd] = FD_FREE;
}
