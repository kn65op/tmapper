/* 
 * File:   Document.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 16:10
 */

#include "Document.h"

#include <string>
#include <gtk-2.0/gtk/gtkcontainer.h>
#include <glib-2.0/glib/glist.h>
#include <gtk-2.0/gtk/gtkentry.h>

using namespace std;

Document::Document()
{
  init();
}

Document::Document(std::string* s) :node(s)
{
  init();
}

Document::Document(const Document& orig)
{
}

Document::~Document()
{
}

void Document::init()
{
  name = "Document";
}

/*void Document::saveToFile(std::string file, int level)
{
  
}//*/

void Document::paintEditWindow(GtkWidget* box)
{
  paintName(box);
  paintDescription(box);
  paintVisibility(box);
}

void Document::saveFromEditWindow(GtkWidget* box)
{
  GList * list;
  GtkWidget *hbox;
  GtkWidget *entry;
  std::string text;
    
  /* name*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 0));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setSubName(text);
  
  /*description*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 1));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setDescription(text);
  
  /*visibility*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 2));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setVisibility(text);
}