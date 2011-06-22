/* 
 * File:   Coordinates.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 19:32
 */

#include "Coordinates.h"

using namespace std;

#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <gtk-2.0/gtk/gtk.h>
#include <sstream>

#include "node.h"

Coordinates::Coordinates()
{
  init();
}

Coordinates::Coordinates(std::string* s) : node(s)
{
  init();
}

Coordinates::Coordinates(const Coordinates& orig)
{
}

Coordinates::~Coordinates()
{
  for (int i=0; i<coordinates.size(); i++)
  {
    delete [] coordinates[i];
  }
}

void Coordinates::addCoordinate(std::string* x, std::string* y, std::string* z)
{
  double *tmp = new double[3];
  if (x->find(".") != std::string::npos) x->replace(x->find("."), 1, ",");
  if (y->find(".") != std::string::npos) y->replace(y->find("."), 1, ",");
  if (z->find(".") != std::string::npos) z->replace(z->find("."), 1, ",");
  tmp[0] = atof(x->c_str());
  tmp[1] = atof(y->c_str());
  tmp[2] = atof(z->c_str());
  coordinates.push_back(tmp);
  delete x;
  delete y;
  delete z;
}

void Coordinates::init()
{
  name = "coordinates";
}

void Coordinates::saveToFile(std::string file, int level)
{

  std::ofstream of(file.c_str(), std::ios::app);

  saveOpeningTag(of);

  vector<double*>::iterator it, end;
  end = coordinates.end();
  for (it = coordinates.begin(); it != end; it++)
  {
    std::cout << "?\n";
    of << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << "\n";
  }

  saveClosingTag(of);

  of.close();
}

void Coordinates::findHW(double& max_x, double& min_x, double& max_y, double& min_y)
{
  vector<double*>::iterator it, end;
  end = coordinates.end();
  for (it = coordinates.begin(); it != end; it++)
  {
    if ((*it)[0] > max_x)
    {
      max_x = (*it)[0];
    }
    else if ((*it)[0] < min_x)
    {
      min_x = (*it)[0];
    }
    if ((*it)[1] > max_y)
    {
      max_y = (*it)[1];
    }
    else if ((*it)[1] < min_y)
    {
      min_y = (*it)[1];
    }
  }
}

int Coordinates::getSize() const
{
  return coordinates.size();
}

void Coordinates::makeTree(GtkTreeStore* treestore, GtkTreeIter* parent)
{
  vector<double*>::iterator it, end;
  end = coordinates.end();
  GtkTreeIter *next = new GtkTreeIter();
  GtkTreeIter *t = new GtkTreeIter();
  gtk_tree_store_append(treestore, t, parent);
  gtk_tree_store_set(treestore, t, 0, name.c_str(), -1);
  for (it = coordinates.begin(); it != end; it++)
  {
    std::stringstream ss;
    ss << (*it)[0] << "," << (*it)[1] << "," << (*it)[2];
    gtk_tree_store_append(treestore, next, t);
    gtk_tree_store_set(treestore, next, 0, ss.str().c_str(), -1);
  }
  delete next;
  delete t;
}