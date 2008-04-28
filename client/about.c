/*
** about.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 22:26:38 2008 caner candan
** Last update Mon Apr 28 02:05:48 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		about(void *btn, t_cnt *cnt)
{
  GtkWidget	*widget;

  debug("about()");
  (void)btn;
  widget = glade_xml_get_widget(GLADE_XML(cnt->xml), ABOUT_WINDOW);
  g_signal_connect(G_OBJECT(widget), DELETE_EVENT,
		   G_CALLBACK(gtk_widget_hide), NULL);
  g_signal_connect(G_OBJECT(widget), "close",
		   G_CALLBACK(gtk_widget_hide), NULL);
  gtk_widget_show(widget);
}
