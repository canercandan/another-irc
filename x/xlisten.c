/*
** xlisten.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:47:23 2008 caner candan
** Last update Sun Apr 27 11:47:24 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "x.h"

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
