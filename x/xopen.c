/*
** xopen.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:47:37 2008 caner candan
** Last update Sun Apr 27 14:25:15 2008 caner candan
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "x.h"

int	xopen(char *path, int flags)
{
  int	fd;

  if ((fd = open(path, flags)) < 0)
    perror("open");
  return (fd);
}
