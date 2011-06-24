/* 
 * File:   Outline.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:33
 */

#include "Outline.h"

using namespace std;

#include <string>

#include "node.h"
#include "boolnode.h"
#include "textnode.h"

Outline::Outline()
{
  init();
}

Outline::Outline(std::string *s) : node(s)
{
  init();
}

Outline::Outline(std::string s)
{
  AddChild(new textnode(s));
  init();
}

Outline::Outline(const Outline& orig)
{
}

Outline::~Outline()
{
}

void Outline::init()
{
  name = "outline";
}

bool Outline::getOutline()
{
  return dynamic_cast<boolnode*>(children.front())->getVal();
}

std::string Outline::getText()
{
  return dynamic_cast<textnode*>(children.front())->getText();
}

void Outline::setText(std::string t)
{
  return dynamic_cast<textnode*>(children.front())->setText(t);
}