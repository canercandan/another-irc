/*
** debug.c for my_irc in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Apr 28 02:00:27 2008 caner candan
** Last update Mon Apr 28 02:02:40 2008 caner candan
*/

#include <string.h>
#include <unistd.h>
#include "client.h"

void	debug(char *s)
{
  if (DEBUG)
    {
      write(1, s, strlen(s));
      write(1, "\n", 2);
    }
}
