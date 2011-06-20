/* 
 * File:   LineString.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 22:36
 */

#ifndef LINESTRING_H
#define	LINESTRING_H

#include <string>

#include "node.h"

class LineString : public node
{
public:
  LineString();
  LineString(std::string* s);
  LineString(const LineString& orig);
  virtual ~LineString();

  void draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color);
private:
  void init();

};

#endif	/* LINESTRING_H */

