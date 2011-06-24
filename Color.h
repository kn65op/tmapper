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
  Color(std::string s);
  Color(const Color& orig);
  virtual ~Color();
  
  void setText(std::string t);
  std::string getText();

  double* getColor();

private:
  void init();

  double color[4];
  bool color_ok;
};

#endif	/* COLOR_H */

