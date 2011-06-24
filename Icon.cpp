/* 
 * File:   Icon.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:08
 */

#include "Icon.h"

using namespace std;

#include <string>

#include "node.h"
#include "Href.h"
#include "textnode.h"

Icon::Icon()
{
  init();
}

Icon::Icon(std::string *s) : node(s)
{
  init();
}

Icon::Icon(std::string s)
{
  AddChild(new Href(s));
  init();
}

Icon::Icon(const Icon& orig)
{
}

Icon::~Icon()
{
}

void Icon::init()
{
  name = "Icon";
}

std::string Icon::getImage()
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Href*>(*it))
    {
      return dynamic_cast<Href*>(*it)->getText();
    }
  }
  return "";
}

void Icon::setImage(std::string i)
{
  std::list<node*>::const_iterator it, end;
  end = children.end();
  for (it = children.begin(); it != end; it++)
  {
    if (dynamic_cast<Href*>(*it))
    {
      dynamic_cast<Href*>(*it)->setText(i);
    }
  }
}
