/*
** main.c for my_irc in /home/candan_c/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:23:57 2008 caner candan
** Last update Thu Apr 24 18:40:27 2008 julian kirtz
*/

#include <sys/time.h>
//#include "x.h"
#include "server.h"
//#include "my_irc.h"

int		main(int ac, char **av)
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
      //printf("Waiting\n");
    }
  return (0);
  //return (TRUE);
}
