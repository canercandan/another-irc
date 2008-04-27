/*
** create_column.c for my_irc in /home/candan_c/cu/rendu/test/glade
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Apr 26 19:50:23 2008 caner candan
** Last update Sat Apr 26 19:51:38 2008 caner candan
*/

#include <gtk/gtk.h>
#include "client.h"

void			create_column(void *view, int type,
				      char *title, int width)
{
  GtkTreeViewColumn	*column;
  GtkCellRenderer	*renderer;

  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes(title, renderer,
						    "text", type,
						    NULL);
  gtk_tree_view_column_set_title(column, title);
  gtk_tree_view_column_set_visible(column, TRUE);
  gtk_tree_view_column_set_resizable(column, TRUE);
  gtk_tree_view_column_set_min_width(column, width);
  gtk_tree_view_column_set_alignment(column, 0.5);
  gtk_tree_view_column_set_clickable(column, TRUE);
  gtk_tree_view_column_set_reorderable(column, TRUE);
  gtk_tree_view_column_set_sort_order(column, 0);
  gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
}
