/* 
 * File:   Polygon.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 00:30
 */

#include "Polygon.h"

#include "node.h"

#include <string>

using namespace std;

Polygon::Polygon()
{
  init();
}

Polygon::Polygon(std::string* s) : node(s)
{
  init();
}

Polygon::Polygon(const Polygon& orig)
{
}

Polygon::~Polygon()
{
}

void Polygon::init()
{
  name = "Polygon";
}