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
#include "LineStyle.h"

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
  AddChild(new numbernode(s));
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

double Width::getVal()
{
  return dynamic_cast<numbernode*>(children.front())->getVal();
}

void Width::setWidth(std::string w)
{
  dynamic_cast<LineStyle*>(parent)->noWidthOk();
  return dynamic_cast<numbernode*>(children.front())->setVal(w);
}
