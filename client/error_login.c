/*
** error_login.c for my_irc in /home/candan_c/cu/rendu/project/my_irc/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 15:19:50 2008 caner candan
** Last update Sun Apr 27 15:22:32 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <stdio.h>
#include "client.h"

void		error_login(void *xml, char *mesg)
{
  GtkWidget	*widget;
  char		err[200];

  widget = glade_xml_get_widget(GLADE_XML(xml), LOGIN_MESG);
  snprintf(err, sizeof(err), ERR_FMT, mesg);
  gtk_label_set_markup(GTK_LABEL(widget), err);
  gtk_widget_show(widget);
}
