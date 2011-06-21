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
#include "Width.h"

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


double LineStyle::getWidth() const
{
  if (width_ok)
  {
    return width;
  }

  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Width*>(*it))
    {
      width_ok = true
      width = dynamic_cast<Width*>(*it)->getWidth();
      return width;
    }
  }

  width_ok = true;
  width = 0;
  return width;
}