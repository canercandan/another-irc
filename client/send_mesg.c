/*
** send_mesg.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 22:28:07 2008 caner candan
** Last update Mon Apr 28 05:19:14 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <string.h>
#include "client.h"

void		send_mesg(void *btn, t_cnt *cnt)
{
  GtkWidget	*nick;
  GtkWidget	*entry;
  GtkWidget	*widget;
  void		*nick_value;
  void		*entry_value;
  GtkAdjustment	*adj;

  debug("send_mesg()");
  (void) btn;
  nick = glade_xml_get_widget(GLADE_XML(cnt->xml), LOGIN_NICK);
  nick_value = (void *) gtk_entry_get_text(GTK_ENTRY(nick));
  entry = glade_xml_get_widget(GLADE_XML(cnt->xml), DIALOG_ENTRY);
  entry_value = (void *) gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entry_value, EMPTY))
    {
      insert_mesg_to_list(cnt, EMPTY, nick_value, entry_value);
      send_to_server(cnt, entry_value);
      widget = glade_xml_get_widget(GLADE_XML(cnt->xml), SCROLL_MESG);
      adj = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(widget));
      gtk_adjustment_set_value(adj, adj->upper);
      gtk_scrolled_window_set_vadjustment(GTK_SCROLLED_WINDOW(widget), adj);
    }
  gtk_entry_set_text(GTK_ENTRY(entry), EMPTY);
  gtk_widget_grab_focus(GTK_WIDGET(entry));
}
