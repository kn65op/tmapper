/* 
 * File:   Heading.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:06
 */

#include "Heading.h"

using namespace std;

#include <string>

#include "node.h"

Heading::Heading()
{
  init();
}

Heading::Heading(std::string *s) : node(s)
{
  init();
}

Heading::Heading(const Heading& orig)
{
}

Heading::~Heading()
{
}

void Heading::init()
{
  name = "Heading";
}
