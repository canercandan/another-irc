/*
** xfork.c for x in /home/candan_c/cu/rendu/project/my_irc/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 11:47:04 2008 caner candan
** Last update Sun Apr 27 11:47:05 2008 caner candan
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	xfork()
{
  int	pid;

  if ((pid = fork()) < 0)
    {
      perror("fork");
      exit(-1);
    }
  return (pid);
}
