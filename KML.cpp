/* 
 * File:   KML.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 14:14
 */

#include "KML.h"

#include <string>

using namespace std;

KML::KML()
{
  init();
}

KML::KML(std::string *s) : node(s)
{
  init();
}

KML::KML(const KML& orig)
{
}

KML::~KML()
{
}

void KML::init()
{
  name = "KML";
}