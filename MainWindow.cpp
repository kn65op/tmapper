/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 22:28
 */

#define STATUS_POZ_CONT 1
#define STATUS_ERR_CONT 2
#define MENU_SIZE 20
#define STATUS_SIZE 20
#define TREE_SIZE 300

#include "MainWindow.h"
#include "Analiser.h"

#include <gtk-2.0/gtk/gtk.h>
#include <gtk-2.0/gdk/gdkkeysyms.h>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <iostream>
#include <fstream>
#include <float.h>
#include <unistd.h>
#include <sstream>
#include <gtk-2.0/gtk/gtkwidget.h>
#include <gtk-2.0/gtk/gtktreemodel.h>
#include <gtk-2.0/gtk/gtkimagemenuitem.h>
#include <gtk-2.0/gtk/gtkstatusbar.h>
#include <gtk-2.0/gtk/gtktreeview.h>

#include "KML.h"
#include "Coordinates.h"
#include "Placemark.h"
#include "node.h"
#include "Style.h"
#include "Document.h"
#include "InnerBoundaryIs.h"
#include "LinearRing.h"
#include "LineString.h"
#include "Multigeometry.h"
#include "OuterBoundaryIs.h"
#include "Point.h"
#include "Polygon.h"
#include "Folder.h"
//#include <gtkmm-2.4/gtkmm/main.h>

using namespace std;

std::vector<GtkWidget*> MainWindow::items;
std::vector<int> MainWindow::tmp_nr;
bool MainWindow::move_ok = false;
int MainWindow::move_nr = -1;
GtkWidget * MainWindow::menu_popup = 0;

node* MainWindow::node_edit = 0;
node* MainWindow::node_add = 0;

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
  mouse_clicked = false;
  act = 0;
  can_edit = true;
  zoom_auto = true;
  edited = false;
}

