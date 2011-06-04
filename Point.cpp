/* 
 * File:   Point.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:30
 */

#include "Point.h"

#include <string>

using namespace std;

Point::Point()
{
  init();
}

Point::Point(std::string* s) : node(s)
{
  init();
}

Point::Point(const Point& orig)
{
}

Point::~Point()
{
}

void Point::init()
{
  name = "Point";
}