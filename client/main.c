/*
** main.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 17:06:02 2008 caner candan
** Last update Mon Apr 28 04:15:33 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <unistd.h>
#include "client.h"

int	main(int ac, char **av)
{
  t_cnt	cnt;

  gtk_init(&ac, &av);
  cnt.xml = glade_xml_new(XML_FILE, NULL, NULL);
  widget_connected(&cnt, LOGIN_WINDOW, DELETE_EVENT, gtk_main_quit);
  init_user_list(&cnt);
  init_mesg_list(&cnt);
  connect_btn_login(&cnt);
  gtk_main();
  return (0);
}
