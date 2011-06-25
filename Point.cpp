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
#include "MainWindow.h"

using namespace std;

Point::Point()
{
  init();
  Coordinates* tmp = new Coordinates();
  tmp->addCoordinate(0.0, 0.0, 0.0);
  AddChild(tmp);
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
  bool no_ic =true;

  if (is) //jest ikona do pokazania
  {
    cairo_surface_t *image;
    gint width, height;
    image = cairo_image_surface_create_from_png(is->getImage().c_str());
    if (cairo_surface_status(image) != CAIRO_STATUS_FILE_NOT_FOUND)
    {
      no_ic = false;
      width = cairo_image_surface_get_width(image);
      height = cairo_image_surface_get_height(image);
      double x, y;
      x = a_x * (cor[0] - b_x);
      y = a_y * (cor[1] - b_y);
      if (is->getXunits() == "\"fraction\"")
      {
        x -= (int) ((double) width * is->getX());
      }
      else if (is->getXunits() == "\"insetPixels\"")
      {
        x += (int) is->getX() + width;
      }
      else if (is->getXunits() == "\"pixels\"")
      {
        x += (int) is->getX();
      }
      if (is->getYunits() == "\"fraction\"")
      {
        y -= (int) ((double) height * is->getY());
      }
      else if (is->getYunits() == "\"insetPixels\"")
      {
        y += (int) is->getY() + height;
      }
      else if (is->getYunits() == "\"pixels\"")
      {
        y += (int) is->getY();
      }
      cairo_set_source_surface(cr, image, x, y);
      cairo_paint(cr);
      cairo_surface_destroy(image);
    }
    else
    {
      
      no_ic = true;
    }
  }
  if (no_ic)
  {
    if (is && is->getColor())
    {
      double *col = is->getColor();
      cairo_set_source_rgba(cr, col[0], col[1], col[2], col[3]);
    }
    else if (!color) //jak nie ma koloru to domyślny czarny
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

bool Point::ifShow()
{
  return false;
}