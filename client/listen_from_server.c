/*
** listen_from_server.c for my_irc in /home/candan_c/cu/rendu/project/my_irc/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 16:15:37 2008 caner candan
** Last update Sun Apr 27 19:50:45 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include "client.h"

int		listen_from_server(void *xml, t_cnt *c)
{
  static t_cnt	*cnt = NULL;
  char		buf[512];
  int		nbr;

  (void)xml;
  if (cnt == NULL)
    {
      if (c == NULL)
	return (-1);
      cnt = c;
      return (0);
    }
  while (42)
    {
      bzero(buf, sizeof(buf));
      if ((nbr = recv(cnt->socket, buf, sizeof(buf), 0)) > 0)
	{
	  if (strstr(buf, ENDLINE) == NULL)
	    {
	      perror("strstr");
	      return (-1);
	    }
	  write(1, buf, nbr);
	  write(1, "\n", 2);
	}
    }
  return (0);
}
