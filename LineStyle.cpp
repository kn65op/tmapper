/* 
 * File:   LineStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:55
 */

#include "LineStyle.h"

using namespace std;

#include <string>

#include "node.h"

LineStyle::LineStyle()
{
  init();
}

LineStyle::LineStyle(std::string *s) : node(s)
{
  init();
}

LineStyle::LineStyle(const LineStyle& orig)
{
}

LineStyle::~LineStyle()
{
}

void LineStyle::init()
{
  name = "LineStyle";
}