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
#include <fstream>

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
  double *tmp = new double[3];
  if (x->find(".") != std::string::npos) x->replace(x->find("."), 1, ",");
  if (y->find(".") != std::string::npos) y->replace(y->find("."), 1, ",");
  if (z->find(".") != std::string::npos) z->replace(z->find("."), 1, ",");
  tmp[0] = atof(x->c_str());
  tmp[1] = atof(y->c_str());
  tmp[2] = atof(z->c_str());
  coordinates.push_back(tmp);
  delete x;
  delete y;
  delete z;
}

void Coordinates::init()
{
  name = "coordinates";
}

void Coordinates::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  vector<double*>::iterator it, end;
  end = coordinates.end();
  for (it = coordinates.begin(); it != end; it++)
  {
    std::cout << "?\n";
    of << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << "\n";
  }
  of.close();
}

void Coordinates::findHW(double& max_x, double& min_x, double& max_y, double& min_y)
{
  vector<double*>::iterator it, end;
  end = coordinates.end();
  for (it = coordinates.begin(); it != end; it++)
  {
    if ((*it)[0] > max_x)
    {
      max_x = (*it)[0];
    }
    else if ((*it)[0] < min_x)
    {
      min_x = (*it)[0];
    }
    if ((*it)[1] > max_y)
    {
      max_y = (*it)[1];
    }
    else if ((*it)[1] < min_y)
    {
      min_y = (*it)[1];
    }
  }
}

int Coordinates::getSize() const
{
  return coordinates.size();
}