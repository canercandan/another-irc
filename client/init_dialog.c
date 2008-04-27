/*
** init_dialog.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 10:33:19 2008 caner candan
** Last update Sun Apr 27 16:02:06 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <stdio.h>
#include "client.h"

static void	ok_connection(void *xml)
{
  GtkWidget	*widget;

  connect_btn_dialog(xml);
  widget = glade_xml_get_widget(GLADE_XML(xml), LOGIN_WINDOW);
  gtk_widget_hide(widget);
  widget_connected(xml, DIALOG_WINDOW, DELETE_EVENT, gtk_main_quit);
  widget = glade_xml_get_widget(GLADE_XML(xml), DIALOG_WINDOW);
  gtk_widget_show(widget);
}

void		init_dialog(void *btn, void *xml)
{
  if (check_entry(xml, LOGIN_CHAN, BCHAN) < 0 ||
      check_entry(xml, LOGIN_CHAN, EMPTY) < 0)
    error_login(xml, ERR_CHAN);
  else if (check_entry(xml, LOGIN_NICK, EMPTY) < 0)
    error_login(xml, ERR_NICK);
  else if (connect_to_server(xml) < 0)
    error_login(xml, ERR_SIGNIN);
  else
    ok_connection(xml);
}