void MainWindow::build()
{
  map = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  treew = gtk_scrolled_window_new(NULL, NULL);
  tree = gtk_tree_view_new();
  col = gtk_tree_view_column_new();
  status_bar = gtk_statusbar_new();
  vbox = gtk_vbox_new(GTK_ORIENTATION_VERTICAL, 1);
  hbox = gtk_hbox_new(GTK_ORIENTATION_HORIZONTAL, 1);

  g_signal_connect(G_OBJECT(map), "delete_event", G_CALLBACK(delete_event), this);
  g_signal_connect(G_OBJECT(map), "destroy", G_CALLBACK(destroy), this);


  /*okno*/
  gtk_window_set_title(GTK_WINDOW(map), "TMapper");
  gtk_widget_set_size_request(map, 700, 400);
  gtk_container_set_border_width(GTK_CONTAINER(map), 0); //*/
  GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("icon.png", NULL);
  gtk_window_set_icon(GTK_WINDOW(map), pixbuf);
  g_object_unref(pixbuf), pixbuf = NULL;

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

  /* dodanie obsługi wydarzeń*/


  /*button = gtk_button_new_with_label("PressMy");
  g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(buttonclicked),this);
  gtk_container_add(GTK_CONTAINER(map),button);//*/

  //gtk_window_set_title(GTK_WINDOW(tree), "Drzewo");
  //gtk_widget_set_size_request(tree, 300, 800);
  //gtk_container_set_border_width(GTK_CONTAINER(tree), 10);//*/

  /* tree window*/
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(treew),
          GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  /*widok drzewa*/
  gtk_widget_set_size_request(tree, TREE_SIZE, TREE_SIZE);
  gtk_tree_view_column_set_title(col, "Drzewo pliku");

  /*podpięcie activate row*/
  g_signal_connect(G_OBJECT(tree), "row-activated", G_CALLBACK(tree_row_activated), this);
  g_signal_connect(G_OBJECT(tree), "cursor-changed", G_CALLBACK(tree_row_selected), this);

  gtk_tree_view_append_column(GTK_TREE_VIEW(tree), col);

  renderer = gtk_cell_renderer_text_new();
  gtk_tree_view_column_pack_start(col, renderer, TRUE);
  gtk_tree_view_column_add_attribute(col, renderer, "text", 0);

  treestore = gtk_tree_store_new(1,
          G_TYPE_STRING);
  model = GTK_TREE_MODEL(treestore);
  gtk_tree_view_set_model(GTK_TREE_VIEW(tree), model);
  g_object_unref(model);

  /*przycisk*/
  button = gtk_button_new_with_label("Narysuj coś");
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(buttonclicked), this);
  gtk_widget_set_size_request(button, TREE_SIZE, TREE_SIZE);

  //  gtk_container_add(GTK_CONTAINER(map), button); //*/


  /* pack canvas widget into window
   */
  // gtk_container_add(GTK_CONTAINER(map), canvas);
  /*dodanie wydarzeń na które reaguje canvvas*/
  gtk_widget_add_events(canvas,
          GDK_POINTER_MOTION_MASK |
          GDK_BUTTON1_MOTION_MASK |
          GDK_BUTTON_PRESS_MASK |
          GDK_BUTTON_RELEASE_MASK);


  /* łaczenie wydarzeń z funkcjami */

  g_signal_connect(G_OBJECT(canvas), "button-press-event", G_CALLBACK(canvas_button_press), this);
  g_signal_connect(G_OBJECT(canvas), "motion-notify-event", G_CALLBACK(canvas_mouse_move), this);
  g_signal_connect(G_OBJECT(canvas), "button-release-event", G_CALLBACK(canvas_button_release), this);

  /**  menu*/
  menu = gtk_menu_bar_new(); // tworzymy menubar
  gtk_widget_set_size_request(menu, 800, MENU_SIZE);

  file_menu = gtk_menu_new(); //tworzymy kategorie
  help_menu = gtk_menu_new();
  add_menu = gtk_menu_new();
  view_menu = gtk_menu_new();

  file = gtk_menu_item_new_with_mnemonic("_Plik"); // tworzymy nazwy kategorii
  help = gtk_menu_item_new_with_mnemonic("P_omoc");
  add = gtk_menu_item_new_with_mnemonic("_Dodaj");
  view = gtk_menu_item_new_with_mnemonic("_Widok");

  open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL); //tworzymy opcje menu
  newf = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
  save_as = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, NULL);
  quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
  about = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT, NULL);
  sep1 = gtk_separator_menu_item_new();
  sep2 = gtk_separator_menu_item_new();
  z_auto = gtk_menu_item_new_with_label("Automatyczne przybliżenie");
  z_man = gtk_menu_item_new_with_label("Ustaw przybliżenie");
  match = gtk_menu_item_new_with_label("Dopasuj");
  closer = gtk_menu_item_new_with_label("Przybliż");
  further = gtk_menu_item_new_with_label("Oddal");
  save_to_pdf = gtk_menu_item_new_with_label("Eksportuj do pdf");
  save_to_png = gtk_menu_item_new_with_label("Eksportuj do png");
  document = gtk_menu_item_new_with_label("Document");
  folder = gtk_menu_item_new_with_label("Folder");
  iconStyle = gtk_menu_item_new_with_label("IconStyle");
  innerBoundaryIs = gtk_menu_item_new_with_label("InnerBoundaryIs");
  linearRing = gtk_menu_item_new_with_label("LinearRing");
  lineString = gtk_menu_item_new_with_label("LineString");
  lineStyle = gtk_menu_item_new_with_label("LineStyle");
  mulitgeometry = gtk_menu_item_new_with_label("Mulitgeometry");
  outerBoundaryIs = gtk_menu_item_new_with_label("OuterBoundaryIs");
  placemark = gtk_menu_item_new_with_label("Placemark");
  point = gtk_menu_item_new_with_label("Point");
  polygon = gtk_menu_item_new_with_label("Polygon");
  polyStyle = gtk_menu_item_new_with_label("PolyStyle");
  style = gtk_menu_item_new_with_label("Style");

  g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(gtk_main_quit), NULL); //łączymy opcje z działaniem aplikacji
  g_signal_connect(G_OBJECT(about), "activate", G_CALLBACK(showInfo), NULL);
  g_signal_connect(G_OBJECT(newf), "activate", G_CALLBACK(createKML), this);
  g_signal_connect(G_OBJECT(open), "activate", G_CALLBACK(openFile), this);
  g_signal_connect(G_OBJECT(save_as), "activate", G_CALLBACK(saveFile), this);
  g_signal_connect(G_OBJECT(z_auto), "activate", G_CALLBACK(setAutoZoom), this);
  g_signal_connect(G_OBJECT(z_man), "activate", G_CALLBACK(setManualZoom), this);
  g_signal_connect(G_OBJECT(match), "activate", G_CALLBACK(matchScale), this);
  g_signal_connect(G_OBJECT(save_to_pdf), "activate", G_CALLBACK(exportPdf), this);
  g_signal_connect(G_OBJECT(save_to_png), "activate", G_CALLBACK(exportPng), this);
  g_signal_connect(G_OBJECT(closer), "activate", G_CALLBACK(setCloser), this);
  g_signal_connect(G_OBJECT(further), "activate", G_CALLBACK(setFurther), this);
  g_signal_connect(G_OBJECT(document), "activate", G_CALLBACK(addDocument), this);
  g_signal_connect(G_OBJECT(folder), "activate", G_CALLBACK(addFolder), this);
  g_signal_connect(G_OBJECT(iconStyle), "activate", G_CALLBACK(addIconStyle), this);
  g_signal_connect(G_OBJECT(innerBoundaryIs), "activate", G_CALLBACK(addInnerBoundaryIs), this);
  g_signal_connect(G_OBJECT(linearRing), "activate", G_CALLBACK(addLinearRing), this);
  g_signal_connect(G_OBJECT(lineString), "activate", G_CALLBACK(addLineString), this);
  g_signal_connect(G_OBJECT(lineStyle), "activate", G_CALLBACK(addLineStyle), this);
  g_signal_connect(G_OBJECT(mulitgeometry), "activate", G_CALLBACK(addMulitgeometry), this);
  g_signal_connect(G_OBJECT(outerBoundaryIs), "activate", G_CALLBACK(addOuterBoundaryIs), this);
  g_signal_connect(G_OBJECT(placemark), "activate", G_CALLBACK(addPlacemark), this);
  g_signal_connect(G_OBJECT(point), "activate", G_CALLBACK(addPoint), this);
  g_signal_connect(G_OBJECT(polygon), "activate", G_CALLBACK(addPolygon), this);
  g_signal_connect(G_OBJECT(polyStyle), "activate", G_CALLBACK(addPolyStyle), this);
  g_signal_connect(G_OBJECT(style), "activate", G_CALLBACK(addStyle), this);

  /*skróty klawiszowe*/
  gtk_widget_add_accelerator(quit, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); //skróty klawiszowe
  gtk_widget_add_accelerator(open, "activate", accel_group, GDK_o, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(save_as, "activate", accel_group, GDK_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(newf, "activate", accel_group, GDK_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(closer, "activate", accel_group, GDK_plus, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(further, "activate", accel_group, GDK_minus, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

  /**/
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), file_menu); // łączymy kategorie z nazwami
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(add), add_menu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(view), view_menu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), help_menu);

  /**/
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), newf); // łączymy kategorie z opcjami
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_as);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), sep1);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_to_pdf);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_to_png);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), sep2);
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit);
  gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), about);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), document);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), folder);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), iconStyle);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), innerBoundaryIs);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), linearRing);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), lineString);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), lineStyle);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), mulitgeometry);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), outerBoundaryIs);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), placemark);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), point);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), polygon);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), polyStyle);
  gtk_menu_shell_append(GTK_MENU_SHELL(add_menu), style);
  gtk_menu_shell_append(GTK_MENU_SHELL(view_menu), z_auto);
  gtk_menu_shell_append(GTK_MENU_SHELL(view_menu), z_man);
  gtk_menu_shell_append(GTK_MENU_SHELL(view_menu), match);
  gtk_menu_shell_append(GTK_MENU_SHELL(view_menu), closer);
  gtk_menu_shell_append(GTK_MENU_SHELL(view_menu), further);

  gtk_menu_shell_append(GTK_MENU_SHELL(menu), file); //łaczymy kategorie z menu
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), add);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), view);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), help);

  gtk_widget_set_sensitive(document, FALSE);
  gtk_widget_set_sensitive(closer, FALSE);
  gtk_widget_set_sensitive(further, FALSE);
  gtk_widget_set_sensitive(match, FALSE);
  setAllInactive();

  //boxowanie

  gtk_box_set_homogeneous(GTK_BOX(vbox), FALSE);
  gtk_box_set_homogeneous(GTK_BOX(hbox), FALSE);

  gtk_box_pack_start(GTK_BOX(vbox), menu, FALSE, FALSE, 0);
  gtk_box_pack_end(GTK_BOX(vbox), status_bar, FALSE, FALSE, 0);
  gtk_box_pack_end(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(treew), tree);

  gtk_box_pack_start(GTK_BOX(hbox), canvas, TRUE, TRUE, 0);
  gtk_box_pack_end(GTK_BOX(hbox), treew, FALSE, FALSE, 0);


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
  std::cout << "1234\n";
  MainWindow *mw = static_cast<MainWindow*> (data);
  if (mw->edited && !mw->printAsk())
  {
    std::cout << "1234\n";
    return;
  }
  gtk_main_quit();
}

