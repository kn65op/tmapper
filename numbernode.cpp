/* 
 * File:   numbernode.cpp
 * Author: tomko
 * 
 * Created on 4 czerwiec 2011, 21:03
 */

#include "numbernode.h"

using namespace std;

#include <cstdlib>
#include <string>
#include <fstream>

#include "node.h"

numbernode::numbernode()
{
  init();
}

numbernode::numbernode(std::string *s)
{
  val = atof(s->c_str());
  delete s;
  init();
}

numbernode::numbernode(const numbernode& orig)
{
}

numbernode::~numbernode()
{
}

void numbernode::init()
{
  name = "numbernode";
}

void numbernode::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  of << val;
  of.close();
}