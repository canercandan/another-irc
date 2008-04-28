/*
** listen_from_server.c for my_irc in /home/candan_c/cu/rendu/project/my_irc/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 16:15:37 2008 caner candan
** Last update Mon Apr 28 04:49:17 2008 caner candan
*/

#include <gtk/gtk.h>
#include <strings.h>
#include "client.h"
#include "x.h"

int	listen_from_server(void *io, int condition, void *cnt)
{
  char	buf[512];
  int	nbr;

  (void) io;
  (void) condition;
  debug("listen_from_server()");
  bzero(buf, sizeof(buf));
  if ((nbr = xrecv(((t_cnt *) cnt)->socket, buf, sizeof(buf), 0)) > 0)
    insert_mesg_to_list(cnt, EMPTY, ((t_cnt *) cnt)->nick, buf);
  return (0);
}
