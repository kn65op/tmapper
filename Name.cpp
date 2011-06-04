/* 
 * File:   Name.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:06
 */

#include "Name.h"

#include <string>
using namespace std;

Name::Name()
{
  init();
}

Name::Name(std::string *s) : node(s)
{
  init();
}

Name::Name(const Name& orig)
{
}

Name::~Name()
{
}

void Name::init()
{
  name = "Name";
}