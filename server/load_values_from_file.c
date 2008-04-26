/*
** load_values_from_file.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 13:26:02 2008 julian kirtz
** Last update Thu Apr 24 19:57:03 2008 julian kirtz
*/

#include <stdio.h>
#include <string.h>
#include "../x/x.h"

char	*load_values_from_file(char *item, char *file)
{
  FILE	*fd;
  char	str[512];
  char	*value;
  char	*sp;

  fd = fopen(file, "r");
  value = 0;
  while (!feof(fd))
    {
      fgets(str, 512, fd);
      if (sp = strrchr(str, '\n'))
	*sp =  '\0';
      if (sp = strchr(str, '='))
	*sp = '\0';
      if (strcmp(item, str) == 0 && strlen(sp + 1))
	{
	  value = xmalloc(sizeof(char) * (strlen(sp + 1) + 1));
	  value = strcpy(value, sp + 1);
	  printf("Value: [%s]\n", value);
	  break;
	}
    }
  fclose(fd);
  return (value);
}
