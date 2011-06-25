/* 
 * File:   Polygon.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 00:30
 */

#ifndef POLYGON_H
#define	POLYGON_H

#include "node.h"

#include <string>

class Polygon : public node
{
public:
  Polygon();
  Polygon(std::string *s);
  Polygon(const Polygon& orig);
  virtual ~Polygon();

  std::list<std::string>* getPosibilities();
  
  void draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color);
private:
  void init();

};

#endif	/* POLYGON_H */

