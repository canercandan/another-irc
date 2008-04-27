/*
** xmalloc.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:47:30 2008 caner candan
** Last update Sun Apr 27 14:24:59 2008 caner candan
*/

#include <stdlib.h>
#include <stdio.h>
#include "x.h"

void	*xmalloc(int size)
{
  void	*p;

  p = malloc(size);
  if (p == NULL)
    {
      perror("xmalloc: not enough memory");
      exit(EXIT_FAIL);
    }
  return (p);
}
