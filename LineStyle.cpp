/* 
 * File:   LineStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:55
 */

#include "LineStyle.h"

using namespace std;

#include <string>

#include "node.h"
#include "Color.h"
#include "Width.h"

LineStyle::LineStyle()
{
  init();
}

LineStyle::LineStyle(std::string *s) : node(s)
{
  init();
}

LineStyle::LineStyle(const LineStyle& orig)
{
}

LineStyle::~LineStyle()
{
}

void LineStyle::init()
{
  name = "LineStyle";
  width_ok = false;
}


double LineStyle::getWidth()
{
  if (width_ok)
  {
    return width;
  }

  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Width*>(*it))
    {
      width_ok = true;
      width = dynamic_cast<Width*>(*it)->getWidth();
      return width;
    }
  }

  width_ok = true;
  width = 0;
  return width;
}

void LineStyle::paintEditWindow(GtkWidget* box)
{
  paintColor(box);
  paintWidth(box);
}

void LineStyle::saveFromEditWindow(GtkWidget* box)
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
  
  /* width*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 1));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setWidth(text);
}

void LineStyle::noWidthOk()
{
  width_ok = false;
}