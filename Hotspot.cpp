/* 
 * File:   Hotspot.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:20
 */

#include "Hotspot.h"

using namespace std;

#include <string>
#include <fstream>
#include <gtk-2.0/gtk/gtk.h>
#include <sstream>

#include "node.h"

Hotspot::Hotspot()
{
  init();
}

Hotspot::Hotspot(std::string *s) : node(s)
{
  init();
}

Hotspot::Hotspot(const Hotspot& orig)
{
}

Hotspot::Hotspot(std::string x, std::string y, std::string xunits, std::string yunits)
{
  init();
  setX(x);
  setY(y);
  setXunits(xunits);
  setYunits(yunits);
}

Hotspot::~Hotspot()
{
}

void Hotspot::init()
{
  name = "hotSpot";
  x = 0;
  y = 0;
  xunits = "";
  yunits = "";
}

void Hotspot::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  of << "<" << name << " x=\"" << x << "\" y=\"" << y << "\" xunits=" << xunits << " yunits=" << yunits << "/>";
  of.close();
}

void Hotspot::makeTree(GtkTreeStore* treestore, GtkTreeIter* parent)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  GtkTreeIter *next = new GtkTreeIter();
  GtkTreeIter *t = new GtkTreeIter();
  gtk_tree_store_append(treestore, t, parent);
  gtk_tree_store_set(treestore, t, 0, name.c_str(), -1);
  stringstream ss, ss1, ss2, ss3;
  ss << "x = " << x;
  gtk_tree_store_append(treestore, next, t);
  gtk_tree_store_set(treestore, next, 0, ss.str().c_str(), -1);
  ss1 << "y = " << y;
  gtk_tree_store_append(treestore, next, t);
  gtk_tree_store_set(treestore, next, 0, ss1.str().c_str(), -1);
  ss2 << "xunits = " << xunits;
  gtk_tree_store_append(treestore, next, t);
  gtk_tree_store_set(treestore, next, 0, ss2.str().c_str(), -1);
  ss3 << "yunits = " << yunits;
  gtk_tree_store_append(treestore, next, t);
  gtk_tree_store_set(treestore, next, 0, ss3.str().c_str(), -1);
  delete next;
  delete t;
}

void Hotspot::setAll(std::string x, std::string y, std::string xunits, std::string yunits)
{
  setX(x);
  setY(y);
  setXunits(xunits);
  setYunits(yunits);
}

node* Hotspot::findFromTreeView(std::string s)
{
  return this;
}

bool Hotspot::ifShow()
{
  return false;
}