void MainWindow::buttonclicked(GtkWidget *widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);

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

  MainWindow *mw = static_cast<MainWindow*> (data);

  mw->drawKMLwithMap();

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
          "AGH\nInformatyka stosowana,\nIII rok");
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(info), "https://sourceforge.net/projects/tmapper/");
  GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("icon.png", NULL);
  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(info), pixbuf);
  g_object_unref(pixbuf), pixbuf = NULL;
  gtk_dialog_run(GTK_DIALOG(info));
  gtk_widget_destroy(info);
  //gtk_main();
}

void MainWindow::openFile(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  if (mw->edited && !mw->printAsk())
  {
    return;
  }
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
      std::string ff = "TMapper (";
      ff += filename;
      ff += ")";
      gtk_window_set_title(GTK_WINDOW(mw->map), ff.c_str());
    }
    g_free(filename);
  }
  gtk_widget_destroy(chooser);
  MainWindow::paint(widget, 0, data);
  mw->edited = false;
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
    mw->getAnaliser()->saveKMLToFile(string(filename));
    std::string ff = "TMapper (";
    ff += filename;
    ff += ")";
    gtk_window_set_title(GTK_WINDOW(mw->map), ff.c_str());
    g_free(filename);
  }
  gtk_widget_destroy(chooser);
}

