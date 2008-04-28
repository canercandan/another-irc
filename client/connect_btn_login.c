/*
** connect_btn_login.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 10:31:00 2008 caner candan
** Last update Mon Apr 28 02:06:42 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		connect_btn_login(t_cnt *cnt)
{
  debug("connect_btn_login()");
  widget_connected(cnt, LOGIN_QUIT, CLICKED, gtk_main_quit);
  widget_connected(cnt, LOGIN_SIGNIN, CLICKED, init_dialog);
  widget_connected(cnt, LOGIN_HOST, ACTIVATE, init_dialog);
  widget_connected(cnt, LOGIN_PORT, ACTIVATE, init_dialog);
  widget_connected(cnt, LOGIN_CHAN, ACTIVATE, init_dialog);
  widget_connected(cnt, LOGIN_NICK, ACTIVATE, init_dialog);
  widget_connected(cnt, LOGIN_REAL, ACTIVATE, init_dialog);
}
