/* 
 * File:   Name.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:06
 */

#include "Name.h"
#include "textnode.h"

#include <string>
using namespace std;

Name::Name()
{
  init();
}

Name::Name(std::string *s) : node(s)
{
  init();
}

Name::Name(const Name& orig)
{
}

Name::~Name()
{
}

void Name::init()
{
  name = "name";
}

std::string Name::getText()
{
  return dynamic_cast<textnode*>(children.front())->getText();
}

node* Name::findFromTreeView(std::string s)
{
  return NULL;
}