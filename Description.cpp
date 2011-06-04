/* 
 * File:   Description.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:20
 */

#include "Description.h"

#include <string>

using namespace std;

Description::Description()
{
  init();
}

Description::Description(std::string* s) : node(s)
{
  init();
}

Description::Description(const Description& orig)
{
}

Description::~Description()
{
}

void Description::init()
{
  name = "Description";
}