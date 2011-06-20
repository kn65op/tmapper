/* 
 * File:   Point.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 22:30
 */

#ifndef POINT_H
#define	POINT_H

#include <string>

#include "node.h"

class Point : public node
{
public:
  Point();
  Point(std::string *s);
  Point(const Point& orig);
  virtual ~Point();

  void draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y);

private:
  void init();
};

#endif	/* POINT_H */

