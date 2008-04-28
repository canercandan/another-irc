/*
** widget_connected.c for my_irc in /home/candan_c/cu/rendu/project/my_irc/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 15:43:20 2008 caner candan
** Last update Mon Apr 28 02:09:42 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		widget_connected(t_cnt *cnt, char *elm,
				 char *action, void (*f)())
{
  GtkWidget	*widget;

  debug("widget_connected()");
  widget = glade_xml_get_widget(GLADE_XML(cnt->xml), elm);
  g_signal_connect(G_OBJECT(widget), action, G_CALLBACK(f), cnt);
}
