/*
** xrealloc.c for x in /home/candan_c/cu/rendu/project/my_irc/x
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:51:17 2008 caner candan
** Last update Sun Apr 27 14:25:27 2008 caner candan
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
      perror("xrealloc: not enough memory");
      exit(EXIT_FAIL);
    }
  return (p);
}