void MainWindow::drawKML()
{
  printTree();
  model = GTK_TREE_MODEL(treestore);
  gtk_tree_view_set_model(GTK_TREE_VIEW(tree), model);
  g_object_unref(model);
  if (strpath != "")
  {
    GtkTreePath *p;
    p = gtk_tree_path_new_from_string(strpath.c_str());
    gtk_tree_view_expand_to_path(GTK_TREE_VIEW(tree), p);
    gtk_tree_path_free(p);
  }
  cairo_t *cr = gdk_cairo_create(canvas->window);
  cairo_set_source_rgb(cr, 1, 1, 1);
  cairo_paint(cr);

  if (!analiser->GetKML()) //nie można narysować
  {
    return;
  }

  calcParameters();
  analiser->GetKML()->draw(cr, a_x, b_x, a_y, b_y, NULL);
  cairo_destroy(cr);
}

void MainWindow::drawKMLwithMap()
{
  drawKML();
  if (analiser->GetKML())
  {
    mapCoordinates();
  }
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
      //std::cout << "gedit " << ss.str().c_str() << " " << file.c_str() << "\n";
      execlp("gedit", "gedit", ss.str().c_str(), file.c_str(), 0); //FIXME: do zmiany kiedyś może //TODO: do poprawy
    }
  }
  gtk_widget_destroy(error);
  //gtk_main();
}

