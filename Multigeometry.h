/* 
 * File:   Multigeometry.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 03:03
 */

#ifndef MULTIGEOMETRY_H
#define	MULTIGEOMETRY_H

#include <string>
#include <list>

#include "node.h"

class Multigeometry : public node
{
public:
  Multigeometry();
  Multigeometry(std::string *s);
  Multigeometry(const Multigeometry& orig);
  virtual ~Multigeometry();
  
  std::list<std::string>* getPosibilities();
  
private:
  void init();
};

#endif	/* MULTIGEOMETRY_H */

