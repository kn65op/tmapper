/* 
 * File:   LinearRing.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 00:21
 */

#ifndef LINEARRING_H
#define	LINEARRING_H

#include <string>

#include "node.h"

class LinearRing : public node
{
public:
  LinearRing();
  LinearRing(std::string *s);
  LinearRing(const LinearRing& orig);
  virtual ~LinearRing();

  void draw(cairo_t* cr, double a_x, double b_x, double a_y, double b_y, double *color);
private:
  void init();
};

#endif	/* LINEARRING_H */

