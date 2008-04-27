/*
** main.c for my_irc in /home/candan_c/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:23:57 2008 caner candan
** Last update Sun Apr 27 13:40:43 2008 julian kirtz
*/

#include <stdio.h>
#include <sys/time.h>
#include "server.h"

int		main()
{
  t_server	serv;

  create_server(&serv);
  while (1)
    {
      init_all_fd(&serv);
      if (select(serv.fd_max + 1, &(serv.fd_read),
		 &(serv.fd_write), 0, &(serv.timeout)) < 0)
	printf("Error: select\n");
      read_all_fd(&serv);
    }
  return (0);
}
