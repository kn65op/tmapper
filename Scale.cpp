/* 
 * File:   Scale.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:05
 */

#include "Scale.h"

using namespace std;

#include <string>

#include "node.h"

Scale::Scale()
{
  init();
}

Scale::Scale(std::string *s) : node(s)
{
  init();
}

Scale::Scale(const Scale& orig)
{
}

Scale::~Scale()
{
}

void Scale::init()
{
  name = "Scale";
}