void MainWindow::convertToPolish(std::string& s) //TODO: Zmienić na pobranie i podzielenie na części względem np. # albo po angielsku
{
  ifstream file("pl_text");
  if (file.eof())
  {
    return;
  }
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

void MainWindow::printTree()
{
  treestore = gtk_tree_store_new(1, G_TYPE_STRING);
  if (analiser->GetKML())
  {
    analiser->GetKML()->makeTree(treestore, NULL);
  }
}

void MainWindow::canvas_button_press(GtkWidget* widget, GdkEventButton* event, gpointer data)
{
  //czyszczenie staticów
  while (!MainWindow::items.empty())
  {
    gtk_widget_destroy(MainWindow::items.front());
    MainWindow::items.erase(MainWindow::items.begin());
  }
  MainWindow::tmp_nr.clear();
  if (MainWindow::menu_popup) gtk_widget_destroy(menu_popup);

  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->mouse_clicked = true;
  std::vector<double>::iterator x, y, endx;
  std::vector<Coordinates*>::iterator cor;
  std::vector<int>::iterator cor_nr;
  x = mw->coors_posx.begin();
  y = mw->coors_posy.begin();
  cor = mw->coors_ptr.begin();
  cor_nr = mw->coors_nr.begin();
  endx = mw->coors_posx.end();
  int nr = 0;
  int i = 0;
  for (std::vector<double>::iterator it = mw->coors_posx.begin(); it != endx; it++, x++, y++, cor++, cor_nr++, i++)
  {
    if ((*x) - 10 < event->x && event->x < (*x) + 10 && (*y) - 10 < event->y && event->y < (*y) + 10)
    {
      nr++;
      mw->act_nr = i;
      MainWindow::tmp_nr.push_back(i);
    }
  }
  if (event->button == 3) // PPM - wybór
  {
    mw->act = 0;
    MainWindow::menu_popup = gtk_menu_new();
    std::vector<GtkWidget*> items;
    std::vector<int>::iterator it = MainWindow::tmp_nr.begin();
    std::vector<int>::iterator end = MainWindow::tmp_nr.end();
    for (; it != end; it++)
    {
      node *n = mw->coors_ptr[*it];
      while (!dynamic_cast<Placemark*> (n))
      {
        n = n->GetParent();
      }
      if (n->getSubName() != "")
      {
        items.push_back(gtk_menu_item_new_with_label(n->getSubName().c_str()));
      }
      else
      {
        items.push_back(gtk_menu_item_new_with_label(mw->coors_ptr[*it]->GetParent()->GetName().c_str()));
      }
      g_signal_connect(items.back(), "activate", (GCallback) setCoord, &(*it)); //*/
      gtk_menu_append(menu_popup, items.back());
    }
    gtk_widget_show_all(menu_popup);
    gtk_menu_popup(GTK_MENU(menu_popup), NULL, NULL, NULL, NULL,
            event->button, event->time);
  }
  else // LPM
  {
    if (nr == 1) //jeśli LPM to bierzemy jak jest jedne w okolicy 
    {
      move_ok = true;
      move_nr = mw->act_nr;
    }
    else if (nr > 1)
    {
      gtk_statusbar_pop(GTK_STATUSBAR(mw->status_bar), STATUS_ERR_CONT);
      gtk_statusbar_pop(GTK_STATUSBAR(mw->status_bar), STATUS_POZ_CONT);
      gchar *str;
      str = g_strdup_printf("W tym miejscu jest więcej niż jeden punkt, wciśnij prawy przycisk myszy, by wybrać.");
      gtk_statusbar_push(GTK_STATUSBAR(mw->status_bar), STATUS_ERR_CONT, str);
    }
    else
    {
      if (!mw->zoom_auto && !move_ok) mw->zoom_can = true;
    }
  }
}

void MainWindow::setCoord(GtkWidget* widget, gpointer data)
{
  move_ok = true;
  move_nr = *(int*) data;
  gtk_widget_destroy(widget->parent);
}

void MainWindow::canvas_button_release(GtkWidget* widget, GdkEventButton* event, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->mouse_clicked = false;
  if (move_ok)
  {
    mw->act = 0;
    mw->drawKMLwithMap();
    move_ok = false;
    mw->edited = true;
  }
  else if (mw->zoom_can)
  {
    mw->old_x = -1;
    mw->zoom_can = false;
    mw->drawKMLwithMap();
  }
}

void MainWindow::canvas_mouse_move(GtkWidget* widget, GdkEventButton* event, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  if (mw->mouse_clicked && move_ok)
  {
    mw->act = mw->coors_ptr[MainWindow::move_nr];
    mw->act_nr = mw->coors_nr[MainWindow::move_nr];
    double *tmp = mw->act->getCoordinates(mw->act_nr);
    tmp[0] = event->x / mw->a_x + mw->b_x;
    tmp[1] = event->y / mw->a_y + mw->b_y;
    mw->drawKML();
  }
  else if (mw->zoom_can)
  {
    if (mw->old_x != -1)
    {
      double dx = mw->zoom_max_x - mw->zoom_min_x;
      double dy = mw->zoom_max_y - mw->zoom_min_y;
      mw->zoom_max_x -= ((double) event->x - (double) mw->old_x) / ((double) mw->width) * dx;
      mw->zoom_min_x -= ((double) event->x - (double) mw->old_x) / ((double) mw->width) * dx;
      mw->zoom_max_y += ((double) event->y - (double) mw->old_y) / ((double) mw->height) * dy;
      mw->zoom_min_y += ((double) event->y - (double) mw->old_y) / ((double) mw->height) * dy;
    }
    mw->old_x = event->x;
    mw->old_y = event->y;
    mw->drawKML();
  }
  gtk_statusbar_pop(GTK_STATUSBAR(mw->status_bar), STATUS_ERR_CONT);
  gtk_statusbar_pop(GTK_STATUSBAR(mw->status_bar), STATUS_POZ_CONT);
  gchar *str;
  str = g_strdup_printf("Pozycja kursora w rzeczywistości: (%lf, %lf)",
          event->x / mw->a_x + mw->b_x, event->y / mw->a_y + mw->b_y);
  gtk_statusbar_push(GTK_STATUSBAR(mw->status_bar), STATUS_POZ_CONT, str);
}

void MainWindow::mapCoordinates()
{
  coors_posx.clear();
  coors_posy.clear();
  coors_ptr.clear();
  coors_nr.clear();
  analiser->GetKML()->mapCoordinates(this, a_x, b_x, a_y, b_y);
}

void MainWindow::calcParameters()
{
  double min_x, max_x, min_y, max_y;
  gtk_window_get_size(GTK_WINDOW(map), &width, &height);
  width -= TREE_SIZE;
  height -= MENU_SIZE + STATUS_SIZE;

  if (zoom_auto)
  {
    min_x = min_y = DBL_MAX;
    max_x = max_y = -DBL_MAX;

    analiser->GetKML()->findHW(max_x, min_x, max_y, min_y);

    max_x += 1;
    max_y += 1;
    min_x -= 1;
    min_y -= 1;
    zoom_max_x = max_x;
    zoom_max_y = max_y;
    zoom_min_y = min_y;
    zoom_min_x = min_x;
  }
  else
  {
    max_x = zoom_max_x;
    max_y = zoom_max_y;
    min_x = zoom_min_x;
    min_y = zoom_min_y;
  }

  a_x = width / (max_x - min_x);
  b_x = min_x;
  a_y = height / (min_y - max_y);
  b_y = max_y;
}

void MainWindow::addCoordinate(double x, double y, Coordinates* cor, int nr)
{
  coors_posx.push_back(x);
  coors_posy.push_back(y);
  coors_ptr.push_back(cor);
  coors_nr.push_back(nr);
}

void MainWindow::tree_row_activated(GtkTreeView* tree_view, GtkTreePath* path, GtkTreeViewColumn* column, gpointer user_data)
{
  MainWindow *mw = static_cast<MainWindow*> (user_data);
  if (!mw->can_edit)
  {
    return;
  }
  mw->can_edit = false;
  gchar *p;
  p = gtk_tree_path_to_string(path);
  std::string spath(p);
  g_free(p);
  mw->showEditNode(mw->getAnaliser()->GetKML()->findFromTreeView(spath));
}

void MainWindow::showEditNode(node* n)
{
  if (!n->ifShow())
  {
    gtk_statusbar_pop(GTK_STATUSBAR(status_bar), STATUS_ERR_CONT);
    gtk_statusbar_pop(GTK_STATUSBAR(status_bar), STATUS_POZ_CONT);
    gchar *str;
    str = g_strdup_printf("Nie możesz edytować tego obiektu, edytuj obiekt wyżej.");
    gtk_statusbar_push(GTK_STATUSBAR(status_bar), STATUS_ERR_CONT, str);
    can_edit = true;
    return;
  }
  MainWindow::node_edit = n;
  GtkWidget *edit = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  std::string window_name = ("Edycja obiektu " + n->getSubName() + " typu " + n->GetName());
  gtk_window_set_title(GTK_WINDOW(edit), window_name.c_str());
  gtk_widget_set_size_request(edit, 800, 400);
  gtk_window_set_deletable(GTK_WINDOW(edit), FALSE);
  g_signal_connect(G_OBJECT(map), "destroy", G_CALLBACK(voidFunction), this);


  /* ustawienie 1*/
  GtkWidget *hbox, *vbox;
  vbox = gtk_vbox_new(GTK_ORIENTATION_VERTICAL, 1);
  hbox = gtk_hbox_new(GTK_ORIENTATION_HORIZONTAL, 1);
  gtk_container_add(GTK_CONTAINER(edit), vbox);

  n->paintEditWindow(vbox);
  gtk_box_pack_end(GTK_BOX(vbox), hbox, TRUE, TRUE, 4);

  /*przyciski*/
  GtkWidget *button_ok, *button_cancel, *button_apply, *button_remove, *button_add;

  if (n->ifRemove())
  {
    button_remove = gtk_button_new_with_label("Usuń");
    g_signal_connect(G_OBJECT(button_remove), "clicked", G_CALLBACK(editButtonRemove), this);
    gtk_box_pack_start(GTK_BOX(hbox), button_remove, TRUE, TRUE, 5);
  }

  button_cancel = gtk_button_new_with_label("Anuluj");

  g_signal_connect(G_OBJECT(button_cancel), "clicked", G_CALLBACK(editButtonCancel), this);
  gtk_box_pack_start(GTK_BOX(hbox), button_cancel, TRUE, TRUE, 5);
  if (!n->ifRemoveOlny())
  {
    button_ok = gtk_button_new_with_label("OK");
    button_apply = gtk_button_new_with_label("Zastosuj");
    g_signal_connect(G_OBJECT(button_apply), "clicked", G_CALLBACK(editButtonApply), this);
    g_signal_connect(G_OBJECT(button_ok), "clicked", G_CALLBACK(editButtonOk), this);
    gtk_box_pack_start(GTK_BOX(hbox), button_apply, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(hbox), button_ok, TRUE, TRUE, 5);
  }

  gtk_widget_show_all(edit);
}

void MainWindow::editButtonApply(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_edit->saveFromEditWindow(widget->parent->parent);
  mw->getAnaliser()->GetKML()->connectStyles();
  mw->drawKMLwithMap();
}

void MainWindow::editButtonCancel(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->can_edit = true;
  gtk_widget_destroy(widget->parent->parent->parent);
}

void MainWindow::editButtonOk(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->can_edit = true;
  node_edit->saveFromEditWindow(widget->parent->parent);
  mw->getAnaliser()->GetKML()->connectStyles();
  gtk_widget_destroy(widget->parent->parent->parent);
  mw->drawKMLwithMap();
  mw->edited = true;
}

void MainWindow::editButtonRemove(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->can_edit = true;
  if (dynamic_cast<Document*> (node_edit))
  {
    gtk_widget_set_sensitive(mw->document, TRUE);
  }
  mw->setAllInactive();
  node_edit->GetParent()->RemoveChild(node_edit);
  node_edit = 0;
  mw->getAnaliser()->GetKML()->connectStyles();
  gtk_widget_destroy(widget->parent->parent->parent);
  mw->drawKMLwithMap();
}

void MainWindow::tree_row_selected(GtkTreeView* tree_view, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->setAllInactive();
  GtkTreePath *path;
  gtk_tree_view_get_cursor(GTK_TREE_VIEW(mw->tree), &path, NULL);
  gchar *p;
  p = gtk_tree_path_to_string(path);
  std::string spath(p);
  gtk_tree_path_free(path);
  mw->strpath = spath;
  g_free(p);
  MainWindow::node_add = mw->getAnaliser()->GetKML()->findFromTreeView(spath);
  mw->setPosobilities(node_add->getPosibilities());
}

void MainWindow::setPosobilities(std::list<std::string> *list)
{
  if (!list)
  {
    return;
  }
  int n = 13;
  std::string tab[] = {
    "Folder",
    "IconStyle",
    "InnerBoundaryIs",
    "LinearRing",
    "LineString",
    "LineStyle",
    "Multigeometry",
    "OuterBoundaryIs",
    "Placemark",
    "Point",
    "Polygon",
    "PolyStyle",
    "Style"
  };

  std::string tmp = list->front();

  for (int i = 0; i < n; i++)
  {
    if (tab[i] == tmp)
    {
      switch (i)
      {
        case 0:
          gtk_widget_set_sensitive(folder, TRUE);
          break;
        case 1:
          gtk_widget_set_sensitive(iconStyle, TRUE);
          break;
        case 2:
          gtk_widget_set_sensitive(innerBoundaryIs, TRUE);
          break;
        case 3:
          gtk_widget_set_sensitive(linearRing, TRUE);
          break;
        case 4:
          gtk_widget_set_sensitive(lineString, TRUE);
          break;
        case 5:
          gtk_widget_set_sensitive(lineStyle, TRUE);
          break;
        case 6:
          gtk_widget_set_sensitive(mulitgeometry, TRUE);
          break;
        case 7:
          gtk_widget_set_sensitive(outerBoundaryIs, TRUE);
          break;
        case 8:
          gtk_widget_set_sensitive(placemark, TRUE);
          break;
        case 9:
          gtk_widget_set_sensitive(point, TRUE);
          break;
        case 10:
          gtk_widget_set_sensitive(polygon, TRUE);
          break;
        case 11:
          gtk_widget_set_sensitive(polyStyle, TRUE);
          break;
        case 12:
          gtk_widget_set_sensitive(style, TRUE);
          break;
      }
      list->erase(list->begin());
      if (list->size())
      {
        tmp = list->front();
      }
      else
      {
        i = 14;
      }
    }
  }
  delete list;
}

void MainWindow::setAllInactive()
{
  gtk_widget_set_sensitive(folder, FALSE);
  gtk_widget_set_sensitive(iconStyle, FALSE);
  gtk_widget_set_sensitive(innerBoundaryIs, FALSE);
  gtk_widget_set_sensitive(linearRing, FALSE);
  gtk_widget_set_sensitive(lineString, FALSE);
  gtk_widget_set_sensitive(lineStyle, FALSE);
  gtk_widget_set_sensitive(mulitgeometry, FALSE);
  gtk_widget_set_sensitive(outerBoundaryIs, FALSE);
  gtk_widget_set_sensitive(placemark, FALSE);
  gtk_widget_set_sensitive(point, FALSE);
  gtk_widget_set_sensitive(polygon, FALSE);
  gtk_widget_set_sensitive(polyStyle, FALSE);
  gtk_widget_set_sensitive(style, FALSE);
}

void MainWindow::addDocument(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->getAnaliser()->GetKML()->AddChild(new Document());
  mw->drawKMLwithMap();
  gtk_widget_set_sensitive(mw->document, FALSE);
}

void MainWindow::addFolder(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new Folder());
  mw->drawKMLwithMap();
}

