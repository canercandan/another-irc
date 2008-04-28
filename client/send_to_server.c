/*
** send_to_server.c for my_irc in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 19:55:13 2008 caner candan
** Last update Mon Apr 28 06:31:51 2008 caner candan
*/

#include <string.h>
#include <stdio.h>
#include "client.h"
#include "x.h"

int	send_to_server(t_cnt *cnt, char *mesg)
{
  debug("send_to_server()");
  mesg = strcat(mesg, ENDLINE);
  xsend(cnt->socket, mesg, strlen(mesg), 0);
  return (0);
}
