/* 
 * File:   Point.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:30
 */

#include "Point.h"

#include <string>
#include <cairo/cairo.h>
#include <vector>

#include "Coordinates.h"

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

void Point::draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y)
{
  double *cor = (dynamic_cast<Coordinates*>(children.front()))->getCoordinates(0);
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width(cr, 10000.0);
  cairo_move_to(cr, a_x*(cor[0]-b_x), a_y*(cor[1]-b_y));
  cairo_line_to(cr, a_x*(cor[0]-b_x)+0.1, a_y*(cor[1]-b_y)+0.1);
  cairo_stroke(cr);
}