void MainWindow::addIconStyle(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new IconStyle());
  mw->drawKMLwithMap();
}

void MainWindow::addInnerBoundaryIs(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new InnerBoundaryIs());
  mw->drawKMLwithMap();
}

void MainWindow::addLinearRing(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new LinearRing());
  mw->drawKMLwithMap();
}

void MainWindow::addLineString(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new LineString());
  mw->drawKMLwithMap();
}

void MainWindow::addLineStyle(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new LineStyle());
  mw->drawKMLwithMap();
}

void MainWindow::addMulitgeometry(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new Multigeometry());
  mw->drawKMLwithMap();
}

void MainWindow::addOuterBoundaryIs(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new OuterBoundaryIs());
  mw->drawKMLwithMap();
}

void MainWindow::addPlacemark(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new Placemark());
  mw->drawKMLwithMap();
}

void MainWindow::addPoint(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new Point());
  mw->drawKMLwithMap();
}

void MainWindow::addPolygon(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new Polygon());
  mw->drawKMLwithMap();
}

void MainWindow::addPolyStyle(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new PolyStyle());
  mw->drawKMLwithMap();
}

void MainWindow::addStyle(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  node_add->AddChild(new Style());
  mw->drawKMLwithMap();
}

void MainWindow::createKML(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  if (mw->edited && !mw->printAsk())
  {
    return;
  }
  mw->getAnaliser()->createKML();
  gtk_widget_set_sensitive(mw->document, TRUE);
  std::string ff = "TMapper (nowy plik)";
  gtk_window_set_title(GTK_WINDOW(mw->map), ff.c_str());
  mw->drawKMLwithMap();
  mw->edited = false;
}

