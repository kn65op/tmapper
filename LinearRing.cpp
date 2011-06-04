/* 
 * File:   LinearRing.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 00:21
 */

#include "LinearRing.h"

#include "node.h"

using namespace std;

LinearRing::LinearRing()
{
  init();
}

LinearRing::LinearRing(std::string* s) : node(s)
{
  init();
}

LinearRing::LinearRing(const LinearRing& orig)
{
}

LinearRing::~LinearRing()
{
}

void LinearRing::init()
{
  name = "LinearRing";
}