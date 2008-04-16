/*
** offset_to_next_value.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 13:09:32 2008 julian kirtz
** Last update Wed Apr 16 13:21:23 2008 julian kirtz
*/

void	offset_to_next_value(int *offset, char *str, char sep)
{
  while (str[*offset] && (str[*offset] == ' ' || str[*offset] == sep))
    (*offset)++;
}
