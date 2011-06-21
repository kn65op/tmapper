/* 
 * File:   PolyStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:58
 */

#include "PolyStyle.h"

using namespace std;

#include <string>

#include "node.h"
#include "Outline.h"
#include "Fill.h"
#include "boolnode.h"

PolyStyle::PolyStyle()
{
  init();
}

PolyStyle::PolyStyle(std::string *s) : node(s)
{
  init();
}

PolyStyle::PolyStyle(const PolyStyle& orig)
{
}

PolyStyle::~PolyStyle()
{
}

void PolyStyle::init()
{
  name = "PolyStyle";
  fill_ok = false;
  outline_ok = false;
}

bool PolyStyle::getFill()
{
  if (fill_ok)
  {
    return fill;
  }

  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Fill*>(*it))
    {
      fill_ok = true;
      fill = dynamic_cast<Fill*>(*it)->getFill();
      return fill;
    }
  }

  fill_ok = true;
  fill = 1;
  return fill;
}

bool PolyStyle::getOutline()
{
  if (outline_ok)
  {
    return outline;
  }

  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Outline*>(*it))
    {
      outline_ok = true;
      outline = dynamic_cast<Outline*>(*it)->getOutline();
      return outline;
    }
  }

  outline_ok = true;
  outline = 0;
  return outline;
}