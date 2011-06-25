/* 
 * File:   Style.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:15
 */

#include "Style.h"

#include <string>

#include "node.h"
#include "KML.h"

using namespace std;

Style::Style()
{
  init();
}

Style::Style(std::string* s) : node(s)
{
  init();
}

Style::Style(const Style& orig)
{
}

Style::~Style()
{
}

void Style::init()
{
  name = "Style";
  labelstyle = 0;
  polystyle = 0;
  iconstyle = 0;
  linestyle = 0;
}

void Style::searchStyle(KML* kml)
{
  labelstyle = 0;
  polystyle = 0;
  iconstyle = 0;
  linestyle = 0;
  kml->addStyle(id, this);
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<IconStyle*> (*it))
    {
      iconstyle = dynamic_cast<IconStyle*> (*it);
    }
    else if (dynamic_cast<LabelStyle*> (*it))
    {
      labelstyle = dynamic_cast<LabelStyle*> (*it);
    }
    else if (dynamic_cast<PolyStyle*> (*it))
    {
      polystyle = dynamic_cast<PolyStyle*> (*it);
    }
    else if (dynamic_cast<LineStyle*> (*it))
    {
      linestyle = dynamic_cast<LineStyle*> (*it);
    }
  }
}

void Style::paintEditWindow(GtkWidget* box)
{
  paintId(box);
}

void Style::saveFromEditWindow(GtkWidget* box)
{
  GList * list;
  GtkWidget *hbox;
  GtkWidget *entry;
  std::string text;

  /*id*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 0));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  SetId(text);
}

std::list<std::string>* Style::getPosibilities()
{
  std::list<std::string> *tmp = new std::list<std::string>();
  tmp->push_back("IconStyle");
  tmp->push_back("LineStyle");
  tmp->push_back("PolyStyle");
  return tmp;
}