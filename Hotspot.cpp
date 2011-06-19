/* 
 * File:   Hotspot.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:20
 */

#include "Hotspot.h"

using namespace std;

#include <string>
#include <fstream>

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
  name = "hotSpot";
}

void Hotspot::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  of << "<" << name << " x=\"" << x << "\" y=\"" << y << "\" xunits=" << xunits << " yunits=" << yunits << "/>";
  of.close();
}
