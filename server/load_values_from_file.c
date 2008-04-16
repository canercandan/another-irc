/*
** load_values_from_file.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 13:26:02 2008 julian kirtz
** Last update Wed Apr 16 15:29:06 2008 julian kirtz
*/

#include <stdio.h>
#include <string.h>
#include "../x/x.h"

char	*load_values_from_file(char *item, char *file)
{
  FILE	*fd;
  char	*str;
  char	*value;
  char	*sp;

  fd = fopen(file, "r");
  str = 0;
  value = 0;
  while (feof(fd))
    {
      free(str);
      str = fgets(str, 512, fd);
      sp = strchr(str, '=');
      *sp = '\0';
      if (strcmp(item, str) == 0)
	{
	  value = xmalloc(sizeof(char) * (strlen(sp + 1) + 1));
	  value = strcpy(value, sp + 1);
	  break;
	}
    }
  free(str);
  fclose(fd);
  return (value);
}
