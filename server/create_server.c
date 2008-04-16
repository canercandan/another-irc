/*
** create_server.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 11:54:59 2008 julian kirtz
** Last update Wed Apr 16 15:44:28 2008 julian kirtz
*/

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"

void			create_server(t_server *serv)
{
  int			s;
  int			i;
  struct sockaddr_in	sin;

  memset(serv->fd_type, FD_FREE, MAX_FD);
  cfg_port(serv->port);
  cfg_ip(serv->ip);
  for (i = 0; serv->port[i]; i++)
    {
      s = xsocket(PF_INET, SOCK_STREAM, 0);
      sin.sin_family = AF_INET;
      sin.sin_port = serv->port[i];
      sin.sin_addr.s_addr = INADDR_ANY; //voir pour utiliser les ip du fichier de conf
      bind(s, (struct sockaddr *)&sin, sizeof(sin));
      listen(s, MAX_LISTEN);
      serv->fd_type[s] = FD_SERVER;
      serv->fct_read[s] = server_socket_read;
      serv->fct_write[s] = 0;
    }
  cfg_timeout(serv->timeout);
}
