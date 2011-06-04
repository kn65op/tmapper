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
private:
  void init();

};

#endif	/* LINESTRING_H */

