/*
** create_server.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 11:54:59 2008 julian kirtz
** Last update Mon Apr 28 08:55:51 2008 julian kirtz
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"
#include "x.h"

void			create_server(t_server *serv)
{
  int			s;
  int			i;
  struct sockaddr_in	sin;
  int			nb_port;

  memset(serv->fd_type, FD_FREE, MAX_FD * sizeof(int));
  xgethostname(serv->hostname, MAX_HOST_NAME_LEN);
  cfg_port(serv->port);
  cfg_timeout(&(serv->timeout));
  cfg_key(&(serv->key));
  nb_port = count_nb_port(serv->port);
  printf("*** IRC Server  ***\n");
  for (i = 0; i < nb_port; i++)
    {
      s = socket(PF_INET, SOCK_STREAM, 0);
      sin.sin_family = AF_INET;
      sin.sin_port = htons(serv->port[i]);
      sin.sin_addr.s_addr = INADDR_ANY;
      bind(s, (struct sockaddr *)&sin, sizeof(sin));
      listen(s, MAX_LISTEN);
      printf("Listen on port: %d\n", serv->port[i]);
      serv->fd_type[s] = FD_SERVER;
      serv->fct_read[s] = server_socket_read;
      serv->fct_write[s] = 0;
    }
  serv->channel = 0;
}
