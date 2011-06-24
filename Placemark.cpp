/* 
 * File:   Placemark.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 16:29
 */

#include "Placemark.h"

using namespace std;

Placemark::Placemark()
{
  init();
}

Placemark::Placemark(std::string* s) :node(s)
{
  init();
}

Placemark::Placemark(const Placemark& orig)
{
}

Placemark::~Placemark()
{
}

void Placemark::init()
{
  name = "Placemark";
  labelstyle = 0;
  polystyle = 0;
  iconstyle = 0;
  linestyle = 0;
}

void Placemark::paintEditWindow(GtkWidget* box)
{
  paintName(box);
  paintDescription(box);
  paintVisibility(box);
  paintStyleUrl(box);
}

void Placemark::saveFromEditWindow(GtkWidget* box)
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
  
  /*styleurl*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 3));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setStyleUrl(text);
}