/* 
 * File:   Coordinates.h
 * Author: tomko
 *
 * Created on 4 czerwiec 2011, 19:32
 */

#ifndef COORDINATES_H
#define	COORDINATES_H

#include <string>
#include <vector>

#include "node.h"

class Coordinates : public node
{
public:
  Coordinates();
  Coordinates(std::string *s);
  Coordinates(const Coordinates& orig);
  virtual ~Coordinates();

  void addCoordinate(std::string *x, std::string *y, std::string *z);
private:
  std::vector<int*> coordinates;

  void init();
};

#endif	/* COORDINATES_H */

