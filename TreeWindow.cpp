/* 
 * File:   TreeWindow.cpp
 * Author: tomko
 * 
 * Created on 5 czerwiec 2011, 01:42
 */

#include "TreeWindow.h"

using namespace std;

TreeWindow::TreeWindow(MainWindow* m) : mw(m)
{
}

TreeWindow::TreeWindow(const TreeWindow& orig)
{
}

TreeWindow::~TreeWindow()
{
}

void TreeWindow::init(int argc, char** argv)
{
  gtk_init(&argc, &argv);
}

void TreeWindow::build()
{
  window = gtk_window_new(GTK_WINDOW_POPUP);

  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), this);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), this);

  gtk_window_set_title(GTK_WINDOW(window), "TMapper - drzewo");
  gtk_widget_set_size_request(window, 800, 800);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_window_set_modal(GTK_WINDOW(window), FALSE);

  //gtk_window_set_transient_for(GTK_WINDOW(window), GTK_WINDOW(mw->getWindow()));
}

void TreeWindow::run()
{
  gtk_widget_show_all(window);
  gtk_main();
}

gboolean TreeWindow::delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
  return FALSE;
}

void TreeWindow::destroy(GtkWidget *widget, gpointer data)
{
  gtk_main_quit();
}