/*
** connect_to_server.c for my_irc in /home/candan_c/cu/rendu/project/my_irc/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 13:38:11 2008 caner candan
** Last update Sun Apr 27 19:50:11 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

static void	*return_widget(void *xml, void *elm)
{
  GtkWidget	*widget;

  widget = glade_xml_get_widget(GLADE_XML(xml), elm);
  return ((void *) gtk_entry_get_text(GTK_ENTRY(widget)));
}

int		connect_to_server(void *xml)
{
  t_cnt		cnt;

  cnt.host = return_widget(xml, LOGIN_HOST);
  cnt.port = return_widget(xml, LOGIN_PORT);
  if (create_socket(&cnt) < 0)
    return (-1);
  listen_from_server(xml, &cnt);
  /*
    send_to_server(xml, &cnt, NULL);
  listen_from_server(xml, &cnt);
  */
  cnt.chan = return_widget(xml, LOGIN_CHAN);
  cnt.nick = return_widget(xml, LOGIN_NICK);
  if (check_entry(xml, LOGIN_REAL, EMPTY) < 0)
    cnt.real = cnt.nick;
  else
    cnt.real = return_widget(xml, LOGIN_REAL);
  return (0);
}
