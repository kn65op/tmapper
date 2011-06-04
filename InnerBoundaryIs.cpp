/* 
 * File:   InnerBoundaryIs.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:36
 */

#include "InnerBoundaryIs.h"

#include <string>

#include "node.h"

using namespace std;

InnerBoundaryIs::InnerBoundaryIs()
{
  init();
}

InnerBoundaryIs::InnerBoundaryIs(std::string* s) : node(s)
{
  init();
}

InnerBoundaryIs::InnerBoundaryIs(const InnerBoundaryIs& orig)
{
}

InnerBoundaryIs::~InnerBoundaryIs()
{
}

void InnerBoundaryIs::init()
{
  name = "InnerBoundaryIs";
}