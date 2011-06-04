/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 22:28
 */

#include "MainWindow.h"

#include <gtk-3.0/gtk/gtk.h>
#include <iostream>

using namespace std;

MainWindow::MainWindow()
{
}

MainWindow::MainWindow(const MainWindow& orig)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::init(int argc, char** argv)
{
  gtk_init(&argc, &argv);
}

void MainWindow::build()
{
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  paned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
  map = gtk_frame_new(NULL);
  tree = gtk_frame_new(NULL);

  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), this);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), this);

  gtk_window_set_title(GTK_WINDOW(window), "TMapper");
  gtk_widget_set_size_request(window, 300, 300);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  gtk_frame_set_shadow_type(GTK_FRAME(map), GTK_SHADOW_IN); //tworzenie ramek
  gtk_frame_set_shadow_type(GTK_FRAME(tree), GTK_SHADOW_IN);

  gtk_paned_pack1(GTK_PANED(paned), map, TRUE, FALSE);
  gtk_paned_pack2(GTK_PANED(paned), tree, TRUE, FALSE);
  gtk_widget_set_size_request(map, 500, 700);
  gtk_widget_set_size_request(tree, 200, 700);/**/

  gtk_container_add(GTK_CONTAINER(window), paned);

}

void MainWindow::run()
{
  gtk_widget_show_all(window);
  gtk_main();
}

gboolean MainWindow::delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
  return FALSE;
}

void MainWindow::destroy(GtkWidget *widget, gpointer data)
{
  gtk_main_quit();
}

void MainWindow::buttonclicked(GtkWidget *widget, gpointer data)
{

}