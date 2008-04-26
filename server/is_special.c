/*
** is_special.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 14:25:29 2008 julian kirtz
** Last update Thu Apr 24 14:29:51 2008 julian kirtz
*/

char	is_special(char c)
{
  if ((c >= '[' && c <= '`') || (c >= '{' && c <= '}'))
    return (1);
  return (0);
}
