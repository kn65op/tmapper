/* 
 * File:   Placemark.h
 * Author: tomko
 *
 * Created on 3 czerwiec 2011, 16:29
 */

#ifndef PLACEMARK_H
#define	PLACEMARK_H

#include "node.h"

#include <string>

class Placemark: public node
{
public:
  Placemark();
  Placemark(std::string *s);
  Placemark(const Placemark& orig);
  virtual ~Placemark();
private:
  void init();
};

#endif	/* PLACEMARK_H */

