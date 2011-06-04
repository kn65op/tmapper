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

Icon::Icon()
{
  init();
}

Icon::Icon(std::string *s) : node(s)
{
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
