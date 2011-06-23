/* 
 * File:   IconStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:49
 */

#include "IconStyle.h"

using namespace std;

#include <string>

#include "node.h"
#include "Icon.h"
#include "Hotspot.h"

IconStyle::IconStyle()
{
  init();
}

IconStyle::IconStyle(std::string *s) : node(s)
{
  init();
}

IconStyle::IconStyle(const IconStyle& orig)
{
}

IconStyle::~IconStyle()
{
}

void IconStyle::init()
{
  name = "IconStyle";
}

std::string IconStyle::getImage()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Icon*> (*it))
    {
      return dynamic_cast<Icon*> (*it)->getImage();
    }
  }
}

double IconStyle::getX()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      return dynamic_cast<Hotspot*> (*it)->getX();
    }
  }
  return 0;
}

double IconStyle::getY()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      return dynamic_cast<Hotspot*> (*it)->getY();
    }
  }
  return 0;
}

std::string IconStyle::getXunits()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      return dynamic_cast<Hotspot*> (*it)->getXunits();
    }
  }
  return "";
}

std::string IconStyle::getYunits()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Hotspot*> (*it))
    {
      return dynamic_cast<Hotspot*> (*it)->getYunits();
    }
  }
  return "";
}
