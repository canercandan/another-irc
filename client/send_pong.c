/*
** send_pong.c for my_irc in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Apr 28 07:24:09 2008 caner candan
** Last update Mon Apr 28 08:03:26 2008 caner candan
*/

#include <stdio.h>
#include "client.h"

int	send_pong(t_cnt *cnt, t_message *msg)
{
  char	buf[200];

  debug("send_pong()");
  (void) msg;
  snprintf(buf, sizeof(buf), MESG_PONG, (char *) cnt->nick);
  send_to_server(cnt, buf);
  return (0);
}
