/*
** scrolled_window.c for my_irc in /home/candan_c/cu/rendu/project/my_irc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Apr 28 06:27:15 2008 caner candan
** Last update Mon Apr 28 06:40:37 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		scrolled_window(t_cnt *cnt, void *scroll)
{
  GtkWidget	*widget;
  GtkAdjustment	*adj;

  debug("scrolled_window()");
  widget = glade_xml_get_widget(GLADE_XML(cnt->xml), scroll);
  adj = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(widget));
  gtk_adjustment_set_value(adj, adj->upper);
  gtk_scrolled_window_set_vadjustment(GTK_SCROLLED_WINDOW(widget), adj);
}
