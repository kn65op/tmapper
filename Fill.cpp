/* 
 * File:   Fill.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:30
 */

#include "Fill.h"

using namespace std;

#include <string>

#include "node.h"
#include "boolnode.h"

Fill::Fill()
{
  init();
}

Fill::Fill(std::string *s) : node(s)
{
  init();
}

Fill::Fill(const Fill& orig)
{
}

Fill::~Fill()
{
}

void Fill::init()
{
  name = "fill";
}

bool Fill::getFill()
{
  return dynamic_cast<boolnode*>(children.front())->getVal();
}