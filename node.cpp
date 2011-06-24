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
#include <gtk-2.0/gtk/gtkhbox.h>
#include <gtk-2.0/gtk/gtklabel.h>
#include <gtk-2.0/gtk/gtkbox.h>
#include <gtk-2.0/gtk/gtkentry.h>
#include <sstream>

#include "node.h"
#include "textnode.h"
#include "KML.h"
#include "Color.h"
#include "Name.h"
#include "MainWindow.h"
#include "Description.h"
#include "Visibility.h"
#include "StyleURL.h"
#include "Icon.h"
#include "Color.h"
#include "Hotspot.h"
#include "Outline.h"
#include "Fill.h"
#include "Width.h"

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
  if (s.find(":") == std::string::npos)
  {
    std::list<node*>::iterator it = children.begin();
    if (dynamic_cast<Name*> (*it))
    {
      it++;
    }
    int n = atoi(s.c_str());
    for (int i = 0; i < n; it++)
    {
      if (!dynamic_cast<Name*> (*it))
      {
        i++;
      }
    }
    if (dynamic_cast<Name*> ((*it)))
    {
      it++;
    }
    return *it;
  }
  else
  {
    std::list<node*>::iterator it = children.begin();
    if (dynamic_cast<Name*> (*it))
    {
      it++;
    }
    int n = atoi(s.substr(0, s.find(":")).c_str());
    for (int i = 0; i < n; it++)
    {
      if (!dynamic_cast<Name*> (*it))
      {
        i++;
      }
    }
    node *val = (*it)->findFromTreeView(s.substr(s.find(":") + 1));
    if (!val)
    {
      it++;
      val = (*it)->findFromTreeView(s.substr(s.find(":") + 1));
    }
    return val;
  }
}

void node::paintEditWindow(GtkWidget* box)
{

}

void node::saveFromEditWindow(GtkWidget* box)
{

}

