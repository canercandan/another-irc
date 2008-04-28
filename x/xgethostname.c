/*
** xgethostname.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:47:14 2008 caner candan
** Last update Mon Apr 28 08:33:30 2008 julian kirtz
*/

#include <unistd.h>
#include "x.h"

void			*xgethostname(char *name, int size)
{
  if (gethostname(name, size) == -1)
    {
      perror("Could not get hostname.");
      exit(-1);
    }
}
