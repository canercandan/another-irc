/*
** get_next_message.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Tue Apr 22 14:14:40 2008 julian kirtz
** Last update Sun Apr 27 13:38:54 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"

void	get_next_message(char *buffer, char *amsg, int *offset)
{
  int	i;
  char	*ptr;

  i = 0;
  amsg[0] = -1;
  if (*offset != 0)
    {
      if ((ptr = strnstr(buffer, CRLF, CLIENT_READ_BUF_SIZE)))
	{
	  while (buffer + i != ptr)
	    {
	      amsg[i] = buffer[i];
	      i++;
	    }
	  amsg[i] = '\0';
	  ptr += strlen(CRLF);
	  i = 0;
	  while (ptr + i < buffer + *offset)
	    {
	      buffer[i] = buffer[ptr - buffer + i];
	      i++;
	    }
	  *offset = i;
	}
      else if ((ptr = strnstr(buffer, "\0", CLIENT_READ_BUF_SIZE)))
	*offset = ptr - buffer;
      else
	*offset = 0;
      memset(buffer + *offset, '\0', CLIENT_READ_BUF_SIZE - *offset);
    }
}
