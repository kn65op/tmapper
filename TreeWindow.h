/* 
 * File:   TreeWindow.h
 * Author: tomko
 *
 * Created on 5 czerwiec 2011, 01:42
 */

#ifndef TREEWINDOW_H
#define	TREEWINDOW_H

#include <gtk-2.0/gtk/gtk.h>

class TreeWindow;

#include "MainWindow.h"

class TreeWindow
{
public:
  TreeWindow(MainWindow* m);
  TreeWindow(const TreeWindow& orig);
  virtual ~TreeWindow();

  void init(int, char**);
  void build();
  void run();

private:
  MainWindow *mw;
  GtkWidget *window;
  GtkWidget *window2;
  

  static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
  static void destroy(GtkWidget *widget, gpointer data);

};

#endif	/* TREEWINDOW_H */

