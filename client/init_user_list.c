/*
** init_user_list.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 20:08:01 2008 caner candan
** Last update Sat Apr 26 20:56:30 2008 caner candan
*/

#include <gtk/gtk.h>
#include "client.h"

void		init_user_list(void *view)
{
  create_column(view, USERS_LIST, "Users", 110);
  create_column(view, STATUS_LIST, "Status", 60);
  if (DEBUG)
    insert_user_to_list(view, "Debug User", TRUE);
}