void MainWindow::setAutoZoom(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->zoom_auto = true;
  mw->drawKMLwithMap();
  gtk_widget_set_sensitive(mw->closer, FALSE);
  gtk_widget_set_sensitive(mw->further, FALSE);
  gtk_widget_set_sensitive(mw->match, FALSE);
}

void MainWindow::setManualZoom(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->zoom_auto = false;
  mw->zoom_can = false;
  mw->old_x = mw->old_y = -1;
  gtk_widget_set_sensitive(mw->closer, TRUE);
  gtk_widget_set_sensitive(mw->further, TRUE);
  gtk_widget_set_sensitive(mw->match, TRUE);
}

void MainWindow::setCloser(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->zoom_max_x -= (mw->zoom_max_x - mw->zoom_min_x) / 4.0;
  mw->zoom_min_x += (mw->zoom_max_x - mw->zoom_min_x) / 4.0;
  mw->zoom_max_y -= (mw->zoom_max_y - mw->zoom_min_y) / 4.0;
  mw->zoom_min_y += (mw->zoom_max_y - mw->zoom_min_y) / 4.0;
  mw->drawKMLwithMap();
}

void MainWindow::setFurther(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->zoom_max_x += (mw->zoom_max_x - mw->zoom_min_x) / 2.0;
  mw->zoom_min_x -= (mw->zoom_max_x - mw->zoom_min_x) / 2.0;
  mw->zoom_max_y += (mw->zoom_max_y - mw->zoom_min_y) / 2.0;
  mw->zoom_min_y -= (mw->zoom_max_y - mw->zoom_min_y) / 2.0;
  mw->drawKMLwithMap();
}

