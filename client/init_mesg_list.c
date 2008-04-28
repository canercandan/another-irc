/*
** init_mesg_list.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 20:14:10 2008 caner candan
** Last update Mon Apr 28 02:08:04 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		init_mesg_list(t_cnt *cnt)
{
  GtkWidget	*widget;

  debug("init_mesg_list()");
  widget = glade_xml_get_widget(GLADE_XML(cnt->xml), MESG_VIEW);
  create_column(widget, DATE_MESG, "Date", 50);
  create_column(widget, USER_MESG, "User", 80);
  create_column(widget, BODY_MESG, "Message", 200);
}
