/*
** cfg_timeout.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 12:47:36 2008 julian kirtz
** Last update Wed Apr 16 15:16:36 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

void	cfg_timeout(struct timeval *tv)
{
    tv->tv_sec = TIMEOUT_SELECT;
    tv->tv_usec = 0;
}
