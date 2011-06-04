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
private:
  void init();
};

#endif	/* POINT_H */

