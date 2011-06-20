/* 
 * File:   LinearRing.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 00:21
 */

#include "LinearRing.h"

#include "node.h"
#include "Coordinates.h"

#include <cairo/cairo.h>

using namespace std;

LinearRing::LinearRing()
{
  init();
}

LinearRing::LinearRing(std::string* s) : node(s)
{
  init();
}

LinearRing::LinearRing(const LinearRing& orig)
{
}

LinearRing::~LinearRing()
{
}

void LinearRing::init()
{
  name = "LinearRing";
}

void LinearRing::draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color)
{
  double *cor;
  int n = (dynamic_cast<Coordinates*> (children.front()))->getSize();
  if (!color) //domyślny czarny
  {
    cairo_set_source_rgb(cr, 0, 0, 0);
  }
  else
  {
    cairo_set_source_rgba(cr, color[0], color[1], color[2], color[3]);
  }
  cairo_set_line_width(cr, 1.0);
  cor = (dynamic_cast<Coordinates*> (children.front()))->getCoordinates(0);
  cairo_move_to(cr, a_x * (cor[0] - b_x), a_y * (cor[1] - b_y));
  for (int i = 1; i < n; i++)
  {
    cor = (dynamic_cast<Coordinates*> (children.front()))->getCoordinates(i);
    cairo_line_to(cr, a_x * (cor[0] - b_x), a_y * (cor[1] - b_y));
  }
  cairo_close_path(cr);
  cairo_fill(cr);
  cairo_stroke(cr);
}

