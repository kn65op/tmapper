/* 
 * File:   OuterBoundaryIs.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:34
 */

#include "OuterBoundaryIs.h"

#include <string>

#include "node.h"
#include "LinearRing.h"

using namespace std;

OuterBoundaryIs::OuterBoundaryIs()
{
  init();
  AddChild(new LinearRing());
}

OuterBoundaryIs::OuterBoundaryIs(std::string* s) : node(s)
{
  init();
}

OuterBoundaryIs::OuterBoundaryIs(const OuterBoundaryIs& orig)
{
}

OuterBoundaryIs::~OuterBoundaryIs()
{
}

void OuterBoundaryIs::init()
{
  name = "outerBoundaryIs";
}

bool OuterBoundaryIs::ifShow()
{
  return false;
}