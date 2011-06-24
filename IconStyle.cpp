/* 
 * File:   IconStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:49
 */

#include "IconStyle.h"

using namespace std;

#include <string>

#include "node.h"
#include "Icon.h"
#include "Hotspot.h"

IconStyle::IconStyle()
{
  init();
}

IconStyle::IconStyle(std::string *s) : node(s)
{
  init();
}

IconStyle::IconStyle(const IconStyle& orig)
{
}

IconStyle::~IconStyle()
{
}

void IconStyle::init()
{
  name = "IconStyle";
}

std::string IconStyle::getImage()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Icon*> (*it))
    {
      return dynamic_cast<Icon*> (*it)->getImage();
    }
  }
}

double IconStyle::getX()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      return dynamic_cast<Hotspot*> (*it)->getX();
    }
  }
  return 0;
}

double IconStyle::getY()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      return dynamic_cast<Hotspot*> (*it)->getY();
    }
  }
  return 0;
}

std::string IconStyle::getXunits()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      return dynamic_cast<Hotspot*> (*it)->getXunits();
    }
  }
  return "";
}

std::string IconStyle::getYunits()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      return dynamic_cast<Hotspot*> (*it)->getYunits();
    }
  }
  return "";
}

void IconStyle::paintEditWindow(GtkWidget* box)
{
  paintColor(box);
  paintIcon(box);
  paintHotspot(box);
}

void IconStyle::saveFromEditWindow(GtkWidget* box)
{
  GList * list;
  GtkWidget *hbox;
  GtkWidget *entry;
  std::string text;

  /*color*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 0));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setColor(text);
  
  /* name*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 1));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setIcon(text);

  /* hotspot */
  std::string x, y, xunits, yunits;
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 2));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  x = gtk_entry_get_text(GTK_ENTRY(entry));
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 3));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  y = gtk_entry_get_text(GTK_ENTRY(entry));
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 4));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  xunits = gtk_entry_get_text(GTK_ENTRY(entry));
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 5));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  yunits = gtk_entry_get_text(GTK_ENTRY(entry));
  setHotspot(x, y, xunits, yunits);
  
}
