/* 
 * File:   Fill.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:30
 */

#include "Fill.h"

using namespace std;

#include <string>

#include "node.h"
#include "boolnode.h"
#include "textnode.h"

Fill::Fill()
{
  init();
}

Fill::Fill(std::string *s) : node(s)
{
  init();
}

Fill::Fill(std::string s)
{
  AddChild(new textnode(s));
  init();
}

Fill::Fill(const Fill& orig)
{
}

Fill::~Fill()
{
}

void Fill::init()
{
  name = "fill";
}

bool Fill::getFill()
{
  return dynamic_cast<boolnode*>(children.front())->getVal();
}

std::string Fill::getText()
{
  return dynamic_cast<textnode*>(children.front())->getText();
}

void Fill::setText(std::string t)
{
  return dynamic_cast<textnode*>(children.front())->setText(t);
}