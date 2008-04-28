/*
** extract_msg.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Tue Apr 22 18:32:32 2008 julian kirtz
** Last update Sun Apr 27 22:49:42 2008 julian kirtz
*/

#include <stdio.h>
#include <sys/time.h>
#include "server.h"
#include "x.h"

void	skip_space(char **amsg)
{
  while (**amsg && **amsg == SP)
    (*amsg)++;
}

void	extract_prefix(char **amsg, t_message *msg)
{
  int	i;

  msg->prefix = 0;
  i = 0;
  if ((*amsg)[i] == ':')
    {
      (*amsg)++;
      while ((*amsg)[i] && (*amsg)[i] != SP)
	i++;
      if (i)
	{
	  msg->prefix = xmalloc(sizeof(*(msg->prefix)) * (i + 1));
	  i = 0;
	  while ((*amsg)[i] && (*amsg)[i] != SP)
	    {
	      msg->prefix[i] = (*amsg)[i];
	      i++;
	    }
	  msg->prefix[i] = '\0';
	  *amsg += i;
	}
    }
}

void	extract_command(char **amsg, t_message *msg)
{
  int	i;

  msg->command = 0;
  i = 0;
  skip_space(amsg);
  while ((*amsg)[i] && (*amsg)[i] != SP)
    i++;
  if (i)
    {
      msg->command = xmalloc(sizeof(*(msg->command)) * (i + 1));
      i = 0;
      while ((*amsg)[i] && (*amsg)[i] != SP)
	{
	  msg->command[i] = (*amsg)[i];
	  i++;
	}
      msg->command[i] = '\0';
      *amsg += i;
    }
}

void	middle_param(char **amsg, t_message *msg, int count)
{
  int	i;

  msg->param[count] = 0;
  i = 0;
  if ((*amsg)[i] && (*amsg)[i] != '\r' && (*amsg)[i] != '\n'
      && (*amsg)[i] != ' ' && (*amsg)[i] != ':')
    {
      i++;
      while ((*amsg)[i] && (*amsg)[i] != '\r' && (*amsg)[i] != '\n'
	     && (*amsg)[i] != ' ')
	i++;
      msg->param[count] = xmalloc(sizeof(*(msg->param[count])) * (i + 1));
      i = 0;
      while ((*amsg)[i] && (*amsg)[i] != '\r' && (*amsg)[i] != '\n'
	     && (*amsg)[i] != ' ')
	{
	  msg->param[count][i] = (*amsg)[i];
	  i++;
	}
      msg->param[count][i] = '\0';
      *amsg += i;
    }
}

void	trailing_param(char **amsg, t_message *msg, int count)
{
  int	i;

  msg->param[count] = 0;
  i = 0;
  while ((*amsg)[i] && (*amsg)[i] != '\r' && (*amsg)[i] != '\n')
    i++;
  if (i)
    {
      msg->param[count] = xmalloc(sizeof(*(msg->param[count])) * (i + 1));
      i = 0;
      while ((*amsg)[i] && (*amsg)[i] != '\r' && (*amsg)[i] != '\n')
	{
	  msg->param[count][i] = (*amsg)[i];
	  i++;
	}
      msg->param[count][i] = '\0';
      *amsg += i;
    }
}

void	extract_params(char **amsg, t_message *msg)
{
  int	i;
  int	count;

  i = 0;
  msg->param_count = 0;
  skip_space(amsg);
  while (**amsg && msg->param_count < MAX_CMD_PARAMS - 1)
    {
      if (**amsg != ':')
	middle_param(amsg, msg, msg->param_count);
      else
	break;
      msg->param_count++;
      skip_space(amsg);
    }
  if (**amsg)
    trailing_param(amsg, msg, (msg->param_count)++);
  count = msg->param_count;
  while (count < MAX_CMD_PARAMS)
    msg->param[count++] = 0;
}

void	extract_msg(char *amsg, t_message *msg)
{
  extract_prefix(&amsg, msg);
  extract_command(&amsg, msg);
  extract_params(&amsg, msg);
}
