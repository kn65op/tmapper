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
class node;

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
  GtkWidget *status_bar; //pasek stanu
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
  GtkWidget *view_menu;
  GtkWidget *help_menu;
  GtkWidget *file;
  GtkWidget *view;
  GtkWidget *help;
  GtkWidget *newf;
  GtkWidget *open;
  GtkWidget *save_as;
  GtkWidget *save_to_pdf;
  GtkWidget *save_to_png;
  GtkWidget *quit;
  GtkWidget *about;
  GtkWidget *sep1;
  GtkWidget *sep2;
  GtkWidget *z_auto;
  GtkWidget *z_man;
  GtkWidget *closer;
  GtkWidget *further;
  GtkWidget *match;

  /*menu add*/
  GtkWidget *add;
  GtkWidget *add_menu;
  GtkWidget *document;
  GtkWidget *folder;
  GtkWidget *iconStyle;
  GtkWidget *innerBoundaryIs;
  GtkWidget *linearRing;
  GtkWidget *lineString;
  GtkWidget *lineStyle;
  GtkWidget *mulitgeometry;
  GtkWidget *outerBoundaryIs;
  GtkWidget *placemark;
  GtkWidget *point;
  GtkWidget *polygon;
  GtkWidget *polyStyle;
  GtkWidget *style;

  GtkAccelGroup *accel_group;

  /*funkcje gtk*/
  static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
  static void destroy(GtkWidget *widget, gpointer data);
  static void buttonclicked(GtkWidget *widget, gpointer data);
  static void setCoord(GtkWidget *widget, gpointer data);
  static void tree_row_activated(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data);
  static void canvas_button_press(GtkWidget *widget, GdkEventButton * event, gpointer data);
  static void canvas_mouse_move(GtkWidget *widget, GdkEventButton * event, gpointer data);
  static void canvas_button_release(GtkWidget *widget, GdkEventButton * event, gpointer data);
  static void showInfo(GtkWidget *widget, gpointer data);
  static void openFile(GtkWidget *widget, gpointer data);
  static void saveFile(GtkWidget *widget, gpointer data);
  static void createKML(GtkWidget *widget, gpointer data);
  static void showNoFile(MainWindow *mw);
  static void editButtonOk(GtkWidget *widget, gpointer data);
  static void editButtonCancel(GtkWidget *widget, gpointer data);
  static void editButtonApply(GtkWidget *widget, gpointer data);
  static void editButtonRemove(GtkWidget *widget, gpointer data);
  static void setAutoZoom(GtkWidget *widget, gpointer data);
  static void setManualZoom(GtkWidget *widget, gpointer data);
  static void setCloser(GtkWidget *widget, gpointer data);
  static void setFurther(GtkWidget *widget, gpointer data);
  static void exportPng(GtkWidget *widget, gpointer data);
  static void exportPdf(GtkWidget *widget, gpointer data);
  static void matchScale(GtkWidget *widget, gpointer data);
  static void voidFunction(GtkWidget *widget, gpointer data);

  static void tree_row_selected(GtkTreeView *tree_view, gpointer data);

  static void paint(GtkWidget *widget, GdkEventExpose *eev, gpointer data);

  void printTree();
  void showEditNode(node* n);

  /*dodawanie*/
  void setPosobilities(std::list<std::string>* list);
  void setAllInactive();
  static void addDocument(GtkWidget *widget, gpointer data);
  static void addFolder(GtkWidget *widget, gpointer data);
  static void addIconStyle(GtkWidget *widget, gpointer data);
  static void addInnerBoundaryIs(GtkWidget *widget, gpointer data);
  static void addLinearRing(GtkWidget *widget, gpointer data);
  static void addLineString(GtkWidget *widget, gpointer data);
  static void addLineStyle(GtkWidget *widget, gpointer data);
  static void addMulitgeometry(GtkWidget *widget, gpointer data);
  static void addOuterBoundaryIs(GtkWidget *widget, gpointer data);
  static void addPlacemark(GtkWidget *widget, gpointer data);
  static void addPoint(GtkWidget *widget, gpointer data);
  static void addPolygon(GtkWidget *widget, gpointer data);
  static void addPolyStyle(GtkWidget *widget, gpointer data);
  static void addStyle(GtkWidget *widget, gpointer data);

  bool printAsk();
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

  static node* node_add;

  static node* node_edit;
  bool can_edit;
  
  std::string strpath;
  
  /* zoom */
  bool zoom_auto;
  bool zoom_can;
  double zoom_min_x;
  double zoom_min_y;
  double zoom_max_x;
  double zoom_max_y;
  
  int old_x;
  int old_y;
  bool edited;

  /* Funkcje inne*/
  void drawKML();
  void drawKMLwithMap();
  void mapCoordinates();
  void calcParameters();


};

#endif	/* MAINWINDOW_H */
