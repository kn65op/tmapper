/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 22:28
 */

#define MENU_SIZE 20
#define TREE_SIZE 200

#include "MainWindow.h"

#include <gtk-2.0/gtk/gtk.h>
#include <gtk-2.0/gdk/gdkkeysyms.h>
#include <cairo/cairo.h>
#include <iostream>
#include <fstream>
#include <float.h>
#include <unistd.h>
#include <sstream>

#include "KML.h"
//#include <gtkmm-2.4/gtkmm/main.h>

using namespace std;

MainWindow::MainWindow(int argc, char **argv)
{
  analiser = new Analiser();
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
  tree = gtk_tree_view_new();
  vbox = gtk_vbox_new(GTK_ORIENTATION_VERTICAL, 1);
  hbox = gtk_hbox_new(GTK_ORIENTATION_HORIZONTAL, 1);

  g_signal_connect(G_OBJECT(map), "delete_event", G_CALLBACK(delete_event), this);
  g_signal_connect(G_OBJECT(map), "destroy", G_CALLBACK(destroy), this);


  /*okno*/
  gtk_window_set_title(GTK_WINDOW(map), "Mapa");
  gtk_widget_set_size_request(map, 700, 400);
  gtk_container_set_border_width(GTK_CONTAINER(map), 0); //*/

  accel_group = gtk_accel_group_new(); //do skrótów klawiszowych
  gtk_window_add_accel_group(GTK_WINDOW(map), accel_group);

  /* create a new drawing area widget
   */
  canvas = gtk_drawing_area_new();
  /* set a requested (minimum size) for the canvas
   */
  gtk_widget_set_size_request(canvas, 400, 400);

  /* connect our drawing method to the "expose" signal
   */
  g_signal_connect(G_OBJECT(canvas), "expose-event", G_CALLBACK(paint), this);

  /*button = gtk_button_new_with_label("PressMy");
  g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(buttonclicked),this);
  gtk_container_add(GTK_CONTAINER(map),button);//*/

  //gtk_window_set_title(GTK_WINDOW(tree), "Drzewo");
  //gtk_widget_set_size_request(tree, 300, 800);
  //gtk_container_set_border_width(GTK_CONTAINER(tree), 10);//*/
  /*widok drzewa*/
  gtk_widget_set_size_request(tree, TREE_SIZE, TREE_SIZE);

  /*przycisk*/
  button = gtk_button_new_with_label("Narysuj coś");
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(buttonclicked), this);
  gtk_widget_set_size_request(button, TREE_SIZE, TREE_SIZE);
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
  gtk_widget_set_size_request(menu, 800, MENU_SIZE);

  file_menu = gtk_menu_new(); //tworzymy kategorie
  help_menu = gtk_menu_new();

  file = gtk_menu_item_new_with_mnemonic("_Plik"); // tworzymy nazwy kategorii
  help = gtk_menu_item_new_with_mnemonic("P_omoc");

  open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL); //tworzymy opcje menu
  newf = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
  save_as = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, NULL);
  quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
  about = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT, NULL);
  sep = gtk_separator_menu_item_new();

  g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(gtk_main_quit), NULL); //łączymy opcje z działaniem aplikacji
  g_signal_connect(G_OBJECT(about), "activate", G_CALLBACK(showInfo), NULL);
  g_signal_connect(G_OBJECT(open), "activate", G_CALLBACK(openFile), this);
  g_signal_connect(G_OBJECT(save_as), "activate", G_CALLBACK(saveFile), this);

  /*skróty klawiszowe*/
  gtk_widget_add_accelerator(quit, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); //skróty klawiszowe
  gtk_widget_add_accelerator(open, "activate", accel_group, GDK_o, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(save_as, "activate", accel_group, GDK_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(newf, "activate", accel_group, GDK_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), file_menu); // łączymy kategorie z nazwami
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), help_menu);

  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), newf); // łączymy kategorie z opcjami
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_as);
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
  gtk_box_pack_end(GTK_BOX(hbox), tree, FALSE, FALSE, 0);


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
  MainWindow *mw = static_cast<MainWindow*> (data);

  std::cout << "LOL\n";

  cairo_t *cr = gdk_cairo_create(mw->canvas->window);

  mw->drawKML(cr);

  cairo_destroy(cr);
}

void MainWindow::showInfo(GtkWidget *widget, gpointer data)
{
  GtkWidget *info = gtk_about_dialog_new();
  gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(info), "TMapper");
  gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(info), "TMapper");
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(info), "0.0.5");
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(info), "(c) Tomasz Drzewiecki");
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(info), "TMapper to program do podglądu i edycji map zapisanych w KML.\n"
          "Program zrealizowany jako program zaliczeniowy na przedmiot \"Języki formalne i kompilatory\",\nprowadzący:\tdr. inż. Jacek Piwowarczyk,\n"
          "Informatyka stosowana,\nIII rok");
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(info), "https://sourceforge.net/projects/tmapper/");
  //gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(info), pixbuf); //TODO dołożyć log
  //g_object_unref(pixbuf), pixbuf = NULL;
  gtk_dialog_run(GTK_DIALOG(info));
  gtk_widget_destroy(info);
  //gtk_main();
}

