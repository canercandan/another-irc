/*
** connect_btn_dialog.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 10:31:43 2008 caner candan
** Last update Sun Apr 27 11:33:09 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void		connect_btn_dialog(void *xml)
{
  GtkWidget	*widget;

  widget = glade_xml_get_widget(GLADE_XML(xml), DIALOG_SEND);
  g_signal_connect(G_OBJECT(widget), CLICKED,
		   G_CALLBACK(send_mesg), xml);
  widget = glade_xml_get_widget(GLADE_XML(xml), DIALOG_ENTRY);
  g_signal_connect(G_OBJECT(widget), ACTIVATE,
		   G_CALLBACK(send_mesg), xml);
  widget = glade_xml_get_widget(GLADE_XML(xml), DIALOG_ABOUT);
  g_signal_connect(G_OBJECT(widget), CLICKED,
		   G_CALLBACK(about), xml);
  widget = glade_xml_get_widget(GLADE_XML(xml), DIALOG_QUIT);
  g_signal_connect(G_OBJECT(widget), CLICKED,
		   G_CALLBACK(gtk_main_quit), NULL);
}
