/*
** mesg_init.c for my_irc in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Apr 28 07:25:06 2008 caner candan
** Last update Mon Apr 28 07:55:52 2008 caner candan
*/

#include <string.h>
#include "client.h"

t_fct	gl_fct[] = {
  {RET_PING, send_pong},
  {"343", send_list},
  {0, 0}
};

int	mesg_init(t_cnt *cnt, t_message *msg)
{
  int	i;

  debug("mesg_init()");
  for (i = 0; gl_fct[i].mesg; i++)
    if (!strcmp(gl_fct[i].mesg, msg->command))
      return (gl_fct[i].f(cnt, msg));
  return (0);
}