void MainWindow::openFile(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  GtkWidget *chooser = gtk_file_chooser_dialog_new("Otwórz plik",
          GTK_WINDOW(mw->map),
          GTK_FILE_CHOOSER_ACTION_OPEN,
          GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
          GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
          NULL);
  if (gtk_dialog_run(GTK_DIALOG(chooser)) == GTK_RESPONSE_ACCEPT)
  {
    char *filename;
    filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
    mw->getAnaliser()->SetFilename(string(filename));
    if (mw->getAnaliser()->Analise())
    {
      MainWindow::showNoFile(mw);
    }
    if (mw->getAnaliser()->GetKML())
    {
      mw->getAnaliser()->GetKML()->connectStyles();
    }
    g_free(filename);
  }
  gtk_widget_destroy(chooser);
  MainWindow::paint(widget, 0, data);
}

void MainWindow::saveFile(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  GtkWidget *chooser = gtk_file_chooser_dialog_new("Zapisz plik",
          GTK_WINDOW(mw->map),
          GTK_FILE_CHOOSER_ACTION_SAVE,
          GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
          GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
          NULL);
  if (gtk_dialog_run(GTK_DIALOG(chooser)) == GTK_RESPONSE_ACCEPT)
  {
    char *filename;
    filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
    std::cout << "A\n";
    mw->getAnaliser()->saveKMLToFile(string(filename));
    std::cout << "A\n";
    g_free(filename);
  }
  gtk_widget_destroy(chooser);
}

void MainWindow::drawKML(cairo_t *cr)
{
  cairo_set_source_rgb(cr, 1, 1, 1);
  cairo_paint(cr);

  if (!analiser->GetKML()) //można narysować
  {
    return;
  }

  double a_x, b_x, a_y, b_y;
  double min_x, max_x, min_y, max_y;
  int width, height;
  min_x = min_y = DBL_MAX;
  max_x = max_y = -DBL_MAX;

  analiser->GetKML()->findHW(max_x, min_x, max_y, min_y);
  gtk_window_get_size(GTK_WINDOW(map), &width, &height);

  max_x = max_x > 0 ? max_x * 1.02 : max_x * 0.98;
  max_y = max_y > 0 ? max_y * 1.02 : max_y * 0.98;
  min_x = min_x > 0 ? min_x * 0.98 : min_x * 1.02;
  min_y = min_y > 0 ? min_y * 0.98 : min_y * 1.02;

  a_x = (width - TREE_SIZE) / (max_x - min_x);
  b_x = min_x;
  a_y = (height - MENU_SIZE) / (min_y - max_y);
  b_y = max_y;

  analiser->GetKML()->draw(cr, a_x, b_x, a_y, b_y, NULL);

}

void MainWindow::showError(const char* s, int line, MainWindow* mw)
{
  std::string err(s);
  MainWindow::convertToPolish(err);
  GtkWidget *error = gtk_message_dialog_new(GTK_WINDOW(mw->map), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_YES_NO,
          "Znaleziono błąd: %s w linii %d.\nCzy chcesz otworzyć edytor plików?", err.c_str(), line);
  gtk_window_set_title(GTK_WINDOW(error), "Bład w odczytywanym pliku.");
  gint response = gtk_dialog_run(GTK_DIALOG(error));
  if (response == GTK_RESPONSE_YES)
  {
    int pid = fork();
    if (!pid)
    {
      stringstream ss;
      ss << "+";
      ss << line;
      string file = mw->getAnaliser()->GetFilename().c_str();
      int i = 0;
      while (file.find(" ", i) != std::string::npos)
      {
        file.replace(file.find(" ", i), 1, "\\ ");
        i = file.find(" ", i) + 1;
      }
      std::cout << "gedit " << ss.str().c_str() << " " << file.c_str() << "\n";
      execlp("gedit", "gedit", ss.str().c_str(), file.c_str(), 0); //FIXME: do zmiany kiedyś może //TODO: do poprawy
    }
  }
  gtk_widget_destroy(error);
  //gtk_main();
}

void MainWindow::convertToPolish(std::string& s) //TODO: Zmienić na pobranie i podzielenie na części względem np. #
{
  ifstream file("pl_text");
  if (file.eof())
  {
    return;
  }
  std::cout << file.eof() << "\n";
  std::string what;
  std::string to;
  while (!file.eof())
  {
    file >> what;
    file >> to;
    if (what == "")
    {
      return;
    }
    while (s.find(what) != std::string::npos)
    {
      s.replace(s.find(what), what.size(), to);
    }
  }
}

void MainWindow::showNoFile(MainWindow* mw)
{
  GtkWidget *error = gtk_message_dialog_new(GTK_WINDOW(mw->map), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
          "Wybrany plik nie istnieje w systemie plików.");
  gtk_window_set_title(GTK_WINDOW(error), "Podany plik nie istnieje.");
  gtk_dialog_run(GTK_DIALOG(error));
  gtk_widget_destroy(error);
}