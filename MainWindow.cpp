/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 22:28
 */

#include "MainWindow.h"

#include <gtk-3.0/gtk/gtk.h>
#include <cairo/cairo.h>
#include <iostream>

using namespace std;

MainWindow::MainWindow(int argc, char **argv)
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
  map = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  tree = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  g_signal_connect(G_OBJECT(map), "delete_event", G_CALLBACK(delete_event), this);
  g_signal_connect(G_OBJECT(map), "destroy", G_CALLBACK(destroy), this);

  gtk_window_set_title(GTK_WINDOW(map), "TMapper1");
  gtk_widget_set_size_request(map, 700, 800);
  gtk_container_set_border_width(GTK_CONTAINER(map), 10);

  /*button = gtk_button_new_with_label("PressMy");
  g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(buttonclicked),this);
  gtk_container_add(GTK_CONTAINER(map),button);//*/

  gtk_window_set_title(GTK_WINDOW(tree), "TMapper2");
  gtk_widget_set_size_request(tree, 300, 800);
  gtk_container_set_border_width(GTK_CONTAINER(tree), 10);

  gtk_window_set_modal(GTK_WINDOW(map), FALSE);
  gtk_window_set_modal(GTK_WINDOW(tree), FALSE);

  wg = gtk_window_group_new();
  gtk_window_group_add_window(wg, GTK_WINDOW(tree));
  gtk_window_group_add_window(wg, GTK_WINDOW(map));
}

void MainWindow::run()
{
  gtk_widget_show_all(map);
  gtk_widget_show_all(tree);
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
  std::cout << "LOL\n";
}