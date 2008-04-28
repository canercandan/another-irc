/*
** freelist.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sun Apr 27 19:37:55 2008 julian kirtz
** Last update Sun Apr 27 20:52:04 2008 julian kirtz
*/

#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

void	freelist(t_list *list)
{
  if (list)
    freelist(list->next);
  free(list);
}
