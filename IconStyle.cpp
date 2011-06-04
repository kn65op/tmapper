/* 
 * File:   IconStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:49
 */

#include "IconStyle.h"

using namespace std;

#include <string>

#include "node.h"

IconStyle::IconStyle()
{
  init();
}

IconStyle::IconStyle(std::string *s) : node(s)
{
  init();
}

IconStyle::IconStyle(const IconStyle& orig)
{
}

IconStyle::~IconStyle()
{
}

void IconStyle::init()
{
  name = "IconStyle";
}
