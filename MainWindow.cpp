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

  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), this);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), this);

  gtk_window_set_title(GTK_WINDOW(window), "MainWindow");
  gtk_widget_set_size_request(window, 170, 50);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  button = gtk_button_new_with_label("PressMy");
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(buttonclicked), this);
  gtk_container_add(GTK_CONTAINER(window), button);
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
  MainWindow *mygui = static_cast<MainWindow*> (data);

  cout << gtk_button_get_label(GTK_BUTTON(mygui->button)) << endl;
  mygui->programtitle = gtk_window_get_title(GTK_WINDOW(mygui->window));
  cout << "Nazwa twojego programu to: " << mygui->programtitle << endl;
}