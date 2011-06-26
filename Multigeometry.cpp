/* 
 * File:   Multigeometry.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 03:03
 */

#include "Multigeometry.h"

#include <string>

#include "node.h"

using namespace std;

Multigeometry::Multigeometry()
{
  init();
}

Multigeometry::Multigeometry(std::string* s) : node(s)
{
  init();
}

Multigeometry::Multigeometry(const Multigeometry& orig)
{
}

Multigeometry::~Multigeometry()
{
}

void Multigeometry::init()
{
  name = "MultiGeometry";
}

std::list<std::string>* Multigeometry::getPosibilities()
{
  std::list<std::string> *tmp = new std::list<std::string>();
  tmp->push_back("LinearRing");
  tmp->push_back("LineString");
  tmp->push_back("Multigeometry");
  tmp->push_back("Point");
  tmp->push_back("Polygon");
  return tmp;
}