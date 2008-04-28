/*
** init_dialog.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Apr 27 10:33:19 2008 caner candan
** Last update Mon Apr 28 08:11:48 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <stdlib.h>
#include "client.h"
#include "x.h"

static gboolean	listen_from_server(GIOChannel *io, GIOCondition condition,
				   void *cnt)
{
  gchar		buf[512];
  gsize		nbr;
  t_message	msg;

  debug("listen_from_server()");
  (void) condition;
  if (g_io_channel_read(io, buf, CLIENT_READ_BUF_SIZE, &nbr)
      != G_IO_ERROR_NONE)
    {
      g_io_channel_close(io);
      return (-1);
    }
  buf[nbr] = '\0';
  if (nbr > 0)
    {
      debug("prefix");
      debug(msg.prefix);
      debug("commande");
      debug(msg.command);
      debug("param[0]");
      debug(msg.param[0]);
      extract_msg((char *) buf, &msg);
      mesg_init(cnt, &msg);
      insert_mesg_to_list(cnt, EMPTY, "server", trim(buf));
    }
  scrolled_window(cnt, SCROLL_MESG);
  g_io_add_watch(io, G_IO_IN, listen_from_server, cnt);
  return (0);
}

static void	ok_connection(t_cnt *cnt)
{
  GtkWidget	*widget;
  GIOChannel	*io;

  connect_btn_dialog(cnt);
  widget = glade_xml_get_widget(GLADE_XML(cnt->xml), LOGIN_WINDOW);
  gtk_widget_hide(widget);
  widget_connected(cnt, DIALOG_WINDOW, DELETE_EVENT, gtk_main_quit);
  widget = glade_xml_get_widget(GLADE_XML(cnt->xml), DIALOG_WINDOW);
  gtk_widget_show(widget);
  init_server(cnt);
  io = g_io_channel_unix_new(cnt->socket);
  g_io_channel_init(io);
  g_io_add_watch(io, G_IO_IN, listen_from_server, cnt);
}

void		init_dialog(void *btn, t_cnt *cnt)
{
  debug("init_dialog()");
  (void)btn;
  if (check_entry(cnt->xml, LOGIN_CHAN, BCHAN) < 0 ||
      check_entry(cnt->xml, LOGIN_CHAN, EMPTY) < 0)
    error_login(cnt->xml, ERR_CHAN);
  else if (check_entry(cnt->xml, LOGIN_NICK, EMPTY) < 0)
    error_login(cnt->xml, ERR_NICK);
  else if (connect_to_server(cnt) < 0)
    error_login(cnt->xml, ERR_SIGNIN);
  else
    ok_connection(cnt);
}
