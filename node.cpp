/* 
 * File:   node.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 14:26
 */

#include <iosfwd>
#include <iostream>
#include <fstream>
#include <string>
#include <gtk-2.0/gtk/gtk.h>
#include <stdlib.h>

#include "node.h"
#include "textnode.h"
#include "KML.h"
#include "Color.h"
#include "Name.h"
#include "MainWindow.h"

node::node() : id("")
{

}

node::node(std::string *i)
{
  if (i)
  {
    id = i->substr(1, i->size() - 2);
  }
  else
  {
    id = "";
  }
  delete i;
}

node::node(const node& orig)
{
}

node::~node()
{
  while (children.size() != 0)
  {
    delete children.front();
    children.erase(children.begin());
  }
}

std::ostream & operator<<(std::ostream& out, const node& n)
{
  out << n.name << "\n";
  if (n.id != "")
  {
    out << "id: " << n.id << "\n";
  }
  else
  {
    out << "no id\n";
  }
  out << "Children of " << n.name << ":";
  if (n.children.empty())
  {
    out << "none\n";
    return out;
  }
  out << "\n";
  std::list<node*>::const_iterator it, end;
  end = n.children.end();
  for (it = n.children.begin(); it != end; it++)
  {
    out << "child of; " << n.name << " " << **it << "\n";
  }
  out << "End of children from " << n.name << "\n";
  return out;
}

void node::saveToFile(std::string file, int level)
{
  std::ofstream of;
  if (dynamic_cast<KML*> (this))
  {
    of.open(file.c_str());
  }
  else
  {
    of.open(file.c_str(), std::ios::app);
    of << "\n";
  }
  for (int i = 0; i < level; i++) of << "\t";
  ;
  saveOpeningTag(of);
  of.close();
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    (*it)->saveToFile(file, level + 1);
  }
  of.open(file.c_str(), std::ios::app);
  for (int i = 0; i < level; i++) of << "";
  ;
  saveClosingTag(of);
  of.close();
}

void node::saveClosingTag(std::ofstream& of)
{
  of << "</" << name << ">\n";
}

void node::saveOpeningTag(std::ofstream& of)
{
  of << "<" << name;
  if (id != "")
  {
    of << " id=\"" << id << "\"";
  }
  of << ">";
}

void node::draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color)
{
  drawChildren(cr, a_x, b_x, a_y, b_y, color);
}

void node::findHW(double& max_x, double& min_x, double& max_y, double& min_y)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    (*it)->findHW(max_x, min_x, max_y, min_y);
  }
}

void node::drawChildren(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double* color)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    (*it)->draw(cr, a_x, b_x, a_y, b_y, color);
  }
}

void node::searchStyle(KML* kml)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    (*it)->searchStyle(kml);
  }
}

void node::connectStyle(KML* kml)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    (*it)->connectStyle(kml);
  }
}

double* node::getColor()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Color*> (*it))
    {
      return dynamic_cast<Color*> (*it)->getColor();
    }
  }
  return NULL;
}

void node::makeTree(GtkTreeStore* treestore, GtkTreeIter* parent)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  GtkTreeIter *next = new GtkTreeIter();
  gtk_tree_store_append(treestore, next, parent);

  std::string tekst = name;
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Name*> (*it))
    {
      tekst = dynamic_cast<Name*> (*it)->getText() + " (" + name + ")";
    }
  }

  if (id != "")
  {
    tekst += " (" + id + ")";
  }

  gtk_tree_store_set(treestore, next, 0, tekst.c_str(), -1);

  for (it = children.begin(); it != end; it++)
  {
    if (!dynamic_cast<Name*> (*it))
    {
      (*it)->makeTree(treestore, next);
    }
  }
  delete next;
}

void node::mapCoordinates(MainWindow* mw, double a_x, double b_x, double a_y, double b_y)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    (*it)->mapCoordinates(mw, a_x, b_x, a_y, b_y);
  }
}

std::string node::getSubName()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Name*> (*it))
    {
      return dynamic_cast<Name*> (*it)->getText();
    }
  }
  return "";
}

node* node::findFromTreeView(std::string s)
{
  if (s == "")
  {
    return this;
  }
  else
  {
    std::list<node*>::iterator it = children.begin();
    int n = atoi(s.substr(0, s.find(":")-1).c_str());
    for (int i=0; i<n; i++, it++);
    return (*it)->findFromTreeView(s.substr(s.find(":")+1));
  }
}