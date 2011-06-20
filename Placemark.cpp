/* 
 * File:   Placemark.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 16:29
 */

#include "Placemark.h"

using namespace std;

Placemark::Placemark()
{
  init();
}

Placemark::Placemark(std::string* s) :node(s)
{
  init();
}

Placemark::Placemark(const Placemark& orig)
{
}

Placemark::~Placemark()
{
}

void Placemark::init()
{
  name = "Placemark";
  labelstyle = 0;
  polystyle = 0;
  iconstyle = 0;
  linestyle = 0;
}