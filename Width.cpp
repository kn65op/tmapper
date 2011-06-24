/* 
 * File:   Width.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:29
 */

#include "Width.h"

using namespace std;

#include <string>

#include "node.h"
#include "numbernode.h"
#include "textnode.h"

Width::Width()
{
  init();
}

Width::Width(std::string *s) : node(s)
{
  init();
}

Width::Width(std::string s)
{
  AddChild(new textnode(s));
  init();
}

Width::Width(const Width& orig)
{
}

Width::~Width()
{
}

void Width::init()
{
  name = "width";
}

double Width::getWidth()
{
  return dynamic_cast<numbernode*>(children.front())->getVal();
}

std::string Width::getText()
{
  return dynamic_cast<textnode*>(children.front())->getText();
}

void Width::setText(std::string t)
{
  return dynamic_cast<textnode*>(children.front())->setText(t);
}
