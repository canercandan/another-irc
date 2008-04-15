/*
** x.h for x in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 15 02:12:52 2008 caner candan
** Last update Tue Apr 15 02:48:00 2008 caner candan
*/

#ifndef __X_H__
# define __X_H__

/*
** Socket's functions
*/

int	xaccept(int s, void *addr, void *addrlen);
int	xbind(int s, const void *addr, void *addrlen);
int	xconnect(int s, const void *name, void *namelen);
int	xlisten(int s, int backlog);
void	*xrecv(int s, void *buf, void *len, int flags);
void	*xsend(int s, const void *msg, void *len, int flags);
int	xsocket(int domain, int type, int protocol);

#endif /* !__X_H__ */
