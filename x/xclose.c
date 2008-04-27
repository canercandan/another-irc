/*
** xclose.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:48:18 2008 caner candan
** Last update Sun Apr 27 14:21:58 2008 caner candan
*/

#include <unistd.h>
#include <stdio.h>
#include "x.h"

int	xclose(int fd)
{
  int	rc;

  if ((rc = close(fd)) < 0)
    perror("close");
  return (rc);
}
