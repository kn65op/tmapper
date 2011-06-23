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
#include <list>
#include <vector>

class Coordinates;
class KML;
class Analiser;

class MainWindow
{
public:
  MainWindow(int argc, char **argv);
  MainWindow(const MainWindow& orig);
  virtual ~MainWindow();
  void init(int, char**);
  void build();
  void run();

  static void showError(const char *s, int line, MainWindow *mw);
  void addCoordinate(double x, double y, Coordinates* cor, int nr);

  /*GtkWidget* getMap() const
  {
    return map;
  }//*/

  /*KML* getKML() const
  {
    return kml;
  }

  void setKML(KML* kml)
  {
    this->kml = kml;
  }//*/

  Analiser* getAnaliser() const
  {
    return analiser;
  }

  void setAnaliser(Analiser* analiser)
  {
    this->analiser = analiser;
  }

private:
  /*zmienne gtk*/
  GtkWidget *map;
  GtkWidget *tree;
  GtkWidget *treew;
  GtkWidget *vbox; // box na menu i resztę
  GtkWidget *hbox; // box na rzeczy w mapie
  GtkWindowGroup * wg;
  GtkTreeViewColumn *col;
  GtkCellRenderer *renderer;
  GtkTreeModel *model;
  GtkTreeStore *treestore;
  std::string programtitle;

  GtkWidget *canvas;
  GtkWidget *button;

  /*menu:*/
  GtkWidget *menu;
  GtkWidget *file_menu;
  GtkWidget *help_menu;
  GtkWidget *file;
  GtkWidget *help;
  GtkWidget *newf;
  GtkWidget *open;
  GtkWidget *save_as;
  GtkWidget *quit;
  GtkWidget *about;
  GtkWidget *sep;

  GtkAccelGroup *accel_group;

  /*funkcje gtk*/
  static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
  static void destroy(GtkWidget *widget, gpointer data);
  static void buttonclicked(GtkWidget *widget, gpointer data);
  static void setCoord(GtkWidget *widget, gpointer data);
  static void canvas_button_press(GtkWidget *widget, GdkEventButton * event, gpointer data);
  static void canvas_mouse_move(GtkWidget *widget, GdkEventButton * event, gpointer data);
  static void canvas_button_release(GtkWidget *widget, GdkEventButton * event, gpointer data);
  static void showInfo(GtkWidget *widget, gpointer data);
  static void openFile(GtkWidget *widget, gpointer data);
  static void saveFile(GtkWidget *widget, gpointer data);
  static void showNoFile(MainWindow *mw);

  static void paint(GtkWidget *widget, GdkEventExpose *eev, gpointer data);

  void printTree();

  /* do błędów*/
  static void convertToPolish(std::string &s);
  /*zmienne do do map*/
  //KML *kml;
  Analiser *analiser;
  /* inne zmienne*/
  bool mouse_clicked;
  int width;
  int height;
  double a_x, b_x, a_y, b_y;
  std::vector<double> coors_posx;
  std::vector<double> coors_posy;
  std::vector<int> coors_nr;
  std::vector<Coordinates*> coors_ptr;
  Coordinates* act;
  int act_nr;

  static std::vector<GtkWidget*> items;
  static std::vector<int> tmp_nr;
  static bool move_ok;
  static int move_nr;
  static GtkWidget *menu_popup;

  /* Funkcje inne*/
  void drawKML();
  void drawKMLwithMap();
  void mapCoordinates();
  void calcParameters();

};

#endif	/* MAINWINDOW_H */
