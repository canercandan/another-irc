/*
** xconnect.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:48:11 2008 caner candan
** Last update Sun Apr 27 11:48:12 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xconnect(int s, const void *name, void *namelen)
{
  int	rc;

  if ((rc = connect(s, (struct sockaddr *) name,
		    (socklen_t) namelen)) < 0)
    {
      fprintf(stderr, "Error with connect()\n");
      close(s);
      exit(FALSE);
    }
  return (s);
}
