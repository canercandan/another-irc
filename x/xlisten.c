/*
** xlisten.c for my_irc in /home/candan_c/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:34:47 2008 caner candan
** Last update Tue Apr 15 00:32:53 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_irc.h"

int	xlisten(int s, int backlog)
{
  int	rc;

  if ((rc = listen(s, backlog)) < 0)
    {
      fprintf(stderr, "Error with listen()\n");
      close(s);
      exit(FALSE);
    }
  return (rc);
}
