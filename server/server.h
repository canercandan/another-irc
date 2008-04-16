/*
** server.h for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Wed Apr 16 14:48:23 2008 julian kirtz
** Last update Wed Apr 16 15:49:24 2008 julian kirtz
*/

#ifndef __SERVER_H__
#define __SERVER_H__

#define MAX_FD		64
#define MAX_LISTEN	128
#define MAX_PORT	6

#define FD_FREE		0
#define FD_CLIENT	1
#define	FD_SERVER	2

#define TIMEOUT_SELECT	10

#define SERVER_CFG_FILE	"server.cfg"
#define PORT_ITEM	"PORT"

typedef void		(*fct)();

typedef struct		s_server
{
  char			fd_type[MAX_FD];
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
  int			port[MAX_PORT];
  char			ip;
  struct timeval	timeout;
}			t_server;

void	create_server(t_server *serv);
void	cfg_port(int *port);
void    cfg_timeout();
void    cfg_ip(void *foo);
char	*load_values_from_file(char *item, char *file);
void	offset_to_next_value(int *offset, char *str, char sep);

#endif