void MainWindow::exportPdf(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  if (!mw->getAnaliser()->GetKML()) //nie można narysować
  {
    return;
  }

  GtkWidget *chooser = gtk_file_chooser_dialog_new("Zapisz jako PDF",
          GTK_WINDOW(mw->map),
          GTK_FILE_CHOOSER_ACTION_SAVE,
          GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
          GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
          NULL);
  if (gtk_dialog_run(GTK_DIALOG(chooser)) == GTK_RESPONSE_ACCEPT)
  {
    char *filename;
    filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
    cairo_surface_t * sur = cairo_pdf_surface_create(filename, (double) mw->width, (double) mw->height);
    cairo_t * cr = cairo_create(sur);
    mw->getAnaliser()->GetKML()->draw(cr, mw->a_x, mw->b_x, mw->a_y, mw->b_y, NULL);
    cairo_show_page(cr);
    cairo_paint(cr);
    //   cairo_surface_flush(sur);
    cairo_surface_destroy(sur);
    cairo_destroy(cr);
    g_free(filename);
  }
  gtk_widget_destroy(chooser);
}

void MainWindow::exportPng(GtkWidget* widget, gpointer data)
{
  MainWindow *mw = static_cast<MainWindow*> (data);
  if (!mw->getAnaliser()->GetKML()) //nie można narysować
  {
    return;
  }

  GtkWidget *chooser = gtk_file_chooser_dialog_new("Zapisz jako PNG",
          GTK_WINDOW(mw->map),
          GTK_FILE_CHOOSER_ACTION_SAVE,
          GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
          GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
          NULL);
  if (gtk_dialog_run(GTK_DIALOG(chooser)) == GTK_RESPONSE_ACCEPT)
  {
    char *filename;
    filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
    cairo_surface_t * sur = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, mw->width, mw->height);
    cairo_t * cr = cairo_create(sur);
    mw->getAnaliser()->GetKML()->draw(cr, mw->a_x, mw->b_x, mw->a_y, mw->b_y, NULL);
    cairo_surface_write_to_png(sur, filename);
    cairo_destroy(cr);
    cairo_surface_destroy(sur);
    g_free(filename);
  }
  gtk_widget_destroy(chooser);
}

void MainWindow::matchScale(GtkWidget* widget, gpointer data)
{

  MainWindow *mw = static_cast<MainWindow*> (data);
  mw->zoom_auto = true;
  mw->drawKMLwithMap();
  mw->zoom_auto = false;
}

bool MainWindow::printAsk()
{
  
  bool tmp = true;
  GtkWidget *error = gtk_message_dialog_new(GTK_WINDOW(map), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_YES_NO,
          "Czy chcesz utracić zmiany?");
  gtk_window_set_title(GTK_WINDOW(error), "Dokonano zmian");
  gint response = gtk_dialog_run(GTK_DIALOG(error));
  if (response == GTK_RESPONSE_NO)
  {
    tmp = false;
  }
  gtk_widget_destroy(error);
  return tmp;
}


void MainWindow::voidFunction(GtkWidget* widget, gpointer data)
{
  
}