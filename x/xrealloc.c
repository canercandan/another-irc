/*
** xrealloc.c for x in /home/candan_c/cu/rendu/project/my_irc/x
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:51:17 2008 caner candan
** Last update Sun Apr 27 11:54:50 2008 caner candan
*/

#include <stdlib.h>
#include <stdio.h>
#include "x.h"

void	*xrealloc(void *ptr, int size)
{
  void	*p;

  p = realloc(ptr, size);
  if (p == NULL)
    {
      fprintf(stderr, "xrealloc: not enougth memory\n");
      exit(EXIT_FAIL);
    }
  return (p);
}
