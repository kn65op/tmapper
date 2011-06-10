/* 
 * File:   MainWindow.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 22:28
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <gtk-2.0/gtk/gtk.h>
#include <cairo/cairo.h>
#include <string>

class MainWindow;

class MainWindow
{
public:
  MainWindow(int argc, char **argv);
  MainWindow(const MainWindow& orig);
  virtual ~MainWindow();
  void init(int, char**);
  void build();
  void run();

  GtkWidget* getMap() const
  {
    return map;
  }


private:
  GtkWidget *map;
  GtkWidget *tree;
  GtkWidget *menu;
  GtkWidget *vbox; // box na menu i resztę
  GtkWidget *hbox; // box na rzeczy w mapie
  GtkWindowGroup * wg;
  std::string programtitle;

  GtkWidget *canvas;
  GtkWidget *button;

  static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
  static void destroy(GtkWidget *widget, gpointer data);
  static void buttonclicked(GtkWidget *widget, gpointer data);

  static void paint(GtkWidget *widget, GdkEventExpose *eev, gpointer data);
};

#endif	/* MAINWINDOW_H */

