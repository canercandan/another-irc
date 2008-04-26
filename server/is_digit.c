/*
** is_digit.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 14:24:01 2008 julian kirtz
** Last update Thu Apr 24 14:25:08 2008 julian kirtz
*/

char	is_digit(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
