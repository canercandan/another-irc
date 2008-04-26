/*
** do_command.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 23 13:51:38 2008 julian kirtz
** Last update Sat Apr 26 17:59:26 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"

t_command	t_cmd[] =
  {
    {"PASS", cmd_pass},
    {"NICK", cmd_nick},
    {"USER", cmd_user},
    {"QUIT", cmd_quit},
    {"JOIN", cmd_join},
    {0, 0}
  };

void	do_command(t_server *serv, int fd, t_message *msg)
{
  int	i;

  if (msg->command)
    for (i = 0; t_cmd[i].cmd != 0; i++)
      if (strcasecmp(msg->command, t_cmd[i].cmd) == 0)
	t_cmd[i].func(serv, fd, msg);
}
