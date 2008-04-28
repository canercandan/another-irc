/*
** connect_to_server.c for my_irc in /home/candan_c/cu/rendu/project/my_irc/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 13:38:11 2008 caner candan
** Last update Mon Apr 28 02:06:34 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"
#include "x.h"

static void	*return_widget(void *xml, void *elm)
{
  GtkWidget	*widget;

  widget = glade_xml_get_widget(GLADE_XML(xml), elm);
  return ((void *) gtk_entry_get_text(GTK_ENTRY(widget)));
}

int		connect_to_server(t_cnt *cnt)
{
  debug("connect_to_server()");
  cnt->host = return_widget(cnt->xml, LOGIN_HOST);
  cnt->port = return_widget(cnt->xml, LOGIN_PORT);
  if (create_socket(cnt) < 0)
    return (-1);
  cnt->chan = return_widget(cnt->xml, LOGIN_CHAN);
  cnt->nick = return_widget(cnt->xml, LOGIN_NICK);
  insert_user_to_list(cnt, cnt->nick, TRUE);
  if (check_entry(cnt->xml, LOGIN_REAL, EMPTY) < 0)
    cnt->real = cnt->nick;
  else
    cnt->real = return_widget(cnt->xml, LOGIN_REAL);
  return (0);
}
