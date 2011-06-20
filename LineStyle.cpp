/* 
 * File:   LineStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:55
 */

#include "LineStyle.h"

using namespace std;

#include <string>

#include "node.h"
#include "Color.h"

LineStyle::LineStyle()
{
  init();
}

LineStyle::LineStyle(std::string *s) : node(s)
{
  init();
}

LineStyle::LineStyle(const LineStyle& orig)
{
}

LineStyle::~LineStyle()
{
}

void LineStyle::init()
{
  name = "LineStyle";
}

double* LineStyle::getColor()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Color*>(*it))
    {
      return dynamic_cast<Color*>(*it)->getColor();
    }
  }
}