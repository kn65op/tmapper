/* 
 * File:   Heading.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 21:06
 */

#ifndef HEADING_H
#define	HEADING_H

#include <string>

#include "node.h"

class Heading : public node
{
public:
  Heading();
  Heading(std::string *s);
  Heading(const Heading& orig);
  virtual ~Heading();
private:
  void init();
};

#endif	/* HEADING_H */

