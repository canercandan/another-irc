/*
** cfg_port.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 12:53:08 2008 julian kirtz
** Last update Mon Apr 21 15:59:48 2008 julian kirtz
*/

#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

void	cfg_port(int *port)
{
  char	*values;
  int	offset;
  int	i;

  values = load_values_from_file(PORT_ITEM, SERVER_CFG_FILE);
  memset(port, 0, MAX_PORT * sizeof(int));
  offset = 0;
  i = 0;
  if (values)
    {
      offset_to_next_value(&offset, values, 0);
      while (values[offset])
	{
	  port[i++] = atoi(&(values[offset]));
	  offset_to_next_value(&offset, values, ',');
	}
      free(values);
    }
}
