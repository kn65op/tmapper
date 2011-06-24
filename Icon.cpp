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
  AddChild(new textnode(s));
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

std::string Icon::getText()
{
  return dynamic_cast<textnode*>(children.front())->getText();
}

void Icon::setText(std::string t)
{
  return dynamic_cast<textnode*>(children.front())->setText(t);
}