/*
** xgethostbyname.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:47:14 2008 caner candan
** Last update Sun Apr 27 14:14:44 2008 caner candan
*/

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include "x.h"

void			*xgethostbyname(const char *name)
{
  struct hostent	*h;

  if (!(h = gethostbyname(name)))
    perror("gethostbyname");
  return (h);
}
