/*
** create_socket.c for my_irc in /home/candan_c/cu/rendu/project/my_irc/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 14:47:04 2008 caner candan
** Last update Sun Apr 27 14:47:37 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include "client.h"

int			create_socket(t_cnt *cnt)
{
  struct sockaddr_in	addr;
  struct hostent	*h;
  struct protoent	*pe;
  struct in_addr	in;

  pe = getprotobyname("tcp");
  if ((cnt->socket = socket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    return (-1);
  addr.sin_family = AF_INET;
  printf("Resolving %s ...\n", (char *) cnt->host);
  h = gethostbyname(cnt->host);
  bcopy(h->h_addr, &in, sizeof(in));
  addr.sin_port = htons(atoi(cnt->port));
  addr.sin_addr.s_addr = inet_addr(inet_ntoa(in));
  return (connect(cnt->socket, (struct sockaddr *) &addr, sizeof(addr)));
}
