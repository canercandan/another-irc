/*
** send_mesg.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 22:28:07 2008 caner candan
** Last update Sun Apr 27 11:27:15 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <string.h>
#include "client.h"

void		send_mesg(void *btn, void *xml)
{
  GtkWidget	*nick;
  GtkWidget	*entry;
  GtkWidget	*mesg;
  void		*nick_value;
  void		*entry_value;

  nick = glade_xml_get_widget(GLADE_XML(xml), LOGIN_NICK);
  nick_value = (void *) gtk_entry_get_text(GTK_ENTRY(nick));
  entry = glade_xml_get_widget(GLADE_XML(xml), DIALOG_ENTRY);
  entry_value = (void *) gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entry_value, EMPTY))
    {
      mesg = glade_xml_get_widget(xml, MESG_VIEW);
      insert_mesg_to_list(mesg, EMPTY, nick_value, entry_value);
    }
  gtk_entry_set_text(GTK_ENTRY(entry), EMPTY);
  gtk_widget_grab_focus(entry);
}
