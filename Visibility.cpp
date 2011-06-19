/* 
 * File:   Visibility.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:04
 */

#include "Visibility.h"

#include "node.h"

#include <string>

using namespace std;

Visibility::Visibility()
{
  init();
}

Visibility::Visibility(std::string* s) : node(s)
{
  init();
}

Visibility::Visibility(const Visibility& orig)
{
}

Visibility::~Visibility()
{
}

void Visibility::init()
{
  name = "visibility";
}