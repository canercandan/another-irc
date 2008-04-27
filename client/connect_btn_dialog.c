/*
** connect_btn_dialog.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 10:31:43 2008 caner candan
** Last update Sun Apr 27 15:54:10 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		connect_btn_dialog(void *xml)
{
  widget_connected(xml, DIALOG_SEND, CLICKED, send_mesg);
  widget_connected(xml, DIALOG_ENTRY, ACTIVATE, send_mesg);
  widget_connected(xml, DIALOG_ABOUT, CLICKED, about);
  widget_connected(xml, DIALOG_QUIT, CLICKED, gtk_main_quit);
}
