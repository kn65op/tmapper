/* 
 * File:   boolnode.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:07
 */

#include "boolnode.h"

#include <cstdlib>
#include <string>

using namespace std;

boolnode::boolnode()
{
  init();
}

boolnode::boolnode(std::string * b)
{
  val = (bool)atoi(b->c_str());
  delete b;
  init();
}

boolnode::boolnode(const boolnode& orig)
{
}

boolnode::~boolnode()
{
}

void boolnode::init()
{
  name = "Bool";
}