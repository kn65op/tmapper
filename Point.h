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

  void draw(cairo_t *cr, int max_x, int min_x, int max_y, int min_y);

private:
  void init();
};

#endif	/* POINT_H */

