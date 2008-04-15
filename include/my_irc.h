/*
** my_irc.h for my_irc in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 15 00:19:15 2008 caner candan
** Last update Tue Apr 15 02:51:00 2008 caner candan
*/

#ifndef __MY_IRC_H__
# define __MY_IRC_H__

/*
** Main defines
*/

# define DEBUG	1

/*
** Return's values
*/

# define FALSE		-1
# define TRUE		0
# define WAIT		1
# define ERROR		2
# define QUIT		3
# define EMPTY		4
# define DENIED		5

/*
** Level's values
*/

# define GUEST		1
# define USER		2
# define ADMIN		3

/*
** Default's values
*/

# define PORT_DEF	"12345"
# define HOST_DEF	"localhost"

/*
** Null value
*/

# ifndef NULL
#  define NULL	0
# endif /* !NULL */

/*
** Connection's data
*/

typedef struct	s_irc
{
  char		*host;
  char		*port;
  char		*user;
  int		s;
  int		cs;
  int		cnt;
}		t_irc;

typedef struct	s_pkt
{
  char		*cmd;
  char		*param1;
  char		*param2;
  char		*param3;
  t_irc		*irc;
}		t_pkt;

typedef struct	s_req
{
  char		*req;
  int		(*f)();
  char		*cmd;
  char		*opt;
  int		lvl;
}		t_req;

#endif /* !__MY_IRC_H__ */
