/* 
 * File:   LineStyle.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 20:55
 */

#ifndef LINESTYLE_H
#define	LINESTYLE_H

#include <string>

#include "node.h"

class LineStyle : public node
{
public:
  LineStyle();
  LineStyle(std::string *s);
  LineStyle(const LineStyle& orig);
  virtual ~LineStyle();

  double getWidth() const;

private:
  void init();

  double width;
  bool width_ok;
};

#endif	/* LINESTYLE_H */

