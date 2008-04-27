/*
** connect_btn_login.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 10:31:00 2008 caner candan
** Last update Sun Apr 27 10:31:33 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		connect_btn_login(void *xml)
{
  GtkWidget	*widget;

  widget = glade_xml_get_widget(GLADE_XML(xml), LOGIN_QUIT);
  g_signal_connect(G_OBJECT(widget), CLICKED,
		   G_CALLBACK(gtk_main_quit), NULL);
  widget = glade_xml_get_widget(GLADE_XML(xml), LOGIN_SIGNIN);
  g_signal_connect(G_OBJECT(widget), CLICKED,
		   G_CALLBACK(init_dialog), xml);
}
