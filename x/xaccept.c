/*
** xaccept.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:48:32 2008 caner candan
** Last update Sun Apr 27 14:22:27 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include "x.h"

int	xaccept(int s, void *addr, void *addrlen)
{
  int	sd;

  if ((sd = accept(s, (struct sockaddr *) addr,
		   (socklen_t *) addrlen)) < 0)
    perror("accept");
  return (sd);
}
