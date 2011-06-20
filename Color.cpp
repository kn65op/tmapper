/* 
 * File:   Color.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:00
 */

#include "Color.h"

using namespace std;

#include <string>

#include "node.h"

Color::Color()
{
  init();
}

Color::Color(std::string *s) : node(s)
{
  init();
}

Color::Color(const Color& orig)
{
}

Color::~Color()
{
}

void Color::init()
{
  name = "color";
}
