/* 
 * File:   Coordinates.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 19:32
 */

#include "Coordinates.h"

using namespace std;

#include <cstdlib>
#include <string>
#include <vector>

#include "node.h"

Coordinates::Coordinates()
{
  init();
}

Coordinates::Coordinates(std::string* s) : node(s)
{
  init();
}

Coordinates::Coordinates(const Coordinates& orig)
{
}

Coordinates::~Coordinates()
{
}

void Coordinates::addCoordinate(std::string* x, std::string* y, std::string* z)
{
  int *tmp = new int[3];
  tmp[0] = atoi(x->c_str());
  tmp[1] = atoi(y->c_str());
  tmp[2] = atoi(z->c_str());
  coordinates.push_back(tmp);
  delete x;
  delete y;
  delete z;
}

void Coordinates::init()
{
  name = "coordinates";
}