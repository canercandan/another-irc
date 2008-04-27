/*
** init_mesg_list.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 20:14:10 2008 caner candan
** Last update Sat Apr 26 20:56:19 2008 caner candan
*/

#include <gtk/gtk.h>
#include "client.h"

void		init_mesg_list(void *view)
{
  create_column(view, DATE_MESG, "Date", 50);
  create_column(view, USER_MESG, "User", 80);
  create_column(view, BODY_MESG, "Message", 200);
  if (DEBUG)
    insert_mesg_to_list(view, "00h00", "Debug User", "Debug message ...");
}
