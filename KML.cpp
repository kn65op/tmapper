/* 
 * File:   KML.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 14:14
 */

#include "KML.h"

#include <iostream>
#include <string>
#include <fstream>
#include <gtk-2.0/gtk/gtk.h>

using namespace std;

KML::KML()
{
  init();
}

KML::KML(std::string *s) : node(s)
{
  init();
}

KML::KML(const KML& orig)
{
}

KML::~KML()
{
}

void KML::init()
{
  name = "kml";
  parent = 0;
}

/*void KML::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str());
  of << "";
  of.close();
  reinterpret_cast<node*>(this)->saveToFile(file, 0);
}*/

void KML::connectStyles()
{
  styles.clear();
  //usuwanie starych
  this->removeStyle(this);
  //wyszukiwanie styli
  this->searchStyle(this);
  //łaczenie styli z placemarkami
  this->connectStyle(this);
}

void KML::addStyle(std::string id, node* n)
{
  styles.insert(std::pair<std::string, node*>(id, n));
}

node* KML::getStyle(std::string id)
{
  return styles[id];
}

void KML::makeTree(GtkTreeStore* treestore, GtkTreeIter* parent)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();

  for (it = children.begin(); it != end; it++)
  {
    (*it)->makeTree(treestore, parent);
  }
}