/* 
 * File:   PolyStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:58
 */

#include "PolyStyle.h"

using namespace std;

#include <string>

#include "node.h"

PolyStyle::PolyStyle()
{
  init();
}

PolyStyle::PolyStyle(std::string *s) : node(s)
{
  init();
}

PolyStyle::PolyStyle(const PolyStyle& orig)
{
}

PolyStyle::~PolyStyle()
{
}

void PolyStyle::init()
{
  name = "PolyStyle";
}