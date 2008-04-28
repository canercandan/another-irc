/*
** init_user_list.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 20:08:01 2008 caner candan
** Last update Mon Apr 28 02:08:15 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		init_user_list(t_cnt *cnt)
{
  GtkWidget	*widget;

  debug("init_user_list()");
  widget = glade_xml_get_widget(GLADE_XML(cnt->xml), USERS_VIEW);
  create_column(widget, USERS_LIST, "Users", 110);
  create_column(widget, STATUS_LIST, "Status", 60);
}
