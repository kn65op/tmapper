/* 
 * File:   node.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 14:26
 */

#ifndef NODE_H
#define	NODE_H

#include <list>
#include <iostream>
#include <string>
#include <cairo/cairo.h>
#include <gtk-2.0/gtk/gtk.h>

class KML;
class MainWindow;

class node
{
public:
  node();
  node(std::string* i);
  node(const node& orig);
  virtual ~node();

  friend std::ostream& operator<<(std::ostream& out, const node& n);

  double* getColor();

  virtual void saveToFile(std::string file, int level);
  virtual void draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color);
  virtual void findHW(double& max_x, double& min_x, double& max_y, double& min_y);
  virtual void searchStyle(KML* kml);
  virtual void removeStyle(KML* kml);
  virtual void connectStyle(KML* kml);
  virtual void makeTree(GtkTreeStore* treestore, GtkTreeIter* parent);
  virtual void mapCoordinates(MainWindow *mw, double a_x, double b_x, double a_y, double b_y);
  virtual node* findFromTreeView(std::string s);
  virtual void paintEditWindow(GtkWidget *box);
  virtual void saveFromEditWindow(GtkWidget *box);

  std::string getSubName();
  void setSubName(std::string n);
  
  void setDescription(std::string n);
  void setVisibility(std::string n);
  void setOutline(std::string n);
  void setFill(std::string n);
  void setStyleUrl(std::string n);
  void setColor(std::string n);
  void setIcon(std::string n);
  void setWidth(std::string n);
  void setHotspot(std::string x, std::string y, std::string xunits, std::string yunits);

  std::list<node*> GetChildren() const
  {
    return children;
  }

  void SetChildren(std::list<node*> children)
  {
    this->children = children;
  }

  node* GetParent() const
  {
    return parent;
  }

  void SetParent(node* parent)
  {
    this->parent = parent;
  }

  void AddChild(node* child)
  {
    children.push_back(child);
    child->SetParent(this);
  }

  void RemoveChild(node* child)
  {
    delete child;
    children.remove(child);
    child = 0;
  }

  std::string GetName() const
  {
    return name;
  }

  void SetName(std::string name)
  {
    this->name = name;
  }

  std::string GetId() const
  {
    return id;
  }

  void SetId(std::string id)
  {
    this->id = id;
  }

  node* GetLastChild()
  {
    return children.back();
  }


protected:
  node *parent;
  std::list<node*> children;
  std::string name;
  std::string id;
  virtual void init()=0;
  void saveOpeningTag(std::ofstream& of);
  void saveClosingTag(std::ofstream& of);
  void drawChildren(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color);

  void paintName(GtkWidget *box);
  void paintColor(GtkWidget *box);
  void paintIcon(GtkWidget *box);
  void paintDescription(GtkWidget *box);
  void paintVisibility(GtkWidget *box);
  void paintStyleUrl(GtkWidget *box);
  void paintId(GtkWidget *box);
  void paintHotspot(GtkWidget *box);
  void paintFill(GtkWidget *box);
  void paintOutline(GtkWidget *box);
  void paintWidth(GtkWidget *box);
};

#endif	/* NODE_H */

