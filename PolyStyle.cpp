/* 
 * File:   PolyStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:58
 */

#include "PolyStyle.h"

using namespace std;

#include <string>

#include "node.h"
#include "Outline.h"
#include "Fill.h"
#include "boolnode.h"

PolyStyle::PolyStyle()
{
  init();
}

PolyStyle::PolyStyle(std::string *s) : node(s)
{
  init();
}

PolyStyle::PolyStyle(const PolyStyle& orig)
{
}

PolyStyle::~PolyStyle()
{
}

void PolyStyle::init()
{
  name = "PolyStyle";
  fill_ok = false;
  outline_ok = false;
}

bool PolyStyle::getFill()
{
  if (fill_ok)
  {
    return fill;
  }

  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Fill*>(*it))
    {
      fill_ok = true;
      fill = dynamic_cast<Fill*>(*it)->getFill();
      return fill;
    }
  }

  fill_ok = true;
  fill = 1;
  return fill;
}

bool PolyStyle::getOutline()
{
  if (outline_ok)
  {
    return outline;
  }

  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Outline*>(*it))
    {
      outline_ok = true;
      outline = dynamic_cast<Outline*>(*it)->getOutline();
      return outline;
    }
  }

  outline_ok = true;
  outline = 0;
  return outline;
}

void PolyStyle::paintEditWindow(GtkWidget* box)
{
  paintColor(box);
  paintFill(box);
  paintOutline(box);
}

void PolyStyle::saveFromEditWindow(GtkWidget* box)
{
  GList * list;
  GtkWidget *hbox;
  GtkWidget *entry;
  std::string text;

  /*coloe*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 0));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setColor(text);
  
  /* fill*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 1));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setFill(text);

  /*outline*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 2));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setOutline(text);

}
void PolyStyle::noFillOk()
{
  fill_ok = false;
}

void PolyStyle::noOutlineOk()
{
  outline_ok = false;
}