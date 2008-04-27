/*
** main.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 17:06:02 2008 caner candan
** Last update Sun Apr 27 10:34:16 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

int		main(int ac, char **av)
{
  GladeXML	*xml;
  GtkWidget	*widget;
  GtkWidget	*user_view;
  GtkWidget	*mesg_view;

  gtk_init(&ac, &av);
  xml = glade_xml_new(XML_FILE, NULL, NULL);
  widget = glade_xml_get_widget(xml, LOGIN_WINDOW);
  g_signal_connect(G_OBJECT(widget), DELETE_EVENT,
		   G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show(widget);
  user_view = glade_xml_get_widget(xml, USERS_VIEW);
  init_user_list(user_view);
  mesg_view = glade_xml_get_widget(xml, MESG_VIEW);
  init_mesg_list(mesg_view);
  connect_btn_login(xml);
  gtk_main();
  return (0);
}