void node::paintName(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Name *name = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Name*> (*it))
    {
      name = dynamic_cast<Name*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Name: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (name)
  {
    gtk_entry_set_text(GTK_ENTRY(entry), name->getText().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  return;
}

void node::paintDescription(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Description *desc = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Description*> (*it))
    {
      desc = dynamic_cast<Description*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Description: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (desc)
  {
    gtk_entry_set_text(GTK_ENTRY(entry), desc->getText().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  return;
}


void node::paintVisibility(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Visibility *visibility = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Visibility*> (*it))
    {
      visibility = dynamic_cast<Visibility*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Visibility: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (visibility)
  {
    std::stringstream b;
    b << visibility->getVal();
    gtk_entry_set_text(GTK_ENTRY(entry), b.str().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  return;
}

void node::paintStyleUrl(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  StyleURL *styleURL = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<StyleURL*> (*it))
    {
      styleURL = dynamic_cast<StyleURL*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("StyleURL: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (styleURL)
  {
    gtk_entry_set_text(GTK_ENTRY(entry), styleURL->getText().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  return;
}

void node::setSubName(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<Name*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Name*> (*it))
    {
      dynamic_cast<Name*> (*it)->setText(n);
      return;
    }
  }
  AddChild(new Name(n));
}

void node::setDescription(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<Description*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Description*> (*it))
    {
      dynamic_cast<Description*> (*it)->setText(n);
      return;
    }
  }
  AddChild(new Description(n));
}

void node::setVisibility(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<Visibility*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Visibility*> (*it))
    {
      bool b = atoi(n.c_str());
      dynamic_cast<Visibility*> (*it)->setVal(b);
      return;
    }
  }
  AddChild(new Visibility(n));
}

void node::setStyleUrl(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<StyleURL*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<StyleURL*> (*it))
    {
      dynamic_cast<StyleURL*> (*it)->setText(n);
      return;
    }
  }
  AddChild(new StyleURL(n));
}

void node::paintId(GtkWidget* box)
{
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Id: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  gtk_entry_set_text(GTK_ENTRY(entry), id.c_str());
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
}

void node::paintColor(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Color *color = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Color*> (*it))
    {
      color = dynamic_cast<Color*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Color: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (color)
  {
    gtk_entry_set_text(GTK_ENTRY(entry), color->getText().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  return;
}

void node::paintIcon(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Icon *icon = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Icon*> (*it))
    {
      icon = dynamic_cast<Icon*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Icon: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (icon)
  {
    gtk_entry_set_text(GTK_ENTRY(entry), icon->getImage().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  std::cout << "Ai\n";
  return;
}

void node::setColor(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<Color*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Color*> (*it))
    {
      dynamic_cast<Color*> (*it)->setText(n);
      return;
    }
  }
  AddChild(new Color(n));
}

void node::setIcon(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<Icon*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Icon*> (*it))
    {
      dynamic_cast<Icon*> (*it)->setImage(n);
      return;
    }
  }
  AddChild(new Icon(n));
}

void node::paintHotspot(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Hotspot *hotspot = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      hotspot = dynamic_cast<Hotspot*> (*it);
    }
  }
  GtkWidget *hbox, *label, *entry;
  //x
  hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  label = gtk_label_new("Hotspot x: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  entry = gtk_entry_new();
  if (hotspot)
  {
    std::stringstream x;
    x << hotspot->getX();
    gtk_entry_set_text(GTK_ENTRY(entry), x.str().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  //y
  hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  label = gtk_label_new("Hotspot y: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  entry = gtk_entry_new();
  if (hotspot)
  {
    std::stringstream x;
    x << hotspot->getY();
    gtk_entry_set_text(GTK_ENTRY(entry), x.str().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);

  //xunits
  hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  label = gtk_label_new("Hotspot xunits: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  entry = gtk_entry_new();
  if (hotspot)
  {
    gtk_entry_set_text(GTK_ENTRY(entry), hotspot->getXunits().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);

  //yunits
  hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  label = gtk_label_new("Hotspot xunits: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  entry = gtk_entry_new();
  if (hotspot)
  {
    gtk_entry_set_text(GTK_ENTRY(entry), hotspot->getYunits().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);

  std::cout << "Ai\n";
  return;
}

void node::setHotspot(std::string x, std::string y, std::string xunits, std::string yunits)
{
  std::list<node*>::iterator it, end;
  end = children.end();

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      dynamic_cast<Hotspot*> (*it)->setAll(x, y, xunits, yunits);
      return;
    }
  }
  AddChild(new Hotspot(x, y, xunits, yunits));
}

void node::setFill(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<Fill*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Fill*> (*it))
    {
      bool b = atoi(n.c_str());
      dynamic_cast<Fill*> (*it)->setVal(b);
      return;
    }
  }
  AddChild(new Fill(n));
}

void node::setOutline(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<Outline*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Outline*> (*it))
    {
      bool b = atoi(n.c_str());
      dynamic_cast<Outline*> (*it)->setVal(b);
      return;
    }
  }
  AddChild(new Outline(n));
}

void node::paintOutline(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Outline *outline = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Outline*> (*it))
    {
      outline = dynamic_cast<Outline*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Outline: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (outline)
  {
    std::stringstream b;
    b << outline->getVal();
    gtk_entry_set_text(GTK_ENTRY(entry), b.str().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  return;
}

void node::paintFill(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Fill *fill = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Fill*> (*it))
    {
      fill = dynamic_cast<Fill*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Fill: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (fill)
  {
    std::stringstream b;
    b << fill->getVal();
    gtk_entry_set_text(GTK_ENTRY(entry), b.str().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  return;
}

void node::paintWidth(GtkWidget* box)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  Width *width = 0;

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Width*> (*it))
    {
      width = dynamic_cast<Width*> (*it);
    }
  }
  GtkWidget *hbox = gtk_hbox_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_box_pack_start(GTK_BOX(box), hbox, 1, 1, 2);
  GtkWidget *label = gtk_label_new("Width: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, 1, 1, 2);
  GtkWidget *entry = gtk_entry_new();
  if (width)
  {
    std::stringstream b;
    b << width->getWidth();
    gtk_entry_set_text(GTK_ENTRY(entry), b.str().c_str());
  }
  else
  {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
  }
  gtk_box_pack_end(GTK_BOX(hbox), entry, 1, 1, 2);
  return;
}

void node::setWidth(std::string n)
{
  std::list<node*>::iterator it, end;
  end = children.end();
  if (n == "")
  {
    for (it = children.begin(); it != end; it++)
    {
      if (dynamic_cast<Width*> (*it))
      {
        delete (*it);
        children.erase(it);
        return;
      }
    }
    return;
  }

  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Width*> (*it))
    {
      dynamic_cast<Width*> (*it)->setWidth(n);
      return;
    }
  }
  AddChild(new Width(n));
}