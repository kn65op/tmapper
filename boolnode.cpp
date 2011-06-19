/* 
 * File:   boolnode.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 22:07
 */

#include "boolnode.h"

#include "node.h"

#include <cstdlib>
#include <string>
#include <fstream>

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

void boolnode::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  of << val;
  of.close();
}