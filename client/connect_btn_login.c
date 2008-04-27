/*
** connect_btn_login.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 10:31:00 2008 caner candan
** Last update Sun Apr 27 16:05:57 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		connect_btn_login(void *xml)
{
  widget_connected(xml, LOGIN_QUIT, CLICKED, gtk_main_quit);
  widget_connected(xml, LOGIN_SIGNIN, CLICKED, init_dialog);
  widget_connected(xml, LOGIN_HOST, ACTIVATE, init_dialog);
  widget_connected(xml, LOGIN_PORT, ACTIVATE, init_dialog);
  widget_connected(xml, LOGIN_CHAN, ACTIVATE, init_dialog);
  widget_connected(xml, LOGIN_NICK, ACTIVATE, init_dialog);
  widget_connected(xml, LOGIN_REAL, ACTIVATE, init_dialog);
}
