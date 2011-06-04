/* 
 * File:   Multigeometry.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 03:03
 */

#include "Multigeometry.h"

#include <string>

#include "node.h"

using namespace std;

Multigeometry::Multigeometry()
{
  init();
}

Multigeometry::Multigeometry(std::string* s) : node(s)
{
  init();
}

Multigeometry::Multigeometry(const Multigeometry& orig)
{
}

Multigeometry::~Multigeometry()
{
}

void Multigeometry::init()
{
  name = "Multigeometry";
}