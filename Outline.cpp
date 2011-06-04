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

Outline::Outline()
{
  init();
}

Outline::Outline(std::string *s) : node(s)
{
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
  name = "Outline";
}
