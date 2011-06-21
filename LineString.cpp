/* 
 * File:   LineString.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:36
 */

#include "LineString.h"
#include "Coordinates.h"
#include "LineStyle.h"
#include "Placemark.h"

#include <string>
#include <cairo/cairo.h>

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

void LineString::draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color)
{
  //TODO: dodać badanie multigeometry
  LineStyle *ls;

  node *tmp = parent;
  while (!(dynamic_cast<Placemark*> (tmp)))
  {
    tmp = tmp->GetParent();
  }
  ls = dynamic_cast<Placemark*> (tmp)->getLinestyle();

  double *col = 0;
  if (ls)
  {
    col = ls->getColor();
  }

  double *cor;
  int n = (dynamic_cast<Coordinates*> (children.front()))->getSize();
  if (color) //domyślnie czarny
  {
    cairo_set_source_rgba(cr, color[0], color[1], color[2], color[3]);
  }
  else if (ls)
  {
    cairo_set_source_rgba(cr, col[0], col[1], col[2], col[3]);
    std::cout << "OK?\n";
  }
  else
  {
    cairo_set_source_rgb(cr, 0, 0, 0);
  }
  cairo_set_line_width(cr, 1.0);
  cor = (dynamic_cast<Coordinates*> (children.front()))->getCoordinates(0);
  cairo_move_to(cr, a_x * (cor[0] - b_x), a_y * (cor[1] - b_y));
  for (int i = 1; i < n; i++)
  {
    cor = (dynamic_cast<Coordinates*> (children.front()))->getCoordinates(i);
    cairo_line_to(cr, a_x * (cor[0] - b_x), a_y * (cor[1] - b_y));
  }
  cairo_stroke(cr);
}