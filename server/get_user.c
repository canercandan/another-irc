/*
** get_user.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 28 05:44:22 2008 julian kirtz
** Last update Mon Apr 28 06:09:46 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

t_client	*get_user(t_server *serv, char *nick)
{
  int		i;

  i = 0;
  while (i < MAX_FD)
    {
      if (strncmp(serv->client[i].nick, nick, MAX_NICK_LEN) == 0)
	return (&(serv->client[i]));
      i++;
    }
  retrun (0);
}
