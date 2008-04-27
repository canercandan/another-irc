/*
** xsocket.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:48:00 2008 caner candan
** Last update Sun Apr 27 11:48:00 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xsocket(int domain, int type, int protocol)
{
  int	s;

  if ((s = socket(domain, type, protocol)) < 0)
    {
      fprintf(stderr, "Error with socket()\n");
      close(s);
      exit(FALSE);
    }
  return (s);
}
