/*
** xbind.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:48:26 2008 caner candan
** Last update Sun Apr 27 14:23:00 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xbind(int s, const void *addr, void *addrlen)
{
  int	rc;

  if ((rc = bind(s, (struct sockaddr *) addr,
		 (socklen_t) addrlen)) < 0)
    {
      perror("bind");
      close(s);
    }
  return (rc);
}
