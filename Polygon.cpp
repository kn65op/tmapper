/* 
 * File:   Polygon.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 00:30
 */

#include "Polygon.h"

#include "node.h"
#include "InnerBoundaryIs.h"
#include "OuterBoundaryIs.h"

#include <string>
#include <list>

using namespace std;

Polygon::Polygon()
{
  init();
  AddChild(new OuterBoundaryIs());
}

Polygon::Polygon(std::string* s) : node(s)
{
  init();
}

Polygon::Polygon(const Polygon& orig)
{
}

Polygon::~Polygon()
{
}

void Polygon::init()
{
  name = "Polygon";
}

void Polygon::draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color)
{
  OuterBoundaryIs *otmp;
  std::list<node*>::iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<OuterBoundaryIs*>(*it))
    {
      otmp = dynamic_cast<OuterBoundaryIs*>(*it);
      (*it)->draw(cr, a_x, b_x, a_y, b_y, color);
    }
  }
  double *c2 = new double[4];
  c2[0] = 1.0;
  c2[1] = 1.0;
  c2[2] = 1.0;
  c2[3] = 1.0;
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<InnerBoundaryIs*>(*it))
    {
      (*it)->draw(cr, a_x, b_x, a_y, b_y, c2);
    }
  }
  delete [] c2;
  children.remove(otmp);
  children.insert(children.end(), otmp);
}

std::list<std::string>* Polygon::getPosibilities()
{
  std::list<std::string> *tmp = new std::list<std::string>();
  tmp->push_back("InnerBoundaryIs");
  tmp->push_back("OuterBoundaryIs");
  return tmp;
}

bool Polygon::ifRemoveOlny()
{
  return true;
}