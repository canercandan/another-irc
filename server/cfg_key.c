/*
** cfg_key.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Mon Apr 21 15:57:22 2008 julian kirtz
** Last update Mon Apr 21 16:32:24 2008 julian kirtz
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"

void	cfg_key(char **key)
{
  *key = load_values_from_file(KEY_ITEM, SERVER_CFG_FILE);
}
