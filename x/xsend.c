/*
** xsend.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:47:54 2008 caner candan
** Last update Sun Apr 27 11:47:54 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xsend(int s, const void *msg, int len, int flags)
{
  int	rc;

  if ((rc = send(s, msg, (size_t) len, flags)) < 0)
    {
      fprintf(stderr, "Error with send()\n");
      close(s);
      exit(FALSE);
    }
  return (rc);
}
