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