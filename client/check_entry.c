/*
** check_entry.c for my_irc in /home/candan_c/cu/rendu/project/my_irc/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 15:29:50 2008 caner candan
** Last update Sun Apr 27 15:39:23 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <string.h>
#include "client.h"

int		check_entry(void *xml, char *entry, char *value)
{
  GtkWidget	*widget;
  void		*text;

  widget = glade_xml_get_widget(GLADE_XML(xml), entry);
  text = (void *) gtk_entry_get_text(GTK_ENTRY(widget));
  if (!strcmp(text, value))
    {
      gtk_widget_grab_focus(widget);
      return (-1);
    }
  return (0);
}
