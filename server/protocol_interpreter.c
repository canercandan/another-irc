/*
** protocol_interpreter.c for my_irc in /u/epitech_2010s/kirtz_j/cu/rendu/c/my_irc/server
** 
** Made by julian kirtz
** Login   <kirtz_j@epitech.net>
** 
** Started on  Tue Apr 22 13:17:43 2008 julian kirtz
** Last update Thu Apr 24 17:47:41 2008 julian kirtz
*/

#include <sys/time.h>
#include "server.h"

void		protocol_interpreter(t_server *serv, int fd)
{
  char		amsg[512];
  t_message	msg;
  int		i;


  //  char		*debug;
  //  snprintf(debug, serv->client[fd].buffer_offset, "buffer: [%s]\n", serv->client[fd].buffer_read);
  //  printf("len:%d debug: [%s]\n", serv->client[fd].buffer_offset, serv->client[fd].buffer_read);

  get_next_message(serv->client[fd].buffer_read, amsg,
		   &(serv->client[fd].buffer_offset));
  while (amsg[0] != -1)
    {
      printf("message: [%s]\n", amsg);
      extract_msg(amsg, &msg);
      printf("\textract prefix: %s\n", msg.prefix);
      printf("\textract command: %s\n", msg.command);
      for (i = 0; msg.param[i]; i++)
	printf("\textract param%d: %s\n", i, msg.param[i]);
      free(msg.prefix);
      free(msg.command);
      for (i = 0; msg.param[i]; i++)
	free(msg.param[i]);
      do_command(serv, fd, &msg);
      get_next_message(serv->client[fd].buffer_read, amsg,
		       &(serv->client[fd].buffer_offset));
    }
  write(1, "Ok\n", 3);
}
