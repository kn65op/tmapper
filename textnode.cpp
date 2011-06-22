/* 
 * File:   textnode.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:31
 */

#include "textnode.h"

#include <string>
#include <fstream>
#include <gtk-2.0/gtk/gtk.h>

using namespace std;

textnode::textnode()
{
  init();
}

textnode::textnode(std::string* t)
{
  init();
  Text = *t;
  delete t;
}

textnode::textnode(const textnode& orig)
{
  init();
}

textnode::~textnode()
{
}

void textnode::init()
{
  name = "Text";
}

void textnode::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  of << Text;
  of.close();
}

void textnode::makeTree(GtkTreeStore* treestore, GtkTreeIter* parent)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  GtkTreeIter *next = new GtkTreeIter();
  gtk_tree_store_append(treestore, next, parent);
  gtk_tree_store_set(treestore, next, 0, Text.c_str(), -1);
  delete next;
}