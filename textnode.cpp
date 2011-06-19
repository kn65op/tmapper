/* 
 * File:   textnode.cpp
 * Author: tomko
 * 
 * Created on 3 czerwiec 2011, 17:31
 */

#include "textnode.h"

#include <string>
#include <fstream>

using namespace std;

textnode::textnode()
{
  init();
}

textnode::textnode(std::string* t)
{
  init();
  Text = *t;
  delete t;
}

textnode::textnode(const textnode& orig)
{
  init();
}

textnode::~textnode()
{
}

void textnode::init()
{
  name = "Text";
}

void textnode::saveToFile(std::string file, int level)
{
  std::ofstream of(file.c_str(), std::ios::app);
  of << Text;
  of.close();
}