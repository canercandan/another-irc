/*
** cmd_quit.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Thu Apr 24 20:53:51 2008 julian kirtz
** Last update Sat Apr 26 17:51:48 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

/*
// attention, a tester: envoi du msg error
// si la socket client est deja close
// write bloquant
// et le fd pourrait etre reatribuer a un autre client
*/


void	cmd_quit(t_server *serv, int fd, t_message *msg)
{
  char	text[CLIENT_READ_BUF_SIZE];

  snprintf(text, CLIENT_READ_BUF_SIZE, TEXT_ERROR_FORMAT,
	   serv->hostname, serv->client[fd].nick);
  //reply_error(serv, fd, ERROR, text);
  delete_client(serv, fd);
}
