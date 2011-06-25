/* 
 * File:   Description.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:20
 */

#include "Description.h"

#include <string>

#include "textnode.h"

using namespace std;

Description::Description()
{
  init();
}

Description::Description(std::string* s) : node(s)
{
  init();
}

Description::Description(std::string s)
{
  AddChild(new textnode(s));
  init();
}

Description::Description(const Description& orig)
{
}

Description::~Description()
{
}

void Description::init()
{
  name = "description";
}

std::string Description::getText()
{
  return dynamic_cast<textnode*>(children.front())->getText();
}

void Description::setText(std::string t)
{
  return dynamic_cast<textnode*>(children.front())->setText(t);
}

bool Description::ifShow()
{
  return false;
}