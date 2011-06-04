/* 
 * File:   LineString.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:36
 */

#include "LineString.h"

#include <string>

using namespace std;

LineString::LineString()
{
  init();
}

LineString::LineString(std::string* s) : node(s)
{
  init();
}

LineString::LineString(const LineString& orig)
{
}

LineString::~LineString()
{
}

void LineString::init()
{
  name = "LineString";
}