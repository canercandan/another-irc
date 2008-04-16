/*
** cfg_port.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 12:53:08 2008 julian kirtz
** Last update Wed Apr 16 15:13:22 2008 julian kirtz
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
  memset(port, 0, MAX_PORT);
  offset = 0;
  i = 0;
  while (values[offset])
    {
      offset_to_next_value(&offset, values, ',');
      port[i++] = atoi(&(values[offset]));
    }
  free(values);
}
