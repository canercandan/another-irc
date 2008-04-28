/*
** init_server.c for my_irc in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Apr 28 06:15:40 2008 caner candan
** Last update Mon Apr 28 06:39:25 2008 caner candan
*/

#include <stdio.h>
#include "client.h"

int	init_server(t_cnt *cnt)
{
  char	buf[200];

  debug("init_server()");
  snprintf(buf, sizeof(buf), MESG_PASS, EMPTY);
  send_to_server(cnt, buf);
  snprintf(buf, sizeof(buf), MESG_NICK, (char *) cnt->nick);
  send_to_server(cnt, buf);
  snprintf(buf, sizeof(buf), MESG_USER, (char *) cnt->real, MODE, MODE, MODE);
  send_to_server(cnt, buf);
  return (0);
}
