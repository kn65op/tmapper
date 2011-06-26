/* 
 * File:   Folder.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 16:39
 */

#include "Folder.h"

using namespace std;

Folder::Folder()
{
  init();
}

Folder::Folder(std::string* s): node(s)
{
  init();
}

Folder::Folder(const Folder& orig)
{
}

Folder::~Folder()
{
}

void Folder::init()
{
  name = "Folder";
}

void Folder::paintEditWindow(GtkWidget* box)
{
  paintId(box);
  paintName(box);
  paintDescription(box);
  paintVisibility(box);
}

void Folder::saveFromEditWindow(GtkWidget* box)
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
  
  /* name*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 1));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setSubName(text);

  /*description*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 2));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setDescription(text);

  /*visibility*/
  list = gtk_container_get_children(GTK_CONTAINER(box));
  hbox = GTK_WIDGET(g_list_nth_data(list, 3));
  list = gtk_container_get_children(GTK_CONTAINER(hbox));
  entry = GTK_WIDGET(g_list_nth_data(list, 1));
  text = gtk_entry_get_text(GTK_ENTRY(entry));
  setVisibility(text);
}

std::list<std::string>* Folder::getPosibilities()
{
  std::list<std::string> *tmp = new std::list<std::string>();
  tmp->push_back("Folder");
  tmp->push_back("Placemark");
  return tmp;
}