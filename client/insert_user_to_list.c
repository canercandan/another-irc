/*
** insert_user_to_list.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 20:40:13 2008 caner candan
** Last update Mon Apr 28 02:09:04 2008 caner candan
*/

#include <gtk/gtk.h>
#include <glade/glade.h>
#include "client.h"

void			insert_user_to_list(t_cnt *cnt, char *user,
					    int status)
{
  static GtkTreeStore	*store = NULL;
  GtkTreeIter		iter;
  GtkWidget		*widget;

  debug("insert_user_to_list()");
  if (!store)
    store = gtk_tree_store_new(N_LIST, G_TYPE_STRING, G_TYPE_BOOLEAN);
  widget = glade_xml_get_widget(GLADE_XML(cnt->xml), USERS_VIEW);
  gtk_tree_store_append(GTK_TREE_STORE(store), &iter, NULL);
  gtk_tree_store_set(GTK_TREE_STORE(store), &iter,
		     USERS_LIST, user,
		     STATUS_LIST, status,
		     -1);
  gtk_tree_view_set_model(GTK_TREE_VIEW(widget), GTK_TREE_MODEL(store));
}
