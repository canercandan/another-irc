/*
** trim.c for my_irc in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Apr 28 05:10:16 2008 caner candan
** Last update Mon Apr 28 05:12:56 2008 caner candan
*/

#include <string.h>
#include "client.h"

char	*trim(char *s)
{
  int	i;

  for (i = 0; s[i]; i++)
    if (s[i] == '\n' || s[i] == '\r')
      {
	s[i] = '\0';
	break;
      }
  return (s);
}
