/* 
 * File:   MainWindow.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 22:28
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <gtk-3.0/gtk/gtk.h>
#include <cairo/cairo.h>
#include <string>

class MainWindow
{
public:
  MainWindow();
  MainWindow(const MainWindow& orig);
  virtual ~MainWindow();
  void init(int, char**);
  void build();
  void run();

private:
  GtkWidget *window;
  GtkWidget *button;
  std::string programtitle;

  static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
  static void destroy(GtkWidget *widget, gpointer data);
  static void buttonclicked(GtkWidget *widget, gpointer data);
};

#endif	/* MAINWINDOW_H */

