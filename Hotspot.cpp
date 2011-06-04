/* 
 * File:   Hotspot.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:20
 */

#include "Hotspot.h"

using namespace std;

#include <string>

#include "node.h"

Hotspot::Hotspot()
{
  init();
}

Hotspot::Hotspot(std::string *s) : node(s)
{
  init();
}

Hotspot::Hotspot(const Hotspot& orig)
{
}

Hotspot::~Hotspot()
{
}

void Hotspot::init()
{
  name = "Hotspot";
}
