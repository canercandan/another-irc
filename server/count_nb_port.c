/*
** count_nb_port.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 21 12:15:45 2008 julian kirtz
** Last update Mon Apr 21 14:11:08 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

int	count_nb_port(int *port)
{
  int	i;

  i = 0;
  while (i < MAX_PORT && port[i] != 0)
    i++;
  return (i);
}
