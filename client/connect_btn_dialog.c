/*
** connect_btn_dialog.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 10:31:43 2008 caner candan
** Last update Mon Apr 28 02:05:23 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		connect_btn_dialog(t_cnt *cnt)
{
  debug("connect_btn_dialog()");
  widget_connected(cnt, DIALOG_SEND, CLICKED, send_mesg);
  widget_connected(cnt, DIALOG_ENTRY, ACTIVATE, send_mesg);
  widget_connected(cnt, DIALOG_ABOUT, CLICKED, about);
  widget_connected(cnt, DIALOG_QUIT, CLICKED, gtk_main_quit);
  widget_connected(cnt, DIALOG_REFRESH, CLICKED, gtk_main_quit);
}
