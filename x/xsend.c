/*
** xsend.c for my_irc in /home/candan_c/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:51:31 2008 caner candan
** Last update Tue Apr 15 00:33:08 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_irc.h"

void	*xsend(int s, const void *msg, void *len, int flags)
{
  void	*rc;

  if ((int) (rc = (void *) send(s, msg, (size_t) len, flags)) < 0)
    {
      fprintf(stderr, "Error with send()\n");
      close(s);
      exit(FALSE);
    }
  return (rc);
}
