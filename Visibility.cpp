/* 
 * File:   Visibility.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:04
 */

#include "Visibility.h"

#include "node.h"
#include "boolnode.h"

#include <string>
#include <cstdlib>

using namespace std;

Visibility::Visibility()
{
  init();
}

Visibility::Visibility(std::string* s) : node(s)
{
  init();
}

Visibility::Visibility(std::string s)
{
  AddChild(new boolnode(atoi(s.c_str())));
  init();
}

Visibility::Visibility(const Visibility& orig)
{
}

Visibility::~Visibility()
{
}

void Visibility::init()
{
  name = "visibility";
}

bool Visibility::getVal()
{
  return dynamic_cast<boolnode*>(children.front())->getVal();
}

void Visibility::setVal(bool b)
{
  return dynamic_cast<boolnode*>(children.front())->setVal(b);
}