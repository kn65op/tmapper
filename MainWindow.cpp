/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 22:28
 */

#include "MainWindow.h"

#include <gtk-2.0/gtk/gtk.h>
#include <cairo/cairo.h>
#include <iostream>
//#include <gtkmm-2.4/gtkmm/main.h>

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
  //tree = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  vbox = gtk_vbox_new(GTK_ORIENTATION_VERTICAL, 5);
  hbox = gtk_hbox_new(GTK_ORIENTATION_HORIZONTAL, 5);

  g_signal_connect(G_OBJECT(map), "delete_event", G_CALLBACK(delete_event), this);
  g_signal_connect(G_OBJECT(map), "destroy", G_CALLBACK(destroy), this);


  /*okno*/
  gtk_window_set_title(GTK_WINDOW(map), "Mapa");
  gtk_widget_set_size_request(map, 700, 800);
  gtk_container_set_border_width(GTK_CONTAINER(map), 10); //*/

  /* create a new drawing area widget
   */
  canvas = gtk_drawing_area_new();
  /* set a requested (minimum size) for the canvas
   */
  gtk_widget_set_size_request(canvas, 400, 400);

  /* connect our drawing method to the "expose" signal
   */
  g_signal_connect(G_OBJECT(canvas), "expose-event", G_CALLBACK(paint), NULL /*< here we can pass a pointer to a custom data structure */);

  /*button = gtk_button_new_with_label("PressMy");
  g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(buttonclicked),this);
  gtk_container_add(GTK_CONTAINER(map),button);//*/

  /*gtk_window_set_title(GTK_WINDOW(tree), "Drzewo");
  gtk_widget_set_size_request(tree, 300, 800);
  gtk_container_set_border_width(GTK_CONTAINER(tree), 10);//*/

  /*przycisk*/
  button = gtk_button_new_with_label("Narysuj coś");
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(buttonclicked), this);
  gtk_widget_set_size_request(button, 30, 30);
  //  gtk_container_add(GTK_CONTAINER(map), button); //*/


  /* pack canvas widget into window
   */
  // gtk_container_add(GTK_CONTAINER(map), canvas);

  gtk_widget_add_events(canvas,
          GDK_BUTTON1_MOTION_MASK |
          GDK_BUTTON_PRESS_MASK |
          GDK_BUTTON_RELEASE_MASK);

  /**  menu*/
  menu = gtk_menu_bar_new(); // tworzymy menubar
  gtk_widget_set_size_request(menu, 800, 20);

  file_menu = gtk_menu_new(); //tworzymy kategorie
  help_menu = gtk_menu_new();

  file = gtk_menu_item_new_with_mnemonic("_Plik"); // tworzymy nazwy kategorii
  help = gtk_menu_item_new_with_mnemonic("P_omoc");

  open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL); //tworzymy opcje menu
  newf = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
  save = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, NULL);
  quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
  about = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT, NULL);
  sep = gtk_separator_menu_item_new();

  g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(gtk_main_quit), NULL); //łączymy opcje z przyciksami
  g_signal_connect(G_OBJECT(about), "activate", G_CALLBACK(showInfo), NULL); //łączymy opcje z przyciksami

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), file_menu); // łączymy kategorie z nazwami
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), help_menu);

  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), newf); // łączymy kategorie z opcjami
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), sep);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit);
  gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), about);

  gtk_menu_shell_append(GTK_MENU_SHELL(menu), file); //łaczymy kategorie z menu
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), help);

  //boxowanie

  gtk_box_set_homogeneous(GTK_BOX(vbox), FALSE);
  gtk_box_set_homogeneous(GTK_BOX(hbox), FALSE);

  gtk_box_pack_start(GTK_BOX(vbox), menu, FALSE, FALSE, 0);
  gtk_box_pack_end(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(hbox), canvas, TRUE, TRUE, 0);
  gtk_box_pack_end(GTK_BOX(hbox), button, FALSE, FALSE, 0);


  gtk_container_add(GTK_CONTAINER(map), vbox);

  gtk_window_set_modal(GTK_WINDOW(map), FALSE);
  //gtk_window_set_modal(GTK_WINDOW(tree), FALSE);

  //wg = gtk_window_group_new();
  //gtk_window_group_add_window(wg, GTK_WINDOW(tree));
  //gtk_window_group_add_window(wg, GTK_WINDOW(map));
}

void MainWindow::run()
{
  gtk_widget_show_all(map);
  //gtk_widget_show_all(tree);
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
  MainWindow *mw = static_cast<MainWindow*> (data);

  std::cout << "LOL\n";

  cairo_t *cr = gdk_cairo_create(mw->canvas->window);
  /*cairo_set_source_rgb(cr, 0, 0, 255);
  cairo_rectangle(cr, 0.25, 0.25, 0.5, 0.5);
  cairo_fill(cr);
  cairo_stroke(cr);
  cairo_destroy(cr);//*/


  /* clear background */
  cairo_set_source_rgb(cr, 1, 1, 1);
  cairo_paint(cr);


  cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
          CAIRO_FONT_WEIGHT_BOLD);

  /* enclosing in a save/restore pair since we alter the
   * font size
   */
  cairo_save(cr);
  cairo_set_font_size(cr, 40);
  cairo_move_to(cr, 40, 60);
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_show_text(cr, "Hello World");
  cairo_restore(cr);

  cairo_set_source_rgb(cr, 1, 0, 0);
  cairo_set_font_size(cr, 20);
  cairo_move_to(cr, 50, 100);
  cairo_show_text(cr, "JEST OK");

  cairo_set_source_rgb(cr, 0, 0, 1);

  cairo_move_to(cr, 0, 150);
  for (int i = 0; i < 400 / 10; i++)
  {
    cairo_rel_line_to(cr, 5, 10);
    cairo_rel_line_to(cr, 5, -10);
  }
  cairo_stroke(cr);

  cairo_destroy(cr);

}

void MainWindow::paint(GtkWidget* widget, GdkEventExpose* eev, gpointer data)
{

  /* clear background */
  cairo_t *cr = gdk_cairo_create(widget->window);
  cairo_set_source_rgb(cr, 1, 1, 1);
  cairo_paint(cr);


  cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
          CAIRO_FONT_WEIGHT_BOLD);

  /* enclosing in a save/restore pair since we alter the
   * font size
   */
  cairo_save(cr);
  cairo_set_font_size(cr, 40);
  cairo_move_to(cr, 40, 60);
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_show_text(cr, "Hello World");
  cairo_restore(cr);

  cairo_set_source_rgb(cr, 1, 0, 0);
  cairo_set_font_size(cr, 20);
  cairo_move_to(cr, 50, 100);
  cairo_show_text(cr, "greetings from gtk and cairo");

  cairo_set_source_rgb(cr, 0, 0, 1);

  cairo_move_to(cr, 0, 150);
  for (int i = 0; i < 100 / 10; i++)
  {
    cairo_rel_line_to(cr, 5, 10);
    cairo_rel_line_to(cr, 5, -10);
  }
  cairo_stroke(cr);

  cairo_destroy(cr);
  std::cout << "Paint\n";
}

void MainWindow::showInfo(GtkWidget *widget, gpointer data)
{
  std::cout << "INFO\n";
  GtkWidget *infow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(infow), "Informacje o programie");
  gtk_widget_show_all(infow);
  //gtk_main();
}