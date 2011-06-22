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
#include <cmath>

#include "Coordinates.h"
#include "IconStyle.h"
#include "Placemark.h"

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

void Point::draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color)
{
  node *tmp = parent;
  while (!(dynamic_cast<Placemark*> (tmp)))
  {
    tmp = tmp->GetParent();
  }

  IconStyle *is = dynamic_cast<Placemark*> (tmp)->getIconstyle();

  double *cor = (dynamic_cast<Coordinates*> (children.front()))->getCoordinates(0);
  ///TODO: dodanie obrazka - ikony
  if (is) //jest ikona do pokazania
  {
    //TODO usunąć scale
    //TODO dorobić hotspot
    cairo_surface_t *image;
    gint width, height;
    image = cairo_image_surface_create_from_png(is->getImage().c_str());
    width = cairo_image_surface_get_width(image);
    height = cairo_image_surface_get_height(image);
    cairo_set_source_surface(cr, image, a_x * (cor[0] - b_x) - (int) (width / 2), a_y * (cor[1] - b_y) - (int) (height / 2));
    cairo_paint(cr);
    cairo_surface_destroy(image);
  }
  else //nie ma ikony do pokazania
  {
    if (!color) //jak nie ma koloru to domyślny czarny
    {
      cairo_set_source_rgb(cr, 0, 0, 0);
    }
    else
    {
      cairo_set_source_rgba(cr, color[0], color[1], color[2], color[3]);
    }
    cairo_set_line_width(cr, 1.0);
    cairo_arc(cr, a_x * (cor[0] - b_x), a_y * (cor[1] - b_y), 2.0, 0, 2 * M_PI);
    cairo_fill(cr);
  }
  /*cairo_move_to(cr, a_x*(cor[0]-b_x), a_y*(cor[1]-b_y));
  cairo_line_to(cr, a_x*(cor[0]-b_x)+1, a_y*(cor[1]-b_y)+1);//*/
  cairo_stroke(cr);
}