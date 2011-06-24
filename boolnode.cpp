/* 
 * File:   boolnode.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:07
 */

#include "boolnode.h"

#include "node.h"

#include <cstdlib>
#include <string>
#include <fstream>
#include <gtk-2.0/gtk/gtk.h>
#include <sstream>

using namespace std;

boolnode::boolnode()
{
  init();
}

boolnode::boolnode(std::string * b)
{
  val = (bool)atoi(b->c_str());
  delete b;
  init();
}

boolnode::boolnode(bool b)
{
  val = b;
  init();
}

boolnode::boolnode(const boolnode& orig)
{
}

boolnode::~boolnode()
{
}

void boolnode::init()
{
  name = "Bool";
}

void boolnode::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  of << val;
  of.close();
}

void boolnode::makeTree(GtkTreeStore* treestore, GtkTreeIter* parent)
{
  std::stringstream ss;
  ss << val;
  GtkTreeIter *next = new GtkTreeIter();
  gtk_tree_store_append(treestore, next, parent);
  gtk_tree_store_set(treestore, next, 0, ss.str().c_str(), -1);
  delete next;
}