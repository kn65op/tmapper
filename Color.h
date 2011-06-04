/* 
 * File:   Color.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:00
 */

#ifndef COLOR_H
#define	COLOR_H

#include <string>

#include "node.h"

class Color : public node
{
public:
  Color();
  Color(std::string *s);
  Color(const Color& orig);
  virtual ~Color();
private:
  void init();
};

#endif	/* COLOR_H */

