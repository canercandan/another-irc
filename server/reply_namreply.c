/*
** reply_namreply.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Sat Apr 26 20:12:46 2008 julian kirtz
** Last update Sun Apr 27 13:51:44 2008 julian kirtz
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include "server.h"

char	*part_of_nicklist(char *nicklist, int *offset, int max)
{
  int	i;
  char	*part;

  part = &(nicklist[*offset]);
  i = *offset;
  while (1)
    {
      if (nicklist[i] == '\0')
	return (0);
      if (i == max)
	{
	  nicklist[*offset] = '\0';
	  (*offset)++;
	  break;
	}
      if (nicklist[i] == ' ')
	*offset += i;
      i++;
    }
  return (part);
}

int	reply_namreply(t_server *serv, int fd, int index, void *chan)
{
  int		len;
  static char	*nicklist = 0;
  static int	offset = 0;
  char		*nicklistpart;

  if (nicklist == 0)
    {
      offset = 0;
      nicklist = nicklist_of_chan(chan);
    }
  len = strlen(serv->client[fd].buffer_write[index]);
  nicklistpart = part_of_nicklist(nicklist, &offset,
				  CLIENT_WRITE_BUF_SIZE - len - 2);
  if (nicklistpart)
    sprintf(serv->client[fd].buffer_write[index],
	    RPL_NAMREPLY_FORMAT, ((t_channel *)chan)->name, nicklistpart);
  else
    {
      free(nicklist);
      nicklist = 0;
      return (0);
    }
  return (1);
}
