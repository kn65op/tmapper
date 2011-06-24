/* 
 * File:   numbernode.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:03
 */

#include "numbernode.h"

using namespace std;

#include <cstdlib>
#include <string>
#include <fstream>
#include <gtk-2.0/gtk/gtk.h>
#include <sstream>

#include "node.h"

numbernode::numbernode()
{
  init();
}

numbernode::numbernode(std::string *s)
{
  if (s->find(".") != std::string::npos) s->replace(s->find("."), 1, ",");
  val = atof(s->c_str());
  delete s;
  init();
}

numbernode::numbernode(std::string s)
{
  if (s.find(".") != std::string::npos) s.replace(s.find("."), 1, ",");
  val = atof(s.c_str());
  init();
}

numbernode::numbernode(const numbernode& orig)
{
}

numbernode::~numbernode()
{
}

void numbernode::init()
{
  name = "numbernode";
}

void numbernode::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  of << val;
  of.close();
}

void numbernode::makeTree(GtkTreeStore* treestore, GtkTreeIter* parent)
{
  std::stringstream ss;
  ss << val;
  GtkTreeIter *next = new GtkTreeIter();
  gtk_tree_store_append(treestore, next, parent);
  gtk_tree_store_set(treestore, next, 0, ss.str().c_str(), -1);
  delete next;
}

void numbernode::setVal(std::string val)
{
  if (val.find(".") != std::string::npos) val.replace(val.find("."), 1, ",");
  this->val = atof(val.c_str());
  std::cout << this->val << "\n";
}