/* 
 * File:   LabelStyle.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 20:52
 */

#include "LabelStyle.h"

using namespace std;

#include <string>

#include "node.h"

LabelStyle::LabelStyle()
{
  init();
}

LabelStyle::LabelStyle(std::string *s) : node(s)
{
  init();
}

LabelStyle::LabelStyle(const LabelStyle& orig)
{
}

LabelStyle::~LabelStyle()
{
}

void LabelStyle::init()
{
  name = "LabelStyle";
}
